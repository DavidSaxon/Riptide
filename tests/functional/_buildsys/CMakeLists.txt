# set the include directory for this source
include_directories(
    ${INCLUDE_DIRECTORIES}
    ..
)

# source files for the functional tests
set(FUNCTIONAL_SRC
    ../FN_Main.cpp

    ../sovereign/FN_SVRN_Historical__TestSuite.cpp
)

# build the functional tests executable
add_executable(functional ${FUNCTIONAL_SRC})
# link libraries to the functional tests
target_link_libraries(functional
    arcanecore_test
    arcanecore_io
    arcanecore_base
)
