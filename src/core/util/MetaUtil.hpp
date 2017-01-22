/*!
 * \file
 * \author David Saxon
 * \brief Utilities for MetaEngine.
 */
#ifndef RIPTIDE_CORE_UTIL_METAUTIL_HPP_
#define RIPTIDE_CORE_UTIL_METAUTIL_HPP_

#include <memory>

#include <arcanecore/io/sys/Path.hpp>

#include <json/json.h>

#include <metaengine/Document.hpp>
#include <metaengine/Variant.hpp>

namespace rip
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

} // namespace meta
} // namespace util
} // namespace rip

#endif
