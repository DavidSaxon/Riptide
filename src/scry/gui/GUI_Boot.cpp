#include "scry/gui/GUI_Boot.hpp"

#include <arcanecore/base/str/StringOperations.hpp>
#include <arcanecore/io/sys/FileSystemOperations.hpp>

#include <metaengine/Document.hpp>
#include <metaengine/visitors/Shorthand.hpp>

#include <QtCore/QByteArray>
#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>

#include <meta_qt/gui/Font.hpp>

#include "scry/base/SC_Global.hpp"
#include "scry/base/SC_Logging.hpp"
#include "scry/base/SC_MetaCompiled.hpp"
#include "scry/gui/GUI_Global.hpp"
#include "scry/util/Data.hpp"
#include "scry/util/Font.hpp"

namespace scry
{
namespace gui
{
namespace boot
{

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

/*!
 * \brief Performs initialisation of MetaEngine data for Scry's
 *        GUI.
 */
void meta_initialisation_subroutine();

/*!
 * \brief Loads the fonts required by Scry's GUI.
 */
void load_fonts();

/*!
 * \brief Assigns the built-in fonts of Scry.
 */
void assign_application_fonts();

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void initialisation_routine()
{
    scry::logger->debug
        << "Initialising integral components of the GUI" << std::endl;

    meta_initialisation_subroutine();
    load_fonts();
    assign_application_fonts();
}

void shutdown_routine()
{
    scry::logger->debug << "Shutting down the GUI" << std::endl;
}

void meta_initialisation_subroutine()
{
    scry::logger->debug << "Initialising GUI MetaEngine data" << std::endl;

    // build the path to the gui metadata directory
    arc::io::sys::Path gui_meta_path(scry::global::meta::META_SCRY_DIR);
    gui_meta_path << "gui";
    // build the path to the gui resources metadata directory
    arc::io::sys::Path resources_meta_path(gui_meta_path);
    resources_meta_path << "resources";

    //----------------------------RESOURCE LOCATIONS----------------------------
    // build the path the resource locations metadata
    arc::io::sys::Path locations_meta_path(resources_meta_path);
    locations_meta_path << "locations.json";
    // built-in memory data
    static const arc::str::UTF8String locations_compiled(
        SCRY_METACOMPILED_GUI_RESOURCES_LOCATIONS);
    // construct the document
    scry::gui::global::meta::resource_locations.reset(new metaengine::Document(
        locations_meta_path,
        &locations_compiled
    ));

    //----------------------------------FONTS-----------------------------------
    // build the path the fonts metadata
    arc::io::sys::Path fonts_meta_path(resources_meta_path);
    fonts_meta_path << "fonts.json";
    // built-in memory data
    static const arc::str::UTF8String fonts_compiled(
        SCRY_METACOMPILED_GUI_RESOURCES_FONTS);
    // construct the document
    scry::gui::global::meta::fonts.reset(new metaengine::Document(
        fonts_meta_path,
        &fonts_compiled
    ));

    //----------------------------------ICONS-----------------------------------
    // build the path the fonts metadata
    arc::io::sys::Path icons_meta_path(resources_meta_path);
    icons_meta_path << "icons.json";
    // built-in memory data
    static const arc::str::UTF8String icons_compiled(
        SCRY_METACOMPILED_GUI_RESOURCES_ICONS);
    // construct the document
    scry::gui::global::meta::icons.reset(new metaengine::Document(
        icons_meta_path,
        &icons_compiled
    ));

    // build the path to the gui widgets metadata directory
    arc::io::sys::Path widgets_meta_path(gui_meta_path);
    widgets_meta_path << "widgets";

    //-----------------------------STARTUP WIDGETS------------------------------
    // build the path the startup widgets metadata
    arc::io::sys::Path startup_meta_path(widgets_meta_path);
    startup_meta_path << "startup.json";
    // built-in memory data
    static const arc::str::UTF8String startup_compiled(
        SCRY_METACOMPILED_GUI_WIDGETS_STARTUP);
    // construct the document
    scry::gui::global::meta::widgets_startup.reset(new metaengine::Document(
        startup_meta_path,
        &startup_compiled
    ));
}

void load_fonts()
{
    scry::logger->debug << "Loading fonts" << std::endl;

    // get the directory where fonts are stored
    arc::io::sys::Path font_directory(
        *scry::gui::global::meta::resource_locations->get(
            "fonts_resource_path", ME_PATHV
        )
    );

    // resolve the supported font formats
    std::vector<arc::str::UTF8String> supported_formats(
        *scry::gui::global::meta::fonts->get(
            "supported_formats", ME_U8STRVECV
        )
    );

    // iterate over each file in the fonts directory and add to the database
    for(const arc::io::sys::Path& path :
        scry::global::res::accessor->list_rec(font_directory))
    {
        // skip directories
        if(arccol::Accessor::force_real_resources &&
           !arc::io::sys::is_file(path))
        {
            continue;
        }

        // check that this font is a supported format
        arc::str::UTF8String extension(path.get_extension());
        if (std::find(
                supported_formats.begin(),
                supported_formats.end(),
                extension
            ) != supported_formats.end())
        {
            scry::logger->debug
                << "Loading font from: " << path << std::endl;

            // attempt to load the font
            int font_id = QFontDatabase::addApplicationFontFromData(
                scry::util::data::access_as_qbytearray(
                    path,
                    scry::global::res::accessor.get()
                )
            );
            if(font_id < 0)
            {
                scry::logger->warning
                    << "Font file could not be loaded it may be corrupt or an "
                    << "invalid font file \"" << path << "\"" << std::endl;
            }
        }
        else
        {
            static arc::str::UTF8String f_supported_formats(
                arc::str::join(supported_formats, ", "));

            scry::logger->warning
                << "Font file will not be loaded as it is an unsupported "
                << "format \"" << path << "\". Supported formats are: ["
                << f_supported_formats << "]" << std::endl;
        }
    }
}

void assign_application_fonts()
{
    scry::logger->debug << "Assigning application fonts" << std::endl;

    // TODO: should have a meta engine iterator for children

    // assign the title font from the fallback list
    for(const arc::str::UTF8String& font_family :
        *scry::gui::global::meta::fonts->get(
            "application_fonts.title", ME_U8STRVECV
        ))
    {
        if(scry::util::font::is_font_available(font_family))
        {
            scry::gui::global::font::title = font_family;
            break;
        }
    }
    // add the built-in fonts as meta_qt::QFontV family references
    meta_qt::QFontV::instance().add_family_reference(
        "title", scry::gui::global::font::title);


    // assign the title font from the fallback list
    for(const arc::str::UTF8String& font_family :
        *scry::gui::global::meta::fonts->get(
            "application_fonts.console", ME_U8STRVECV
        ))
    {
        if(scry::util::font::is_font_available(font_family))
        {
            scry::gui::global::font::console = font_family;
            break;
        }
    }
    // add the built-in fonts as meta_qt::QFontV family references
    meta_qt::QFontV::instance().add_family_reference(
        "console", scry::gui::global::font::console);

    // assign the arcane arts font from the fallback list
    for(const arc::str::UTF8String& font_family :
        *scry::gui::global::meta::fonts->get(
            "application_fonts.arcane_arts", ME_U8STRVECV
        ))
    {
        if(scry::util::font::is_font_available(font_family))
        {
            scry::gui::global::font::arcane_arts = font_family;
            break;
        }
    }
    // add the built-in fonts as meta_qt::QFontV family references
    meta_qt::QFontV::instance().add_family_reference(
        "arcane_arts", scry::gui::global::font::arcane_arts);
}

} // namespace boot
} // namespace gui
} // namespace scry
