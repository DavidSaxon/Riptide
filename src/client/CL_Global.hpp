/*!
 * \file
 * \author David Saxon
 * \brief Global objects for the Riptide Client.
 */
#ifndef RIPTIDE_CLIENT_GLOBAL_HPP_
#define RIPTIDE_CLIENT_GLOBAL_HPP_

#include <memory>

#include "client/util/MetaUtil.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

namespace arccol
{

class Accessor;

} // namespace arccol

namespace rip_c
{
/*!
 * \brief Contains the global objects for the Riptide Client.
 */
namespace global
{

/*!
 * \brief Common MetaEngine Documents and Variants for Scry.
 */
namespace meta
{

/*!
 * \brief The MetaEngine Document for the directories where scry resources are
 *        found.
 */
extern util::meta::DocumentPtr resource_locations;

} // namespace meta

/*!
 * \brief Access to the Riptide Client's resources.
 */
namespace res
{

/*!
 * \brief Access to the Riptide Client's resources through ArcaneCollate.
 */
extern std::unique_ptr<arccol::Accessor> accessor;

} // namespace res

} // namespace global
} // namespace rip_c

#endif
