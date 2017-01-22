# source files for the riptide common library
set(CORE_SRC
    ../base/RT_Boot.cpp
    ../base/RT_Global.cpp
)

# build the riptide core library
add_library(riptide_core STATIC ${CORE_SRC})
