#include "scry/util/Icon.hpp"

#include <metaengine/visitors/Shorthand.hpp>

#include <core/base/RT_Global.hpp>

#include "scry/gui/GUI_Global.hpp"
#include "scry/util/Data.hpp"

namespace scry
{
namespace util
{
namespace icon
{

QIcon get_application_icon()
{
    // get the icon as a pixmap
    QPixmap pixmap;
    pixmap.loadFromData(
        scry::util::data::access_as_qbytearray(
            *scry::gui::global::meta::icons->get(
                "app",
                metaengine::PathV::instance(
                    rip::global::meta::resource_locations.get()
                )
            ),
            rip::global::res::accessor.get()
        )
    );

    return QIcon(pixmap);
}

} // namespace icon
} // namespace util
} // namespace scry
