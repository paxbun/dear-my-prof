// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/TemplateList.hpp>

#include <fstream>

TemplateList TemplateList::_singleton = TemplateList("./Asset/Templates.txt");

Template const& TemplateList::GetTemplateByTheme(std::string const& theme)
{
    return _templateList.at(theme);
}

void TemplateList::AddTemplate(Template&& temp)
{
    auto const theme = temp.theme();
    _templateList.insert(std::make_pair(theme, std::move(temp)));
    _WriteTo(_path);
    _NotifyObservers();
}

void TemplateList::_ReadFrom(std::filesystem::path const& path)
{
    size_t        num_temps = 0;
    std::ifstream ifs(path);
    ifs >> num_temps;

    for (size_t i = 0; i < num_temps; ++i)
    {
        Template new_temp;
        if (Template::ReadFrom(ifs, new_temp))
        {
            auto const theme = new_temp.theme();
            _templateList.insert(std::make_pair(theme, std::move(new_temp)));
        }
    }
}

void TemplateList::_WriteTo(std::filesystem::path const& path)
{
    std::ofstream ofs(path);
    ofs << _templateList.size() << '\n';
    for (auto const& [_, temp] : _templateList) temp.WriteTo(ofs);
}