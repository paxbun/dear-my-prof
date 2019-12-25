// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/DetailPresenter.hpp>
#include <core/View.hpp>

void DetailPresenter::Input(std::string const& event_name, Args const& args)
{
    // TODO
    view()->Output("detail-refresh-reply",
                   { { "title", u8"제목" },
                     { "subtitle", u8"부제목" },
                     { "body", u8"내용" } });
}