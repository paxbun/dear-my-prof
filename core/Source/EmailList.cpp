// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/EmailList.hpp>

std::vector<Email> const& EmailList::FetchInbox(size_t num_emails)
{
    // TODO
    return std::vector<Email>(
        num_emails,
        Email(u8"제목", "foo@dgist.ac.kr", "bar@dgist.ac.kr", u8"내용"));
}