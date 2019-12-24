// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/View.hpp>

void View::Input(std::string const& event_name, Args const& event_args)
{
    if (auto it = _bindMap.find(event_name); it != _bindMap.end())
        it->second->Input(event_name, event_args);
}

void View::Bind(std::string const& event_name, Presenter* presenter)
{
    _bindMap.insert(std::make_pair(event_name, presenter));
}

void View::Output(std::string const& response_name, Args const& response_args)
{
    if (auto h_app = app(); h_app)
        h_app->Output(this, response_name, response_args);
}
