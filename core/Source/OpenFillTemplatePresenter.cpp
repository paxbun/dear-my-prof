// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/FillTemplateView.hpp>
#include <core/HasApp.hpp>
#include <core/OpenFillTemplatePresenter.hpp>
#include <core/View.hpp>

void OpenFillTemplatePresenter::Input(std::string const& event_name,
                                      Args const&        args)
{
    Args new_args = Args::array();
    new_args.push_back(std::string("---theme=")
                       + args.at("theme").get<std::string>());

    app()->Navigate(view(), new FillTemplateView(std::move(new_args)));
}