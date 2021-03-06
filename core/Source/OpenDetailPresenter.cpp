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
    if (app()->GetNumberOfViews() == 1)
        app()->NewWindow(new DetailView(Args(args)), view());
}