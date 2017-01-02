#include "client/util/MetaUtil.hpp"

namespace rip_c
{
namespace util
{
namespace meta
{

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

const arc::io::sys::Path META_DIR({arc::str::UTF8String("meta")});
const arc::io::sys::Path META_CLIENT_DIR(
    {arc::str::UTF8String("meta"), arc::str::UTF8String("client")});

} // namespace meta
} // namespace util
} // namespace omi_
