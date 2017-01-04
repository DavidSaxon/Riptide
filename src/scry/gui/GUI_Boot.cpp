#include "scry/gui/GUI_Boot.hpp"

#include <arcanecore/base/str/StringOperations.hpp>
#include <arcanecore/io/sys/FileSystemOperations.hpp>

#include <metaengine/Document.hpp>
#include <metaengine/visitors/Shorthand.hpp>

#include <arcanecollate/Reader.hpp>

#include <QtCore/QByteArray>
#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>

#include "scry/common/SC_Global.hpp"
#include "scry/common/SC_Logging.hpp"
#include "scry/common/SC_MetaCompiled.hpp"
#include "scry/gui/GUI_Global.hpp"

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
 * \brief Performs initialisation of Qt.
 */
void qt_initialisation_subroutine();

/*!
 * \brief Performs the shutdown of Qt.
 */
void qt_shutdown_subroutine();

/*!
 * \brief Loads the fonts required by Scry's GUI.
 */
void load_fonts();

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void initialisation_routine()
{
    scry::logger->debug
        << "Initialising integral components of the GUI" << std::endl;

    meta_initialisation_subroutine();
    qt_initialisation_subroutine();
    load_fonts();
}

void shutdown_routine()
{
    scry::logger->debug << "Shutting down the GUI" << std::endl;

    qt_shutdown_subroutine();
}

void meta_initialisation_subroutine()
{
    scry::logger->debug << "Initialising GUI MetaEngine data" << std::endl;

    // build the path to the gui metadata directory
    arc::io::sys::Path gui_meta_path(util::meta::META_SCRY_DIR);
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
}

void qt_initialisation_subroutine()
{
    scry::logger->debug << "Initialising Qt" << std::endl;

    int argc = 0;
    scry::gui::global::qt_application = new QApplication(argc, nullptr);
}

void qt_shutdown_subroutine()
{
    scry::logger->debug << "Shutting down Qt" << std::endl;

    if(scry::gui::global::qt_application != nullptr)
    {
        delete scry::gui::global::qt_application;
        scry::gui::global::qt_application = nullptr;
    }
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

            // access the font file
            arccol::Reader font_reader(
                path,
                scry::global::res::accessor.get()
            );
            // read the data from the file
            const arc::int64 data_size = font_reader.get_size();
            char* font_data = new char[data_size];
            font_reader.read(font_data, data_size);

            // attempt to load the font
            QByteArray byte_array =
                QByteArray::fromRawData(font_data, data_size);
            if(QFontDatabase::addApplicationFontFromData(byte_array) != 0)
            {
                scry::logger->warning
                    << "Font file could not be loaded it may be corrupt or an "
                    << "invalid font file \"" << path << "\"" << std::endl;
            }

            // clean up
            delete[] font_data;
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

} // namespace boot
} // namespace gui
} // namespace scry
