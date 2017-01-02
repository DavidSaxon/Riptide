# source files for sovereign
set(SOVEREIGN_SRC
    ../prototyping/patterns/HistoricalPatternMatching.cpp
)

# build the sovereign library
add_library(sovereign STATIC ${SOVEREIGN_SRC})
