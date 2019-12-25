// Copyright (c) 2019 Dear My Professor Authors
// Author: sp301415

#include <algorithm>
#include <core/StringTransform.hpp>
#include <core/StringTransformFactory.hpp>
#include <core/TemplateString.hpp>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

TemplateString TemplateString::ParseFrom(std::string const& original_string)
{
    _base                 = original_string;
    std::size_t pos_begin = 0, pos_end = 0, pos_mid = 0;

    while (true)
    {
        pos_begin = _base.find("${", pos_begin);
        if (pos_begin == std::string::npos)
            break;

        pos_end = _base.find('}', pos_begin);
        pos_mid = _base.find('.', pos_begin);

        if (pos_mid != std::string::npos)
        {
            _param.push_back(std::make_tuple(
                pos_begin,
                _base.substr(pos_begin + 2, pos_mid - pos_begin - 2),
                StringTransformFactory::GetTransform(
                    _base.substr(pos_mid + 1, pos_end - pos_mid - 1))));
        }
        else
        {
            _param.push_back(std::make_tuple(
                pos_begin,
                _base.substr(pos_begin + 2, pos_end - pos_begin - 2),
                nullptr));
        }
        _base.replace(pos_begin, pos_end - pos_begin + 1, "");
    }

    return *this;
}

TemplateString::TemplateString(
    std::string const&                                                 base,
    std::vector<std::tuple<int, std::string, StringTransform*>> const& param)
    : _base { base }, _param { param }
{}

std::string TemplateString::Generate(
    std::unordered_map<std::string, std::string> transformMap)
{
    std::string base = _base;
    for (auto s : _param)
    {
        auto pos       = std::get<0>(s);
        auto param     = std::get<1>(s);
        auto transform = std::get<2>(s);

        auto replaced_string = transformMap[param];
        if (transform != nullptr)
        {
            replaced_string = transform->Transform(replaced_string);
        }

        base.insert(pos, replaced_string);
    }

    return base;
}