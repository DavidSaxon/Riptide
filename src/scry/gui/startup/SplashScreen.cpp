#include "scry/gui/startup/SplashScreen.hpp"

#include <arcanelog/Shared.hpp>

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

#include <core/base/RT_Global.hpp>

#include "scry/gui/GUI_Global.hpp"
#include "scry/gui/logging/LabelLogger.hpp"
#include "scry/util/Data.hpp"
#include "scry/util/Icon.hpp"

// TODO: REMOVE ME
#include "scry/base/SC_Logging.hpp"

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
    : QWidget ()
    , m_logger(nullptr)
{
    init();
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

SplashScreen::~SplashScreen()
{
    // clean up the logger
    arclog::shared_handler.remove_output(m_logger);
    delete m_logger;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void SplashScreen::init()
{
    // set the application icon
    setWindowIcon(scry::util::icon::get_application_icon());

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

    // set up layout
    m_title_layout = new QHBoxLayout();
    setLayout(m_title_layout);
    m_title_layout->setSpacing(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.title_layout.spacing", ME_INTV(arc::int32)));
    m_title_layout->setContentsMargins(0, 0, 0, 0);

    init_title();
    init_arcane_arts();
    init_logging();
}

void SplashScreen::init_title()
{
    // create a the logo
    QLabel* logo = new QLabel(this);
    QPixmap logo_pix;
    logo_pix.loadFromData(
        scry::util::data::access_as_qbytearray(
            *scry::gui::global::meta::widgets_startup->get(
                "splash_screen.logo.image",
                metaengine::PathV::instance(
                    rip::global::meta::resource_locations.get())
            ),
            rip::global::res::accessor.get()
        )
    );
    logo->setPixmap(logo_pix.scaled(
        *scry::gui::global::meta::widgets_startup->get(
            "splash_screen.logo.size", MQT_WGTSZV(logo)
        )
    ));
    logo->setStyleSheet("background: rgba(0, 0, 0, 0);");
    // add to layout
    m_title_layout->addWidget(logo);

    // create the title
    QLabel* title = new QLabel((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.title.text", ME_U8STRV
    )).get_raw());
    // title style sheet
    title->setStyleSheet((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.title.style_sheet", ME_U8STRV
    )).get_raw());
    // title font
    title->setFont(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.title.font", MQT_FONTV
    ));
    // add to layout
    m_title_layout->addWidget(title);
    // add space
    m_title_layout->addStretch();
}

void SplashScreen::init_arcane_arts()
{
    // add a widget to contain the contents of the logo
    QWidget* arcane_arts_base = new QWidget(this);
    arcane_arts_base->setStyleSheet("background: rgba(0, 0, 0, 0);");
    // logger position
    arcane_arts_base->move(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.arcane_arts.position", MQT_WGTPOSV(arcane_arts_base)
    ));
    // layout
    QHBoxLayout* arcane_arts_layout = new QHBoxLayout();
    arcane_arts_layout->setContentsMargins(0, 0, 0, 0);
    arcane_arts_layout->setSpacing(
        *scry::gui::global::meta::widgets_startup->get(
            "splash_screen.arcane_arts.spacing", ME_INTV(arc::int32)
        )
    );
    arcane_arts_base->setLayout(arcane_arts_layout);

    // create a the logo
    QLabel* logo = new QLabel();
    QPixmap logo_pix;
    logo_pix.loadFromData(
        scry::util::data::access_as_qbytearray(
            *scry::gui::global::meta::widgets_startup->get(
                "splash_screen.arcane_arts.logo.image",
                metaengine::PathV::instance(
                    rip::global::meta::resource_locations.get())
            ),
            rip::global::res::accessor.get()
        )
    );
    logo->resize(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.arcane_arts.logo.size", MQT_WGTSZV(logo)
    ));
    logo->setPixmap(logo_pix);
    logo->setPixmap(logo_pix.scaled(logo->size()));
    logo->setStyleSheet("background: rgba(0, 0, 0, 0);");
    arcane_arts_layout->addWidget(logo);

    // create the title
    QLabel* title = new QLabel((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.arcane_arts.title.text", ME_U8STRV
    )).get_raw());
    // title style sheet
    title->setStyleSheet((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.arcane_arts.title.style_sheet", ME_U8STRV
    )).get_raw());
    // title font
    title->setFont(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.arcane_arts.title.font", MQT_FONTV
    ));
    // add to layout
    arcane_arts_layout->addWidget(title);

    // resize base to fit contents
    arcane_arts_base->resize(arcane_arts_base->sizeHint());
}

void SplashScreen::init_logging()
{
    // create a label that will display log messages
    QLabel* logger_label = new QLabel("", this);
    // logger size
    logger_label->resize(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.logger.size", MQT_WGTSZV(logger_label)
    ));
    // logger position
    logger_label->move(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.logger.position", MQT_WGTPOSV(logger_label)
    ));
    // logger style sheet
    logger_label->setStyleSheet((*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.logger.style_sheet", ME_U8STRV
    )).get_raw());
    // logger font
    logger_label->setFont(*scry::gui::global::meta::widgets_startup->get(
        "splash_screen.logger.font", MQT_FONTV
    ));

    // create the arcane log output
    m_logger = new scry::gui::logging::LabelLogger(
        logger_label,
        arclog::VERBOSITY_DEBUG
    );
    arclog::shared_handler.add_output(m_logger);

    scry::logger->notice << "Bootstrapping..." << std::endl;
}

} // namespace startup
} // namespace gui
} // namespace scry
