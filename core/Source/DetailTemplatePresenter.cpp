// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/DetailTemplatePresenter.hpp>
#include <core/TemplateList.hpp>
#include <core/View.hpp>

void DetailTemplatePresenter::Input(std::string const& event_name,
                                    Args const&        args)
{
    auto theme_it = args.find("theme");
    if (theme_it != args.end())
    {
        try
        {
            auto temp = TemplateList::GetInstance()->GetTemplateByTheme(
                theme_it->get<std::string>());

            auto email = temp.ToEmail();

            view()->Output("detail-template-refresh-reply",
                           { { "theme", temp.theme() },
                             { "subject", email.subject },
                             { "content", email.content } });
        }
        catch (...)
        {
            app()->Close(view());
        }
    }
}