// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/Address.hpp>
#include <core/ProfessorList.hpp>
#include <core/ProfessorPresenter.hpp>
#include <core/View.hpp>

#include <vector>

void ProfessorPresenter::Input(std::string const& event_name, Args const& args)
{
    ProfessorList* list  = ProfessorList::GetInstance();
    auto           query = args.at("query").get<std::string>();

    std::vector<Address> addrss[] = { list->GetProfByName(query),
                                      list->GetProfBySubjects(query),
                                      list->GetProfByAddress(query) };

    Args new_arg = Args::array();
    for (auto const& addrs : addrss)
        for (auto const& addr : addrs)
        {
            if (!addr.realName.empty())
                new_arg.push_back(Args::array({ addr.email, addr.realName }));
            else if (!addr.email.empty())
                new_arg.push_back(addr.email);
        }

    view()->Output("professor-reply", new_arg);
}