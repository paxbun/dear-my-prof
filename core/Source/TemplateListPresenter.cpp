// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/RootView.hpp>
#include <core/TemplateList.hpp>
#include <core/TemplateListPresenter.hpp>
#include <core/View.hpp>

void TemplateListPresenter::Start()
{
    TemplateList::GetInstance()->AddObserver(this);
}

void TemplateListPresenter::Input(std::string const& event_name,
                                  Args const&        args)
{
    UpdateTemplates();
}

void TemplateListPresenter::Update()
{
    UpdateTemplates();
}

TemplateListPresenter::~TemplateListPresenter()
{
    TemplateList::GetInstance()->RemoveObserver(this);
}

void TemplateListPresenter::UpdateTemplates()
{

    auto const temps = TemplateList::GetInstance()->templateList();

    Args new_args = Args::array();
    for (auto const& [theme, temp] : temps)
    {
        auto email = temp.ToEmail();
        new_args.push_back({ { "theme", theme },
                             { "subject", email.subject },
                             { "content", email.content } });
    }

    view()->Output("template-refresh-reply", new_args);
}