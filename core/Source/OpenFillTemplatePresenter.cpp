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
    app()->Navigate(view(), new FillTemplateView(Args(args)));
}