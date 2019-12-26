// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/Template.hpp>

#include <string>

Template Template::ParseFrom(std::istream& is)
{
    std::string line;
    do
    {
        std::getline(is, line);
    } while (line != "BEGIN");

    // Read subject
    std::getline(is, line);
    auto subject = TemplateString::ParseFrom(line);

    // Read content
    std::string content;
    while (true)
    {
        std::getline(is, line);
        if (line == "END")
            break;
        content.append(line);
        content.push_back('\n');
    }
    auto content = TemplateString::ParseFrom(content);

    return Template(std::move(subject), std::move(content));
}

Template
Template::Generate(std::unordered_map<std::string, std::string> const& map)
{
    return Template(_subject.Generate(map), _content.Generate(map));
}

Email Template::ToEmail()
{
    return Email(
        _subject.ToString(), Address(), Address(), _content.ToString());
}

std::set<std::string> Template::GetAllParameters()
{
    std::set<std::string> rtn;

    for (auto const& param : _subject.param()) rtn.insert(param.name);
    for (auto const& param : _content.param()) rtn.insert(param.name);

    return rtn;
}
