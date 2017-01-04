#include "scry/Client.hpp"

#include "scry/common/SC_Boot.hpp"
#include "scry/common/SC_Logging.hpp"

namespace scry
{

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Client::~Client()
{
}

//------------------------------------------------------------------------------
//                            PUBLIC STATIC FUNCTIONS
//------------------------------------------------------------------------------

Client* Client::get_instance()
{
    static Client instance;
    return &instance;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

int Client::execute()
{

    // initialise
    if(!scry::boot::initialisation_routine())
    {
        scry::logging::get_critical_stream()
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
    if(!scry::boot::shutdown_routine())
    {
        scry::logging::get_critical_stream()
            << "Shutdown failed. Aborting early." << std::endl;
        return -1;
    }

    // TODO:
    return 0;
}

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Client::Client()
{
}

} // namespace scry
