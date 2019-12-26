// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/Args.hpp>
#include <core/DetailTemplateView.hpp>
#include <core/HasApp.hpp>
#include <core/OpenDetailTemplatePresenter.hpp>
#include <core/View.hpp>

void OpenDetailTemplatePresenter::Input(std::string const& event_name, Args const& args)
{
    Args new_args = Args::array();
    new_args.push_back(std::string("---template-theme=")
                       + args.at("theme").get<std::string>());

    app()->NewWindow(new DetailTemplateView(std::move(new_args)), view());
}