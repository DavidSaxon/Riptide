/*!
 * \file
 * \author David Saxon
 * \brief Utilities for MetaEngine.
 */
#ifndef RIPTIDE_SCRY_UTIL_METAUTIL_HPP_
#define RIPTIDE_SCRY_UTIL_METAUTIL_HPP_

#include <memory>

#include <arcanecore/io/sys/Path.hpp>

#include <json/json.h>

#include <metaengine/Document.hpp>
#include <metaengine/Variant.hpp>

namespace scry
{
namespace util
{
/*!
 * \brief Utilities for MetaEngine.
 */
namespace  meta
{

//------------------------------------------------------------------------------
//                                TYPE DEFINITIONS
//------------------------------------------------------------------------------

typedef std::unique_ptr<metaengine::Document> DocumentPtr;
typedef std::unique_ptr<metaengine::Variant> VariantPtr;

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

/*!
 * \brief The path to the Riptide metadata directory.
 */
extern const arc::io::sys::Path META_DIR;
/*!
 * \brief The path to the Scry metadata directory.
 */
extern const arc::io::sys::Path META_SCRY_DIR;

} // namespace meta
} // namespace util
} // namespace scry

#endif
