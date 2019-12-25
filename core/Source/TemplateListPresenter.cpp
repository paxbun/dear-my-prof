// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/RootView.hpp>
#include <core/TemplateListPresenter.hpp>
#include <core/View.hpp>

void TemplateListPresenter::Input(std::string const& event_name,
                                  Args const&        args)
{
    auto const temps = TemplateList::GetInstance()->GetAllTemplates();

    Args new_args = Args::array();
    for (auto const& temp : temps)
        new_args.push_back({ { "theme", temps.theme },
                             { "subject", temps.subject },
                             { "content", temps.content },
                             { "id", std::to_string(temps.id) } });

    view()->Output("emplate-refresh-reply", new_args);
}