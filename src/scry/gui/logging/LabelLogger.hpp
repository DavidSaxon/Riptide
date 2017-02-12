/*!
 * \file
 * \author David Saxon
 */
#ifndef RIPTIDE_SCRY_GUI_LOGGING_LABELLOGGER_HPP_
#define RIPTIDE_SCRY_GUI_LOGGING_LABELLOGGER_HPP_

#include <arcanelog/AbstractOutput.hpp>

#include <QtWidgets/QLabel>

namespace scry
{
namespace gui
{
namespace logging
{

/*!
 * \brief An implementation of an ArcaneLog output that writes log messages to
 *        a QLabel.
 *
 * Each new log messages clears the current text of the label and changes it
 * to the new text.
 */
class LabelLogger : public arclog::AbstractOutput
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /*!
     * \brief Constructs a new Label logger.
     *
     * \param label The QLabel instance to write messages to.
     * \param verbosity_level The initial verbosity level of the logger.
     */
    LabelLogger(
            QLabel* label,
            arclog::Verbosity verbosity_level = arclog::VERBOSITY_NOTICE);

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    // override
    virtual void write(
            arclog::Verbosity verbosity,
            const arclog::Profile& profile,
            const arc::str::UTF8String& message);
private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The QLabel log messages will be written to.
     */
    QLabel* m_label;
};

} // namespace logging
} // namespace gui
} // namespace scry

#endif
