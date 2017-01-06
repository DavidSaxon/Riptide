/*!
 * \file
 * \author David Saxon
 * \brief Utilities for accessing data.
 */
#ifndef RIPTIDE_SCRY_UTIL_DATA_HPP_
#define RIPTIDE_SCRY_UTIL_DATA_HPP_

#include <arcanecore/io/sys/FileReader.hpp>

#include <arcanecollate/Accessor.hpp>

#include <QtCore/QByteArray>

namespace scry
{
namespace util
{
/*!
 * \brief Utilities relating to accessing data.
 */
namespace data
{

/*!
 * \brief TODO:
 *
 * TODO:
 */
QByteArray access_as_qbytearray(
        const arc::io::sys::Path& resource,
        const arccol::Accessor* accessor,
        arc::io::sys::FileHandle::Encoding encoding =
            arc::io::sys::FileHandle::ENCODING_DETECT,
        arc::io::sys::FileHandle::Newline newline =
            arc::io::sys::FileHandle::NEWLINE_UNIX);

} // namespace data
} // namespace util
} // namespace scry

#endif
