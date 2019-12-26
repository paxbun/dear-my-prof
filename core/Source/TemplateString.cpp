// Copyright (c) 2019 Dear My Professor Authors
// Author: sp301415

#include <core/StringTransform.hpp>
#include <core/StringTransformFactory.hpp>
#include <core/TemplateString.hpp>

#include <map>
#include <regex>
#include <stdexcept>

std::string TemplateString::_Parameter::ToString() const
{
    if (transformName.empty())
        return "${" + name + "}";
    else
        return "${" + name + "." + transformName + "}";
}

TemplateString TemplateString::ParseFrom(std::string const& str)
{
    std::regex expr(R"~(\$\s*\{\s*([^\.\s]*)\s*(\.\s*([^\.\s]*))?\s*\})~");
    std::vector<std::string> new_base;
    std::vector<_Parameter>  new_param;

    size_t begin = 0;
    for (std::sregex_iterator it(str.begin(), str.end(), expr), e; it != e;
         ++it)
    {
        auto const& match = *it;
        new_base.push_back(str.substr(begin, match.position() - begin));
        if (match.size() < 4)
            new_param.push_back(
                { match[1],
                  "",
                  StringTransformFactory::GetTransform(match[3]) });
        else
            new_param.push_back(
                { match[1],
                  match[3],
                  StringTransformFactory::GetTransform(match[3]) });
        begin = match.position() + match.length();
    }
    new_base.push_back(str.substr(begin));

    return TemplateString(std::move(new_base), std::move(new_param));
}

TemplateString TemplateString::Generate(
    std::unordered_map<std::string, std::string> const& map) const
{
    std::string              on_synthesize;
    std::vector<std::string> new_base;
    std::vector<_Parameter>  new_param;

    for (size_t i = 0, l = _param.size(); i < l; ++i)
    {
        on_synthesize.append(_base[i]);

        if (auto it = map.find(_param[i].name); it != map.end())
            on_synthesize.append(_param[i].transform->Transform(it->second));
        else
        {
            size_t length = on_synthesize.size();

            new_base.push_back(std::move(on_synthesize));
            new_param.push_back(_param[i]);

            on_synthesize = std::string();
            on_synthesize.reserve(length);
        }
    }
    on_synthesize.append(_base.back());
    new_base.push_back(std::move(on_synthesize));

    return TemplateString(std::move(new_base), std::move(new_param));
}

std::string TemplateString::ToString() const
{
    std::string rtn;

    for (size_t i = 0, l = _param.size(); i < l; ++i)
    {
        rtn.append(_base[i]);
        rtn.append(_param[i].ToString());
    }
    rtn.append(_base.back());

    return rtn;
}
