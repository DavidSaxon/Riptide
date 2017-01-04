#include "scry/gui/startup/SplashScreen.hpp"

#include <metaengine/visitors/Shorthand.hpp>

#include <QtCore/QSize>
#include <QtCore/Qt>
#include <QtGui/QFont>
#include <QtGui/QPixmap>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSizePolicy>
#include <QtWidgets/QVBoxLayout>

#include <meta_qt/core/Geometry.hpp>
#include <meta_qt/core/Qt.hpp>
#include <meta_qt/gui/Font.hpp>

#include <common/base/RT_Global.hpp>

#include "scry/gui/GUI_Global.hpp"

namespace scry
{
namespace gui
{
namespace startup
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

SplashScreen::SplashScreen()
    : QWidget()
{
    // window flags
    setWindowFlags(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.window_flags", MQT_WINFLGV
    ));
    // size
    resize(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.size", MQT_WGTSZV(this)
    ));
    // position
    move(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.position", MQT_WGTPOSV(this)
    ));
    // style sheet
    setStyleSheet((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.style_sheet", ME_U8STRV
    )).get_raw());

    // TODO: meta engine???
    // set up layouts
    QVBoxLayout* main_layout = new QVBoxLayout();
    QHBoxLayout* title_layout = new QHBoxLayout();
    title_layout->setSpacing(34);
    title_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->addLayout(title_layout);

    // create a the logo
    QLabel* logo = new QLabel(this);
    // TODO: use arcane collate
    QPixmap logo_pix((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.logo.image",
        metaengine::PathV::instance(rip::global::meta::resource_locations.get())
    )).to_native().get_raw());
    // logo size
    logo->setPixmap(logo_pix.scaled(
        *scry::gui::global::meta::widgets_startup->get(
            "splash_screen.logo.size", MQT_WGTSZV(logo)
        )
    ));
    // add to the splash screen
    logo->setStyleSheet("background: rgba(0, 0, 0, 0);");
    logo->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    title_layout->addWidget(logo);

    // create the title
    QLabel* title = new QLabel((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.title.text", ME_U8STRV
    )).get_raw());
    // title style sheet
    title->setStyleSheet((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.title.style_sheet", ME_U8STRV
    )).get_raw());
    title->setFont(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.title.font", MQT_FONTV
    ));
    // add to layout
    title_layout->addWidget(title);

    // TODO: don't offset title..
    // TODO: transform into logger
    QLabel* state_info = new QLabel("Bootstrapping...");
    state_info->setStyleSheet(
        "background: rgba(0, 0, 0, 0); "
        "font-family: FreeMono; color: white; font-size: 16px;"
    );
    state_info->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    main_layout->addWidget(state_info);

    setLayout(main_layout);
}

} // namespace startup
} // namespace gui
} // namespace scry
