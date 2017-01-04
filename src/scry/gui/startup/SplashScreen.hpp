/*!
 * \file
 * \author David Saxon
 */
#ifndef RIPTIDE_SCRY_GUI_STARTUP_SPLASHSCREEN_HPP_
#define RIPTIDE_SCRY_GUI_STARTUP_SPLASHSCREEN_HPP_

#include <QtWidgets/QWidget>

namespace scry
{
namespace gui
{
namespace startup
{

/*!
 * \brief Base widget for the splash screen that is displayed during Scry's
 *        startup procedure.
 */
class SplashScreen : public QWidget
{
    Q_OBJECT

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    SplashScreen();
};

} // namespace startup
} // namespace gui
} // namespace scry

#endif
