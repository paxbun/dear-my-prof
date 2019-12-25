// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/EmailList.hpp>

std::vector<Email> EmailList::FetchInbox(size_t num_emails)
{
    // TODO
    _FetchInbox(num_emails);
    return inbox();
}

void EmailList::_FetchInbox(size_t num_emails)
{
    _inbox.clear();
    _inbox.reserve(num_emails);

    for (size_t i = 0; i < num_emails; ++i)
        _inbox.insert(std::make_pair(i,
                                     Email(u8"제목",
                                           "foo@dgist.ac.kr",
                                           "bar@dgist.ac.kr",
                                           u8"내용",
                                           std::vector<std::string> {},
                                           std::vector<std::string> {},
                                           i)));
}