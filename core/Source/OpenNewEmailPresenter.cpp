// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/HasApp.hpp>
#include <core/NewEmailView.hpp>
#include <core/OpenNewEmailPresenter.hpp>
#include <core/View.hpp>

void OpenNewEmailPresenter::Input(std::string const& event_name,
                                  Args const&        args)
{
    app()->NewWindow(new NewEmailView, view());
}