// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/Args.hpp>
#include <core/HasApp.hpp>
#include <core/NewEmailView.hpp>
#include <core/OpenNewEmailPresenter.hpp>
#include <core/View.hpp>

void OpenNewEmailPresenter::Input(std::string const& event_name,
                                  Args const&        args)
{
    Args new_args = Args::array();
    new_args.push_back(
        std::string("---subject=" + args.at("subject").get<std::string>()));
    new_args.push_back(
        std::string("---content=" + args.at("content").get<std::string>()));

    app()->Navigate(view(), new NewEmailView(std::move(new_args)));
}