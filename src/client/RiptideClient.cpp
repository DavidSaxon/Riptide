#include "client/RiptideClient.hpp"

#include "client/CL_Startup.hpp"
#include "client/Logging.hpp"

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
    if(!rip_c::startup::initialisation_routine())
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

    // TODO: this may need to be triggered elsewhere..
    // shutdown
    if(!rip_c::startup::shutdown_routine())
    {
        rip_c::logging::get_critical_stream()
            << "Shutdown failed. Aborting early." << std::endl;
        return -1;
    }

    // TODO:
    return 0;
}

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

RiptideClient::RiptideClient()
{
}

} // namespace rip_c
