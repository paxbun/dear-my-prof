// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/HasApp.hpp>
#include <core/OpenTemplateListPresenter.hpp>
#include <core/TemplateListView.hpp>
#include <core/View.hpp>

void OpenTemplateListPresenter::Input(std::string const& event_name,
                                      Args const&        args)
{
    if (app()->GetNumberOfViews() == 1)
        app()->NewWindow(new TemplateListView, view());
}