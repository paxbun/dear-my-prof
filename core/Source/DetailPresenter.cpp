// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/DetailPresenter.hpp>
#include <core/EmailList.hpp>
#include <core/View.hpp>

void DetailPresenter::Input(std::string const& event_name, Args const& args)
{
    auto const& creation_args = view()->creationArgs();
    auto        id_it         = creation_args.find("id");
    if (id_it != creation_args.end())
    {
        try
        {
            auto email = EmailList::GetInstance()->GetEmailById(
                std::stoi(id_it->get<std::string>()));

            view()->Output("detail-refresh-reply",
                           { { "subject", email.subject },
                             { "from", email.from.email },
                             { "content", email.content } });
        }
        catch (...)
        {
            app()->Close(view());
        }
    }
}