// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/CredentialManager.hpp>
#include <core/EmailList.hpp>

void EmailList::FetchInbox(size_t num_emails)
{
    // TODO
    _inbox.clear();

    for (size_t i = 0; i < num_emails; ++i)
        _inbox.insert(std::make_pair(10000 + i,
                                     Email(u8"제목 " + std::to_string(i * 2),
                                           "foo@dgist.ac.kr",
                                           "bar@dgist.ac.kr",
                                           u8"내용",
                                           std::vector<Address> {},
                                           std::vector<Address> {},
                                           10000 + i)));

    _NotifyObservers();
}

Email const& EmailList::GetEmailById(Email::EmailId id)
{
    return _inbox.at(id);
}

bool EmailList::TrySend(Email&& email)
{
    // TODO

    static size_t idx = 0;
    if (email.subject.empty() || email.to.email.empty())
        return false;

    email.from = CredentialManager::GetInstance()->id();
    _inbox.insert(std::make_pair(idx++, std::move(email)));
    _NotifyObservers();

    return true;
}