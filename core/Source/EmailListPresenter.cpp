// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/EmailListPresenter.hpp>
#include <core/View.hpp>

void EmailListPresenter::Input(std::string const& event_name, Args const& args)
{
    // TODO
    Args new_args = Args::array();
    for (int i = 0; i < 5; ++i)
        new_args.push_back({
            { "title", u8"제목" },
            { "subtitle", u8"부제목" },
            { "body", u8"내용" },
            { "id", 12345 },
        });
    view()->Output("mail-refresh-reply", new_args);
}