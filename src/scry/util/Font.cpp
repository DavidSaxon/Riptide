#include "scry/util/Font.hpp"

#include <QtGui/QFontDatabase>

#include "scry/base/SC_Logging.hpp"

namespace scry
{
namespace util
{
namespace font
{

bool is_font_available(const arc::str::UTF8String& font_family)
{
    QString q_font_family(font_family.get_raw());

    QFontDatabase font_db;
    QStringList families = font_db.families();
    for(const QString& family : families)
    {
        if(q_font_family == family)
        {
            return true;
        }
    }

    return false;
}

void print_available_fonts()
{
    scry::logger->notice << "Available fonts:" << std::endl;

    QFontDatabase font_db;
    QStringList families = font_db.families();
    for(const QString& family : families)
    {
        scry::logger->notice << family.toStdString() << std::endl;
    }
}

} // namespace font
} // namespace util
} // namespace scry
