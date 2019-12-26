// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/TemplateList.hpp>

#include <fstream>
#include <sstream>

namespace
{

static std::string const templateListStirng = R"~(2

BEGIN
면담 문의
${학번} ${이름} 면담 문의입니다.
${교수님성함} 교수님께
안녕하세요, ${학번} ${이름}입니다.
${테스트.를} 먹는 ${이름}입니다.
END

BEGIN
과제 문의
${학번} ${이름} 과제 문의입니다.
${교수님성함} 교수님께
기초학부 ${이름}입니다.
END)~";

}

TemplateList* TemplateList::GetInstance()
{
    static TemplateList singleton { std::istringstream(templateListStirng) };
    return &singleton;
}

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

void TemplateList::_ReadFrom(std::istream& is)
{
    size_t num_temps = 0;
    is >> num_temps;

    for (size_t i = 0; i < num_temps; ++i)
    {
        Template new_temp;
        if (Template::ReadFrom(is, new_temp))
        {
            auto const theme = new_temp.theme();
            _templateList.insert(std::make_pair(theme, std::move(new_temp)));
        }
    }
}

void TemplateList::_WriteTo(std::filesystem::path const& path)
{
    return;

    // TODO

    std::ofstream ofs(path);
    ofs << _templateList.size() << '\n';
    for (auto const& [_, temp] : _templateList) temp.WriteTo(ofs);
}