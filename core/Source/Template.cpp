// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/Template.hpp>

#include <string>

bool Template::ReadFrom(std::istream& is, Template& out)
{
    std::string line;
    do
    {
        std::getline(is, line);
    } while (line != "BEGIN");

    // Read Theme
    std::getline(is, line);
    if (line == "END")
        return false;
    auto theme = std::move(line);
    line       = std::string();

    // Read subject
    std::getline(is, line);
    if (line == "END")
        return false;
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
    content.pop_back();
    auto parsed_content = TemplateString::ParseFrom(content);

    out = Template(
        std::move(subject), std::move(parsed_content), std::move(theme));
    return true;
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

void Template::WriteTo(std::ostream& os)
{
    os << "BEGIN\n"
       << _theme << '\n'
       << _subject.ToString() << '\n'
       << _content.ToString() << '\n'
       << "END\n";
}