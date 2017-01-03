#include "client/CL_Global.hpp"

#include <arcanecollate/Accessor.hpp>

namespace rip_c
{
namespace global
{

namespace meta
{

util::meta::DocumentPtr resource_locations;

} // namespace meta

namespace res
{

std::unique_ptr<arccol::Accessor> accessor;

} // namespace res

} // namespace global
} // namespace rip_c
