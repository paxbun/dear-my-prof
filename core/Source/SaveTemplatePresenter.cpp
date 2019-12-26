// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/HasApp.hpp>
#include <core/RootView.hpp>
#include <core/SaveTemplatePresenter.hpp>
#include <core/Template.hpp>
#include <core/TemplateList.hpp>
#include <core/TemplateString.hpp>
#include <core/View.hpp>

void SaveTemplatePresenter::Input(std::string const& event_name,
                                  Args const&        args)
{
    auto theme_it   = args.find("theme");
    auto subject_it = args.find("subject");
    auto content_it = args.find("content");

    if (theme_it != args.end() && subject_it != args.end()
        && content_it != args.end())
    {
        auto theme   = theme_it.value().get<std::string>();
        auto subject = subject_it.value().get<std::string>();
        auto content = content_it.value().get<std::string>();

        TemplateList::GetInstance()->AddTemplate(
            Template(TemplateString::ParseFrom(subject),
                     TemplateString::ParseFrom(content),
                     std::move(theme)));
    }
    else
        view()->Output("save-template-failed");
}