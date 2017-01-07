#ifndef META_QT_GUI_FONT_HPP_
#define META_QT_GUI_FONT_HPP_

#include <map>

#include <metaengine/Document.hpp>

#include <QtGui/QFont>

namespace meta_qt
{

/*!
 * \brief MetaEngine Visitor object used to retrieve a QFont object.
 *
 * The JSON data must be an object that has a sub member named ```family``` and
 * an optional sub-member named ```size```.
 *
 * The family must be a string represent the name of the family, the actual name
 * of the font to use, or the name of a reference. Font references can be used
 * with the syntax: ```"#{reference_name}"```. Family references can be added
 * with the QFontV::add_family_reference function.
 *
 * The size represents the point or pixel size of the font and supports the
 * following syntax:
 *
 * - <b>integral or string of integral:</b> The point size of the font.
 *   Examples: ```12```, ```"22"````.
 *
 * - <b>string with ```px``` suffix:</b> The exact pixel size of the font.
 *   Example: ```"10px"```.
 */
class QFontV : public metaengine::Visitor<QFont>
{
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC STATIC FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Provides an existing static instance of this object.
     */
    static QFontV& instance();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    // override
    virtual bool retrieve(
            const Json::Value* data,
            const arc::str::UTF8String& key,
            metaengine::Document* requester,
            arc::str::UTF8String& error_message);

    /*!
     * \brief Adds a new reference for a font family.
     *
     * \note If a reference already exists with the given name it will be
     *       overwritten.
     *
     * \param name The name of the reference to add.
     * \param target The name of the font family this reference the reference
     *                points to.
     */
    void add_family_reference(
            const arc::str::UTF8String& name,
            const arc::str::UTF8String& target);

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    // TODO: use unordered_map
    /*!
     * \brief Maps the names of reference to the names of font families they
     *        point to.
     */
    std::map<arc::str::UTF8String, arc::str::UTF8String> m_family_refs;
};

/*!
 * \brief Shorthand for meta_qt::QFontV::instance()
 */
#define MQT_FONTV meta_qt::QFontV::instance()

} // namespace meta_qt

#endif
