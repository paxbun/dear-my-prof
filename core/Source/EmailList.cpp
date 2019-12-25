// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/EmailList.hpp>

std::vector<Email> const& EmailList::FetchInbox(size_t num_emails)
{
    // TODO
    _FetchInbox(num_emails);
    return _inbox;
}

void EmailList::_FetchInbox(size_t num_emails)
{
    _inbox = std::vector<Email>(
        num_emails,
        Email(u8"제목", "foo@dgist.ac.kr", "bar@dgist.ac.kr", u8"내용"));
}