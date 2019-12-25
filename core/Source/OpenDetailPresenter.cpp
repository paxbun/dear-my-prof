// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/DetailView.hpp>
#include <core/HasApp.hpp>
#include <core/OpenDetailPresenter.hpp>
#include <core/View.hpp>

void OpenDetailPresenter::Input(std::string const& event_name, Args const& args)
{
    app()->Navigate(view(), new DetailView(args));
}