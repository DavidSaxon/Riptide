# use automoc
set(CMAKE_AUTOMOC ON)

# source files for the Riptide client
set(RIPTIDE_CLIENT_SRC
    ../CL_Global.cpp
    ../CL_Main.cpp
    ../CL_Startup.cpp
    ../Logging.cpp
    ../RiptideClient.cpp
    ../gui/GUI_Global.cpp
    ../gui/GUI_Startup.cpp
    ../util/MetaUtil.cpp
)

# build the riptide client executable
add_executable(riptide_client ${RIPTIDE_CLIENT_SRC})

# link libraries to the riptide client
target_link_libraries(riptide_client
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    arcanecollate_lib
    metaengine
    arcanelog_shared
    arcanelog
    arcanecore_io
    arcanecore_base
    sovereign
)
