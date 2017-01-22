/*!
 * \file
 * \author David Saxon
 * \brief Global objects for Riptide.
 */
#ifndef RIPTIDE_CORE_BASE_GLOBAL_HPP_
#define RIPTIDE_CORE_BASE_GLOBAL_HPP_

#include <memory>

#include "core/util/MetaUtil.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

namespace arccol
{

class Accessor;

} // namespace arccol

namespace rip
{
/*!
 * \brief Contains the global objects for Riptide.
 */
namespace global
{

/*!
 * \brief Common MetaEngine Documents and Variants for Riptide.
 */
namespace meta
{

/*!
 * \brief The path to the Riptide metadata directory.
 */
extern const arc::io::sys::Path META_DIR;

/*!
 * \brief The path to the Riptide core metadata directory.
 */
extern const arc::io::sys::Path META_CORE_DIR;

/*!
 * \brief The MetaEngine Document for the directories where Riptide resources
 *        are found.
 */
extern util::meta::DocumentPtr resource_locations;

} // namespace meta

/*!
 * \brief Access to Riptide's resources.
 */
namespace res
{

/*!
 * \brief Access to Riptide's resources through ArcaneCollate.
 */
extern std::unique_ptr<arccol::Accessor> accessor;

} // namespace res

} // namespace global
} // namespace rip

#endif
