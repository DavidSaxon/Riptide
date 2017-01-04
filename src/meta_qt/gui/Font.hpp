#ifndef META_QT_GUI_FONT_HPP_
#define META_QT_GUI_FONT_HPP_

#include <metaengine/Document.hpp>

#include <QtGui/QFont>

namespace meta_qt
{

/*!
 * \brief MetaEngine Visitor object used to retrieve a QFont object.
 *
 * The JSON data must be an object that has a sub member named ```family``` and
 * an optional sub-member named ```size```. The family must be a string
 * represent the name of the family or the actual name of the font to use.
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

    /*!
     * \brief Provides an existing static instance of this object.
     */
    static QFontV& instance();

    // override
    virtual bool retrieve(
            const Json::Value* data,
            const arc::str::UTF8String& key,
            metaengine::Document* requester,
            arc::str::UTF8String& error_message);

};

/*!
 * \brief Shorthand for meta_qt::QFontV::instance()
 */
#define MQT_FONTV meta_qt::QFontV::instance()

} // namespace meta_qt

#endif
