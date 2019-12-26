// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/HasApp.hpp>
#include <core/NewTemplateView.hpp>
#include <core/OpenNewTemplatePresenter.hpp>
#include <core/View.hpp>

void OpenNewTemplatePresenter::Input(std::string const& event_name,
                                     Args const&        args)
{
    app()->NewWindow(new NewTemplateView, view());
}