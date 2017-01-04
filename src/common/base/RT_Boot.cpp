#include "common/base/RT_Boot.hpp"

#include <metaengine/visitors/Shorthand.hpp>

#include <arcanecollate/Accessor.hpp>

#include "common/base/RT_Global.hpp"
#include "common/base/RT_MetaCompiled.hpp"

namespace rip
{
/*!
 * \brief Boot up and boot down routines for Riptide commons.
 */
namespace boot
{

//------------------------------------------------------------------------------
//                                    GLOBALS
//------------------------------------------------------------------------------

namespace
{

/*!
 * \brief Whether Riptide commons have been initialised yet or not.
 */
static bool g_initialised = false;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

/*!
 * \brief Performs initialisation of MetaEngine data for the Riptide commons.
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
    // skip initialisiation if it's been done before
    if(g_initialised)
    {
        return true;
    }

    meta_initialisation_subroutine();
    resource_access_initialisation_subroutine();

    g_initialised = true;
    return true;
}

bool shutdown_routine()
{
    // abort if Riptide commons haven't been initialised
    if(!g_initialised)
    {
        return false;
    }

    g_initialised = false;
    return true;
}

void meta_initialisation_subroutine()
{
    // build the path to the commons metadata directory
    arc::io::sys::Path common_meta_path(rip::global::meta::META_COMMON_DIR);
    // build the path to the common resources metadata directory
    arc::io::sys::Path resources_meta_path(common_meta_path);
    resources_meta_path << "resources";

    //----------------------------RESOURCE LOCATIONS----------------------------
    // build the path the resource locations metadata
    arc::io::sys::Path locations_meta_path(resources_meta_path);
    locations_meta_path << "locations.json";
    // built-in memory data
    static const arc::str::UTF8String locations_compiled(
        RIP_METACOMPILED_RESOURCES_LOCATIONS);
    // construct the document
    rip::global::meta::resource_locations.reset(new metaengine::Document(
        locations_meta_path,
        &locations_compiled
    ));
}

void resource_access_initialisation_subroutine()
{
    // get the path to the resources table of contents
    arc::io::sys::Path toc_path(
        *rip::global::meta::resource_locations->get("resources_toc", ME_PATHV)
    );

    // instantiate the accessor
    rip::global::res::accessor.reset(new arccol::Accessor(toc_path));

    // should resource from collated sources be used
    bool use_collated =
        *rip::global::meta::resource_locations->get("use_collated", ME_BOOLV);
    arccol::Accessor::force_real_resources = !use_collated;
}

} // namespace boot
} // namespace rip
