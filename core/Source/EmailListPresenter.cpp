// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/EmailList.hpp>
#include <core/EmailListPresenter.hpp>
#include <core/View.hpp>

void EmailListPresenter::Start()
{
    EmailList::GetInstance()->AddObserver(this);
}

void EmailListPresenter::Input(std::string const& event_name, Args const& args)
{
    UpdateEmail();
}

void EmailListPresenter::Update()
{
    Args new_args = Args::array();
    for (auto const& email : EmailList::GetInstance()->inbox())
        new_args.push_back({ { "subject", email.subject },
                             { "from", email.from.email },
                             { "content", email.content },
                             { "id", std::to_string(email.id) } });
    view()->Output("mail-refresh-reply", new_args);
}

EmailListPresenter::~EmailListPresenter()
{
    EmailList::GetInstance()->RemoveObserver(this);
}

void EmailListPresenter::UpdateEmail()
{
    EmailList::GetInstance()->FetchInbox(/* TODO */ 5);
}