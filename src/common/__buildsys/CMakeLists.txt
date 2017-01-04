# source files for the riptide common library
set(COMMON_SRC
    ../base/RT_Boot.cpp
    ../base/RT_Global.cpp
)

# build the riptide common library
add_library(riptide_common STATIC ${COMMON_SRC})
