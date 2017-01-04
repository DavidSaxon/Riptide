#include "scry/common/SC_Global.hpp"

#include <arcanecollate/Accessor.hpp>

namespace scry
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
} // namespace scry
