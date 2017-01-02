#include "client/RiptideClient.hpp"

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
    run_initialisation_routines();
    // start splash screen
    // TODO:
    // boot
    // TODO:
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
    // TODO: warn if initialisation has been done before

    // initialisation successful
    m_initialised = true;
    return true;
}

} // namespace rip_c
