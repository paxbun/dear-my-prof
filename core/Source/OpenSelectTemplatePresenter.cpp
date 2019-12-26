// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/HasApp.hpp>
#include <core/OpenSelectTemplatePresenter.hpp>
#include <core/SelectTemplateView.hpp>
#include <core/View.hpp>

void OpenSelectTemplatePresenter::Input(std::string const& event_name,
                                        Args const&        args)
{
    app()->NewWindow(new SelectTemplateView, view());
}