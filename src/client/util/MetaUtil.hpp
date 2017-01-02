/*!
 * \file
 * \author David Saxon
 * \brief Utilities for MetaEngine.
 */
#ifndef RIPTIDE_CLIENT_UTIL_METAUTIL_HPP_
#define RIPTIDE_CLIENT_UTIL_METAUTIL_HPP_

#include <memory>

#include <arcanecore/io/sys/Path.hpp>

#include <json/json.h>

#include <metaengine/Document.hpp>
#include <metaengine/Variant.hpp>

namespace rip_c
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
 * \brief The path to the Riptide client metadata directory.
 */
extern const arc::io::sys::Path META_CLIENT_DIR;

} // namespace meta
} // namespace util
} // namespace rip_c

#endif
