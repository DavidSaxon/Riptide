/*!
 * \file
 * \author David Saxon
 * \brief Utilities relating to fonts.
 */
#ifndef RIPTIDE_SCRY_UTIL_FONT_HPP_
#define RIPTIDE_SCRY_UTIL_FONT_HPP_

#include <arcanecore/base/str/UTF8String.hpp>

namespace scry
{
namespace util
{
/*!
 * \brief Utilities relating to fonts.
 */
namespace font
{

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/*!
 * \brief Returns whether the given font family is available to Riptide.
 */
bool is_font_available(const arc::str::UTF8String& font_family);

/*!
 * \brief Debug function that prints each font family that is available to
 *        Riptide on a newline.
 */
void print_available_fonts();

} // namespace font
} // namespace util
} // namespace scry

#endif
