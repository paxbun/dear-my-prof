// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/TemplateList.hpp>

#include <map>
#include <sstream>

std::string const content = R"~(2

BEGIN
면담 문의
${이름.이} ${물건.을} 먹습니다.
${학번} ${이름} 면담 문의입니다.
${교수님성함} 교수님께
안녕하세요, ${학번} ${이름}입니다.
END

BEGIN
과제 문의
${학번} ${이름} 과제 문의입니다.
${교수님성함} 교수님께
END)~";

int main()
{
    size_t                          num_temps = 0;
    std::istringstream              iss(content);
    std::map<std::string, Template> template_list;

    iss >> num_temps;
    for (size_t i = 0; i < num_temps; ++i)
    {
        Template new_temp;
        if (Template::ReadFrom(iss, new_temp))
        {
            auto const theme = new_temp.theme();
            template_list.insert(std::make_pair(theme, std::move(new_temp)));
        }
    }

    if (template_list.at(u8"면담 문의").GetAllParameters().size() != 4)
        return 1;

    if (template_list.at(u8"과제 문의").GetAllParameters().size() != 3)
        return 1;

    return 0;
}