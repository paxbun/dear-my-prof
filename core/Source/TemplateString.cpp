// Copyright (c) 2019 Dear My Professor Authors
// Author: sp301415

#include <algorithm>
#include <core/StringTransform.hpp>
#include <core/StringTransformFactory.hpp>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

TemplateString TemplateString::ParseFrom(std::string const& original_string)
{
    _base                 = original_string;
    std::size_t pos_begin = 0, pos_end = 0;

    while (true)
    {
        pos_begin = original_string.find("${", pos_begin);
        if (pos_begin == std::string::npos)
            break;
        pos_end = original_string.find("}", pos_begin);

        if (auto p = original_string.find(".", pos_begin) != std::string::npos)
        {
            _param.push_back(std::make_tuple(
                pos_begin,
                original_string.substr(pos_begin + 2, p - 1),
                GetTransform(original_string.substr(p, pos_end - 1))));
        }
        else
        {
            _param.push_back(std::make_tuple(
                pos_begin,
                original_string.substr(pos_begin + 2, pos_end-1),
                nullptr)));
        }
    }

    return this;
}

TemplateString::TemplateString(
    std::string const&                                            base,
    vector<std::tuple<int, std::string, StringTransform*>> const& param)
    : _base { base }, _param { param };

std::string TemplateString::Generate(
    std::unordered_map<std::string, std::string> const& transformMap)
{
    std::string base = _base;
    for (auto s : _param)
    {
        auto pos                   = std::get<0>(s);
        auto param                 = std::get<1>(s);
        auto string_transform_func = std::get<2>(s);
        auto pos_end               = _base.find("}", pos);

        std::string replaced_string = transformMap[param];
        if (string_transform_func != nullptr)
        {
            replaced_string = string_transform_func(replaced_string);
        }

        base.replace(pos, pos_end, replaced_string);
    }

    return base;
}