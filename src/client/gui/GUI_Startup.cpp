#include "client/gui/GUI_Startup.hpp"

#include <arcanecore/base/str/StringOperations.hpp>
#include <arcanecore/io/sys/FileSystemOperations.hpp>

#include <metaengine/Document.hpp>
#include <metaengine/visitors/Shorthand.hpp>

#include <arcanecollate/Reader.hpp>

#include <QtCore/QByteArray>
#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>

#include "client/CL_Global.hpp"
#include "client/CL_MetaCompiled.hpp"
#include "client/Logging.hpp"
#include "client/gui/GUI_Global.hpp"

namespace rip_c
{
namespace gui
{

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

/*!
 * \brief Performs initialisation of MetaEngine data for the Riptide Client's
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
 * \brief Loads the fonts required by the Riptide Client GUI.
 */
void load_fonts();

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void initialisation_routine()
{
    rip_c::logger->debug
        << "Initialising integral components of the GUI" << std::endl;

    meta_initialisation_subroutine();
    qt_initialisation_subroutine();
    load_fonts();
}

void shutdown_routine()
{
    rip_c::logger->debug << "Shutting down the GUI" << std::endl;

    qt_shutdown_subroutine();
}

void meta_initialisation_subroutine()
{
    rip_c::logger->debug << "Initialising GUI MetaEngine data" << std::endl;

    // build the path to the gui metadata directory
    arc::io::sys::Path gui_meta_path(util::meta::META_CLIENT_DIR);
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
        RIP_C_METACOMPILED_GUI_RESOURCES_LOCATIONS);
    // construct the document
    rip_c::gui::global::meta::resource_locations.reset(new metaengine::Document(
        locations_meta_path,
        &locations_compiled
    ));

    //----------------------------------FONTS-----------------------------------
    // build the path the fonts metadata
    arc::io::sys::Path fonts_meta_path(resources_meta_path);
    fonts_meta_path << "fonts.json";
    // built-in memory data
    static const arc::str::UTF8String fonts_compiled(
        RIP_C_METACOMPILED_GUI_RESOURCES_FONTS);
    // construct the document
    rip_c::gui::global::meta::fonts.reset(new metaengine::Document(
        fonts_meta_path,
        &fonts_compiled
    ));
}

void qt_initialisation_subroutine()
{
    rip_c::logger->debug << "Initialising Qt" << std::endl;

    int argc = 0;
    rip_c::gui::global::qt_application = new QApplication(argc, nullptr);
}

void qt_shutdown_subroutine()
{
    rip_c::logger->debug << "Shutting down Qt" << std::endl;

    if(rip_c::gui::global::qt_application != nullptr)
    {
        delete rip_c::gui::global::qt_application;
        rip_c::gui::global::qt_application = nullptr;
    }
}

void load_fonts()
{
    rip_c::logger->debug << "Loading fonts" << std::endl;

    // get the directory where fonts are stored
    arc::io::sys::Path font_directory(
        *rip_c::gui::global::meta::resource_locations->get(
            "fonts_resource_path", ME_PATHV
        )
    );

    // resolve the supported font formats
    std::vector<arc::str::UTF8String> supported_formats(
        *rip_c::gui::global::meta::fonts->get(
            "supported_formats", ME_U8STRVECV
        )
    );

    // TODO: need file system list for collated resources...
    // TODO: can this include collated and real resources?

    // iterate over each file in the fonts directory and add to the database
    for(const arc::io::sys::Path& path : arc::io::sys::list_rec(font_directory))
    {
        // check that this font is a supported format
        arc::str::UTF8String extension(path.get_extension());
        if (std::find(
                supported_formats.begin(),
                supported_formats.end(),
                extension
            ) != supported_formats.end())
        {
            rip_c::logger->debug
                << "Loading font from: " << path << std::endl;

            // access the font file
            arccol::Reader font_reader(
                path,
                rip_c::global::res::accessor.get()
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
                rip_c::logger->warning
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

            rip_c::logger->warning
                << "Font file will not be loaded as it is an unsupported "
                << "format \"" << path << "\". Supported formats are: ["
                << f_supported_formats << "]" << std::endl;
        }
    }
}

} // namespace gui
} // namespace rip_c
