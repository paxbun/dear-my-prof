// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/DetailView.hpp>
#include <core/Email.hpp>
#include <core/HasApp.hpp>
#include <core/OpenDetailPresenter.hpp>
#include <core/View.hpp>

void OpenDetailPresenter::Input(std::string const& event_name, Args const& args)
{
    Args new_args = Args::array();
    new_args.push_back(std::string("---data-id=")
                       + args.at("id").get<std::string>());

    app()->NewWindow(new DetailView(std::move(new_args)), view());
}