#include "core/base/RT_Global.hpp"

#include <arcanecollate/Accessor.hpp>

namespace rip
{
namespace global
{

namespace meta
{

const arc::io::sys::Path META_DIR({arc::str::UTF8String("meta")});
const arc::io::sys::Path META_CORE_DIR(
    {arc::str::UTF8String("meta"), arc::str::UTF8String("core")});
util::meta::DocumentPtr resource_locations;

} // namespace meta

namespace res
{

std::unique_ptr<arccol::Accessor> accessor;

} // namespace res

} // namespace global
} // namespace rip
