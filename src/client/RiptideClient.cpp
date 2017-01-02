#include "client/RiptideClient.hpp"

#include "client/Logging.hpp"

#ifdef ARC_OS_WINDOWS
    #include <windows.h>
#endif

namespace rip_c
{

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

RiptideClient::~RiptideClient()
{
}

//------------------------------------------------------------------------------
//                            PUBLIC STATIC FUNCTIONS
//------------------------------------------------------------------------------

RiptideClient* RiptideClient::get_instance()
{
    static RiptideClient instance;
    return &instance;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

int RiptideClient::execute()
{

    // initialise
    if(!run_initialisation_routines())
    {
        rip_c::logging::get_critical_stream()
            << "Initialisation failed. Aborting." << std::endl;
        return -1;
    }
    // start splash screen
    // TODO:
    // boot
    // TODO: this should be assigned to the splash screen somehow
    // run
    // TODO:
    // shutdown
    // TODO:

    // TODO:
    return 0;
}

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

RiptideClient::RiptideClient()
    : m_initialised(false)
{
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool RiptideClient::run_initialisation_routines()
{
    // warn and do nothing if the Riptide Client has already been initialised
    if(m_initialised)
    {
        rip_c::logger->warning
            << "Attempted to run Riptide Client initialisation routines after "
            << "the client has already successfully started. Aborting routine."
            << std::endl;
        return true;
    }

    try
    {
        rip_c::logging::initialisation_routine();
        os_initialisation_subroutine();
        // TODO: gui initialisation routine
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
    m_initialised = true;
    return true;
}

void RiptideClient::os_initialisation_subroutine()
{
    rip_c::logger->debug
        << "Initialising Operating System specific functionality." << std::endl;

    #ifdef ARC_OS_WINDOWS

        // set the way in which Windows handles errors (i.e. we don't want
        // dialog boxes!)
        SetErrorMode(SEM_FAILCRITICALERRORS);

    #endif
}

} // namespace rip_c
