/*!
 * \file
 * \author David Saxon
 */
#ifndef RIPTIDE_SCRY_GUI_STARTUP_SPLASHSCREEN_HPP_
#define RIPTIDE_SCRY_GUI_STARTUP_SPLASHSCREEN_HPP_

#include <QtWidgets/QWidget>

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class QHBoxLayout;

namespace scry
{
namespace gui
{

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

namespace logging
{
    class LabelLogger;
} // namespace logging

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

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~SplashScreen();

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The logger writing to this splash screen.
     */
    scry::gui::logging::LabelLogger* m_logger;

    /*!
     * \brief The layout of the title components of the splash screen.
     */
    QHBoxLayout* m_title_layout;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Performs initialisation of the splash screen.
     */
    void init();

    /*!
     * \brief Initialises the title section of the splash screen.
     */
    void init_title();

    /*!
     * \brief Initialises the arcane arts logo on the splash screen.
     */
    void init_arcane_arts();

    /*!
     * \brief Initialises the logger components of the title.
     */
    void init_logging();
};

} // namespace startup
} // namespace gui
} // namespace scry

#endif
