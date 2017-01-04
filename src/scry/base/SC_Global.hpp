/*!
 * \file
 * \author David Saxon
 * \brief Global objects for Scry.
 */
#ifndef RIPTIDE_SCRY_BASE_GLOBAL_HPP_
#define RIPTIDE_SCRY_BASE_GLOBAL_HPP_

#include <memory>

#include "common/util/MetaUtil.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

namespace arccol
{

class Accessor;

} // namespace arccol

namespace scry
{
/*!
 * \brief Contains the global objects for Scry.
 */
namespace global
{

/*!
 * \brief Common MetaEngine Documents and Variants for Scry.
 */
namespace meta
{

/*!
 * \brief The path to the Scry metadata directory.
 */
extern const arc::io::sys::Path META_SCRY_DIR;

/*!
 * \brief The MetaEngine Document for the directories where common Riptide
 *        resources are found.
 */
extern rip::util::meta::DocumentPtr common_resource_locations;

/*!
 * \brief The MetaEngine Document for the directories where scry resources are
 *        found.
 */
extern rip::util::meta::DocumentPtr resource_locations;

} // namespace meta

/*!
 * \brief Access to Scry's resources.
 */
namespace res
{

/*!
 * \brief Access to the common Riptide resources through ArcaneCollate.
 */
extern std::unique_ptr<arccol::Accessor> common_accessor;

/*!
 * \brief Access to Scry's resources through ArcaneCollate.
 */
extern std::unique_ptr<arccol::Accessor> accessor;

} // namespace res

} // namespace global
} // namespace scry

#endif
