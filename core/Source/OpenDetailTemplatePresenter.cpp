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
    app()->NewWindow(new DetailTemplateView(Args(args)), view());
}