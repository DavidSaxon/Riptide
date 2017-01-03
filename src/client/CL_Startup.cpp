#include "client/CL_Startup.hpp"

#include <arcanecore/base/Preproc.hpp>

#include <metaengine/visitors/Shorthand.hpp>

#include <arcanecollate/Accessor.hpp>

#ifdef ARC_OS_WINDOWS
    #include <windows.h>
#endif

#include "client/CL_Global.hpp"
#include "client/CL_MetaCompiled.hpp"
#include "client/Logging.hpp"
#include "client/gui/GUI_Startup.hpp"

namespace rip_c
{
namespace startup
{

//------------------------------------------------------------------------------
//                                    GLOBALS
//------------------------------------------------------------------------------

namespace
{

/*!
 * \brief Whether Scry has been initialised yet or not.
 */
static bool g_initialised = false;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

/*!
 * \brief Performs initialisation of operating system specific functionality.
 */
void os_initialisation_subroutine();

/*!
 * \brief Performs initialisation of MetaEngine data for Scry.
 */
void meta_initialisation_subroutine();

/*!
 * \brief Performs initialisation of resource access.
 */
void resource_access_initialisation_subroutine();

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

bool initialisation_routine()
{
    // warn and do nothing if Scry has already been initialised
    if(g_initialised)
    {
        rip_c::logger->warning
            << "Attempted to run Scry initialisation routines after the client "
            << "has already successfully started. Aborting routine."
            << std::endl;
        return true;
    }

    try
    {
        rip_c::logging::initialisation_routine();
        meta_initialisation_subroutine();
        os_initialisation_subroutine();
        resource_access_initialisation_subroutine();
        rip_c::gui::initialisation_routine();
    }
    catch(const arc::ex::ArcException& exc)
    {
        rip_c::logging::get_critical_stream()
            << "Encountered exception during initialisation routines: ["
            << exc.get_type() << "] \"" << exc.get_message() << "\""
            << std::endl;
        return false;
    }
    catch(const std::exception& exc)
    {
        rip_c::logging::get_critical_stream()
            << "Encountered exception during initialisation routines: \""
            << exc.what() << "\"" << std::endl;
        return false;
    }

    rip_c::logger->debug
        << "Initialisation completed successfully" << std::endl;

    // initialisation successful
    g_initialised = true;
    return true;
}

bool shutdown_routine()
{
    // warn and do nothing if Scry has not been initialised
    if(!g_initialised)
    {
        rip_c::logger->warning
            << "Attempted to run Scry shutdown routines before the client has "
            << "been initialised. Aborting routine." << std::endl;
        return false;
    }

    rip_c::logger->info << "Executing shutdown routines" << std::endl;

    try
    {
        rip_c::gui::shutdown_routine();
    }
    catch(const arc::ex::ArcException& exc)
    {
        rip_c::logging::get_critical_stream()
            << "Encountered exception during shutdown routines: ["
            << exc.get_type() << "] \"" << exc.get_message() << "\""
            << std::endl;
        return false;
    }
    catch(const std::exception& exc)
    {
        rip_c::logging::get_critical_stream()
            << "Encountered exception during shutdown routines: \""
            << exc.what() << "\"" << std::endl;
        return false;
    }

    rip_c::logger->debug << "Shutdown completed successfully" << std::endl;

    // shutdown successful
    g_initialised = false;
    return true;
}

void os_initialisation_subroutine()
{
    rip_c::logger->debug
        << "Initialising Operating System specific functionality." << std::endl;

    #ifdef ARC_OS_WINDOWS

        // set the way in which Windows handles errors (i.e. we don't want
        // dialog boxes!)
        SetErrorMode(SEM_FAILCRITICALERRORS);

    #endif
}

void meta_initialisation_subroutine()
{
    rip_c::logger->debug << "Initialising common MetaEngine data" << std::endl;

    // build the path to the scry metadata directory
    arc::io::sys::Path scry_meta_path(util::meta::META_CLIENT_DIR);
    // build the path to the scry resources metadata directory
    arc::io::sys::Path resources_meta_path(scry_meta_path);
    resources_meta_path << "resources";

    //----------------------------RESOURCE LOCATIONS----------------------------
    // build the path the resource locations metadata
    arc::io::sys::Path locations_meta_path(resources_meta_path);
    locations_meta_path << "locations.json";
    // built-in memory data
    static const arc::str::UTF8String locations_compiled(
        RIP_C_METACOMPILED_RESOURCES_LOCATIONS);
    // construct the document
    rip_c::global::meta::resource_locations.reset(new metaengine::Document(
        locations_meta_path,
        &locations_compiled
    ));
}

void resource_access_initialisation_subroutine()
{
    rip_c::logger->debug << "Initialising resource access" << std::endl;

    // get the path to the resources table of contents
    arc::io::sys::Path toc_path(
        *rip_c::global::meta::resource_locations->get("resources_toc", ME_PATHV)
    );

    // instantiate the accessor
    rip_c::global::res::accessor.reset(new arccol::Accessor(toc_path));

    // should resource from collated sources be used
    bool use_collated =
        *rip_c::global::meta::resource_locations->get("use_collated", ME_BOOLV);
    arccol::Accessor::force_real_resources = !use_collated;
    if(!use_collated)
    {
        rip_c::logger->notice
            << "Using resources from non-collated sources" << std::endl;
    }
}

} // namespace startup
} // namespace rip_c
