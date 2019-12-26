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
    auto new_args = view()->creationArgs();
    for (auto it = args.begin(); it != args.end(); ++it)
        new_args[it.key()] = it.value();
    app()->Navigate(view(), new FillTemplateView(std::move(new_args)));
}