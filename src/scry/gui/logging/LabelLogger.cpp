#include "scry/gui/logging/LabelLogger.hpp"

namespace scry
{
namespace gui
{
namespace logging
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

LabelLogger::LabelLogger(QLabel* label, arclog::Verbosity verbosity_level)
    : arclog::AbstractOutput(verbosity_level)
    , m_label               (label)
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void LabelLogger::write(
        arclog::Verbosity verbosity,
        const arclog::Profile& profile,
        const arc::str::UTF8String& message)
{
    // should writing be skipped?
    if(!m_enabled || verbosity > m_verbosity_level)
    {
        return;
    }

    if(m_label != nullptr)
    {
        m_label->setText(QString(message.get_raw()));
    }
}

} // namespace logging
} // namespace gui
} // namespace scry
