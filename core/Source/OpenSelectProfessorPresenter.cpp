// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/HasApp.hpp>
#include <core/OpenSelectProfessorPresenter.hpp>
#include <core/SelectProfessorView.hpp>
#include <core/View.hpp>

void OpenSelectProfessorPresenter::Input(std::string const& event_name,
                                         Args const&        args)
{
    app()->Navigate(view(), new SelectProfessorView(Args(args)));
}