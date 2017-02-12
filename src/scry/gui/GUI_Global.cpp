#include "scry/gui/GUI_Global.hpp"

namespace scry
{
namespace gui
{
namespace global
{

namespace meta
{

rip::util::meta::DocumentPtr resource_locations;
rip::util::meta::DocumentPtr fonts;
rip::util::meta::DocumentPtr icons;
rip::util::meta::DocumentPtr widgets_startup;

} // namespace meta

namespace font
{

arc::str::UTF8String title("Sans Serif");
arc::str::UTF8String console("Sans Serif");
arc::str::UTF8String arcane_arts("Sans Serif");

} // namespace font

} // namespace global
} // namespace gui
} // namespace scry
