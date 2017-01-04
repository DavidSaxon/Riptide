# source files for the meta_qt library
set(META_QT
    ../core/Geometry.cpp
    ../core/Qt.cpp

    ../gui/Font.cpp
)

# build the meta_qt library
add_library(meta_qt STATIC ${META_QT})

# link libraries to meta_qt
target_link_libraries(meta_qt
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)
