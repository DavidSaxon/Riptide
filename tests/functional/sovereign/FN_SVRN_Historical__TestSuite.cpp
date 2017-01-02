#include <arcanecore/test/ArcTest.hpp>

ARC_TEST_MODULE(functional.sovereign.historical)

#include <riptide/sovereign/prototyping/patterns/HistoricalPatternMatching.hpp>

namespace
{

//------------------------------------------------------------------------------
//                                     SIMPLE
//------------------------------------------------------------------------------

class SimpleFixture : public arc::test::Fixture
{
public:

    //----------------------------PUBLIC ATTRIBUTES-----------------------------

    std::vector<std::vector<arc::uint32>> patterns;
    std::vector<std::vector<arc::uint32>> next;

    //-------------------------PUBLIC MEMBER FUNCTIONS--------------------------

    virtual void setup()
    {
        // generate some patterns
        patterns.push_back({0, 1, 0, 1, 0, 1, 0, 1, 0, 1});
        next.push_back({0, 1, 0, 1});
    }
};

ARC_TEST_UNIT_FIXTURE(simple, SimpleFixture)
{
    // iterate over the patterns
    for(std::size_t i = 0; i < fixture->patterns.size(); ++i)
    {
        std::vector<arc::uint32> result;

        rip::svrn::proto::historical_single_pattern_match(
            fixture->patterns[i],
            fixture->next[i].size(),
            result
        );

        ARC_CHECK_ITER_EQUAL(result, fixture->next[i]);
    }
}

} // namespace anonymous
