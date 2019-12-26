// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/ProfessorList.hpp>

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string_view>

namespace
{

static std::string const professorListString = R"~(4
홍길동 honggil@dgist.ac.kr 2 다변수미적분학 선형대수학
홍길서 hongseo@dgist.ac.kr 1 전자기학
홍길남 hongnam@dgist.ac.kr 3 물질의이해 기초화학실험 화학반응의이해
홍길북 hongbuk@dgist.ac.kr 1 분자와생명현상)~";

}

ProfessorList* ProfessorList::GetInstance()
{
    static ProfessorList singleton { std::istringstream(professorListString) };
    return &singleton;
}

std::vector<Address> ProfessorList::GetProfByName(std::string const& name)
{
    std::vector<Address> rtn;

    for (auto const& prof : _profList)
        if (prof.addr.realName.rfind(name, 0) == 0)
            rtn.push_back(prof.addr);

    return rtn;
}

std::vector<Address> ProfessorList::GetProfBySubjects(std::string const& name)
{
    std::vector<Address> rtn;

    for (auto const& prof : _profList)
        if (std::find_if(prof.subjects.begin(),
                         prof.subjects.end(),
                         [&name](std::string const& subject) {
                             return subject.find(name) != std::string::npos;
                         })
            != prof.subjects.end())
            rtn.push_back(prof.addr);

    return rtn;
}

std::vector<Address> ProfessorList::GetProfByAddress(std::string const& addr)
{
    std::vector<Address> rtn;

    for (auto const& prof : _profList)
        if (prof.addr.email.rfind(addr, 0) == 0)
            rtn.push_back(prof.addr);

    return rtn;
}

std::vector<Address> ProfessorList::GetAllProfessors()
{
    std::vector<Address> rtn;
    rtn.reserve(_profList.size());

    for (auto const& prof : _profList) rtn.push_back(prof.addr);

    return rtn;
}

void ProfessorList::_ReadFrom(std::istream& is)
{
    if (is)
    {
        size_t num = 0;
        is >> num;

        if (!is.fail())
        {
            std::vector<_Professor> new_prof_list;
            new_prof_list.reserve(num);

            for (size_t i = 0; i < num; ++i)
            {
                std::string realName, id;
                is >> realName >> id;
                size_t subject_num = 0;
                is >> subject_num;

                if (!is.fail())
                {
                    std::vector<std::string> new_subjects;
                    new_subjects.resize(subject_num);
                    for (size_t j = 0; j < subject_num; ++j)
                        is >> new_subjects[j];

                    new_prof_list.push_back(
                        { Address { std::move(id), std::move(realName) },
                          std::move(new_subjects) });
                }
                else
                    return;
            }

            _profList = std::move(new_prof_list);
        }
    }
}