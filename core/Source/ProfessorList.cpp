// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/ProfessorList.hpp>

#include <algorithm>
#include <fstream>

ProfessorList ProfessorList::_singleton
    = ProfessorList("./Asset/ProfessorList.txt");

std::vector<Address> ProfessorList::GetProfByName(std::string const& name)
{
    std::vector<Address> rtn;

    for (auto const& prof : _profList)
        if (prof.addr.realName == name)
            rtn.push_back(prof.addr);

    return rtn;
}

std::vector<Address> ProfessorList::GetProfBySubjects(std::string const& name)
{
    std::vector<Address> rtn;

    for (auto const& prof : _profList)
        if (std::find(prof.subjects.begin(), prof.subjects.end(), name)
            != prof.subjects.end())
            rtn.push_back(prof.addr);

    return rtn;
}

void ProfessorList::_ReadFrom(std::filesystem::path const& path)
{
    std::ifstream ifs(path);

    if (ifs)
    {
        size_t num = 0;
        ifs >> num;

        if (!ifs.fail())
        {
            std::vector<_Professor> new_prof_list;
            new_prof_list.reserve(num);

            for (size_t i = 0; i < num; ++i)
            {
                std::string realName, id;
                ifs >> realName >> id;
                size_t subject_num = 0;
                ifs >> subject_num;

                if (!ifs.fail())
                {
                    std::vector<std::string> new_subjects;
                    new_subjects.resize(subject_num);
                    for (size_t j = 0; j < subject_num; ++j)
                        ifs >> new_subjects[j];

                    new_prof_list.push_back(
                        { Address { std::move(realName), std::move(id) },
                          std::move(new_subjects) });
                }
                else
                    return;
            }

            _profList = std::move(new_prof_list);
        }
    }
}