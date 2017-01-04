#include "scry/base/SC_Global.hpp"

#include <arcanecollate/Accessor.hpp>

namespace scry
{
namespace global
{

namespace meta
{

const arc::io::sys::Path META_SCRY_DIR(
    {arc::str::UTF8String("meta"), arc::str::UTF8String("scry")});
rip::util::meta::DocumentPtr resource_locations;

} // namespace meta

namespace res
{

std::unique_ptr<arccol::Accessor> accessor;

} // namespace res

} // namespace global
} // namespace scry
