/*!
 * \file
 * \author David Saxon
 * \brief Pattern matching algorithms which only use historical data.
 */
#ifndef RIPTIDE_SOVEREIGN_PROTOTYPING_PATTERNS_HISTORICALPATTERNMATCHING_HPP_
#define RIPTIDE_SOVEREIGN_PROTOTYPING_PATTERNS_HISTORICALPATTERNMATCHING_HPP_

#include <vector>

#include <arcanecore/base/Types.hpp>

namespace svrn
{
namespace proto
{

// TODO: how to handle types - all types could be broken down into byte fields?
/*!
 * \brief TODO:
 *
 * TODO
 */
void historical_single_pattern_match(
        const std::vector<arc::uint32>& source,
        std::size_t result_size,
        std::vector<arc::uint32>& result);

} // namespace proto
} // namespace svrn

#endif
