#include "client/gui/GUI_Global.hpp"

#include <QtWidgets/QApplication>

namespace rip_c
{
namespace gui
{
namespace global
{

namespace meta
{

util::meta::DocumentPtr resource_locations;
util::meta::DocumentPtr fonts;

} // namespace meta

QApplication* qt_application = nullptr;

} // namespace global
} // namespace gui
} // namespace rip_c
