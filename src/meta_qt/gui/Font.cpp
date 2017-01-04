#include "meta_qt/gui/Font.hpp"

#include <json/json.h>

namespace meta_qt
{

QFontV& QFontV::instance()
{
    static QFontV v;
    return v;
}

bool QFontV::retrieve(
        const Json::Value* data,
        const arc::str::UTF8String& key,
        metaengine::Document* requester,
        arc::str::UTF8String& error_message)
{
    // is the data an object
    if(!data->isObject())
    {
        Json::FastWriter j_writer;
        error_message << "\"" << j_writer.write(*data) << "\" cannot be "
                      << "converted to an object type, which is required to "
                      << "retrieve QFont.";
        return false;
    }

    // has the family member been supplied?
    if(!data->isMember("family"))
    {
        Json::FastWriter j_writer;
        error_message << "\"" << j_writer.write(*data) << "\" has no member \""
                      << "family\" which is required to retrieve QtFont.";
        return false;
    }

    // get the family member
    Json::Value family_member((*data)["family"]);

    // is the member a string?
    if(!family_member.isString())
    {
        Json::FastWriter j_writer;
        error_message << "family member \"" << j_writer.write(family_member)
                      << "\" is not a valid UTF8-string type.";
        return false;
    }

    // create the font
    m_value = QFont(family_member.asCString());

    // has the size member been supplied
    if(!data->isMember("size"))
    {
        // we're done
        return true;
    }

    // get the size member
    Json::Value size_member((*data)["size"]);

    // is the member an int
    if(size_member.isInt())
    {
        // use point size
        m_value.setPointSize(size_member.asInt());
        return true;
    }

    // is the member a string
    if(!size_member.isString())
    {
        Json::FastWriter j_writer;
        error_message << "size member \"" << j_writer.write(size_member)
                      << "\" is not a valid integral or UTF-8 string "
                      << "type.";
        return false;
    }

    // resolve as a string
    arc::str::UTF8String size(size_member.asCString());

    // no suffix
    if(size.is_int())
    {
        // use point size
        m_value.setPointSize(size.to_int32());
        return true;
    }

    // px suffix
    if(size.ends_with("px"))
    {
        // ensure we can get an integral
        arc::str::UTF8String integral(size.substring(0, size.get_length() - 2));
        if(!integral.is_int())
        {
            error_message << "Cannot convert size member pixel value \""
                          << integral << "\" to an integral type.";
            return false;
        }

        // use pixel size
        m_value.setPixelSize(integral.to_int32());
        return true;
    }

    // couldn't resolve
    error_message << "Cannot resolve size member \"" << size << "\" since it "
                  << "has an unrecognised syntax.";
    return false;
}

} // namespace meta_qt
