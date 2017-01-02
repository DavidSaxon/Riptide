# source files for the Riptide client
set(RIPTIDE_CLIENT_SRC
    ../CL_Main.cpp
    ../Logging.cpp
    ../RiptideClient.cpp
    ../util/MetaUtil.cpp
)

# build the riptide client executable
add_executable(riptide_client ${RIPTIDE_CLIENT_SRC})

# link libraries to the riptide client
target_link_libraries(riptide_client
    metaengine
    arcanelog_shared
    arcanelog
    arcanecore_io
    arcanecore_base
    sovereign
)
