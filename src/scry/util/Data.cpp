#include "scry/util/Data.hpp"

#include <arcanecollate/Reader.hpp>

namespace scry
{
namespace util
{
namespace data
{

QByteArray access_as_qbytearray(
        const arc::io::sys::Path& resource,
        const arccol::Accessor* accessor,
        arc::io::sys::FileHandle::Encoding encoding,
        arc::io::sys::FileHandle::Newline newline)
{
    // get the raw data through the accessor
    char* raw_data = nullptr;
    const arc::int64 data_size =
        arccol::Reader::get_bytes(resource, accessor, &raw_data);

    // build the byte array
    QByteArray byte_array(raw_data, data_size);

    // delete raw data
    delete[] raw_data;

    // return
    return byte_array;
}

} // namespace data
} // namespace util
} // namespace scry
