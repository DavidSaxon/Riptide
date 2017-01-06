# use automoc
set(CMAKE_AUTOMOC ON)

# source files for the Riptide client
set(SCRY_SRC
    ../Client.cpp
    ../Main.cpp
    ../base/SC_Boot.cpp
    ../base/SC_Global.cpp
    ../base/SC_Logging.cpp
    ../gui/GUI_Global.cpp
    ../gui/GUI_Boot.cpp
    ../gui/startup/SplashScreen.cpp
    ../util/Data.cpp
)

# build the riptide client executable
add_executable(riptide_client ${SCRY_SRC})

# link libraries to the riptide client
target_link_libraries(riptide_client
    sovereign
    riptide_common
    meta_qt
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    arcanecollate_lib
    metaengine
    arcanelog_shared
    arcanelog
    arcanecore_io
    arcanecore_base
)
