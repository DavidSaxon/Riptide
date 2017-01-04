#include "scry/Client.hpp"

#include <QtWidgets/QApplication>

#include "scry/base/SC_Boot.hpp"
#include "scry/base/SC_Logging.hpp"
#include "scry/gui/startup/SplashScreen.hpp"

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
    // instantiate the Qt application
    int argc = 0;
    QApplication app(argc, nullptr);

    // initialise
    if(!scry::boot::initialisation_routine())
    {
        scry::logging::get_critical_stream()
            << "Initialisation failed. Aborting." << std::endl;
        return -1;
    }

    // create the instance of the splash screen
    scry::gui::startup::SplashScreen* splash =
        new scry::gui::startup::SplashScreen();
    splash->show();

    // TODO: assign startup routines

    // begin execution of the Qt application, we will only regain control on
    // exit
    QApplication::exec();

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
