# use automoc
set(CMAKE_AUTOMOC ON)

# source files for the Riptide client
set(SCRY_SRC
    ../Client.cpp
    ../Main.cpp
    ../common/SC_Boot.cpp
    ../common/SC_Global.cpp
    ../common/SC_Logging.cpp
    ../gui/GUI_Global.cpp
    ../gui/GUI_Boot.cpp
    ../util/MetaUtil.cpp
)

# build the riptide client executable
add_executable(riptide_client ${SCRY_SRC})

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
