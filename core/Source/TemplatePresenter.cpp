// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/HasApp.hpp>
#include <core/RootView.hpp>
#include <core/TemplateList.hpp>
#include <core/TemplatePresenter.hpp>
#include <core/View.hpp>

std::unordered_map<std::string, void (TemplatePresenter::*)(Args const&)> const
    TemplatePresenter::_eventMap
    = { { "template-init", &TemplatePresenter::_InitTemplate },
        { "template-params", &TemplatePresenter::_GetParameters },
        { "template-fill", &TemplatePresenter::_FillTemplate } };

void TemplatePresenter::Input(std::string const& event_name, Args const& args)
{
    if (auto it = _eventMap.find(event_name); it != _eventMap.end())
        (this->*(it->second))(args);
}

void TemplatePresenter::_InitTemplate(Args const& args)
{
    auto const& creation_args = view()->creationArgs();
    if (auto it = creation_args.find("theme"); it != creation_args.end())
    {
        auto theme = it->get<std::string>();
        _temp      = TemplateList::GetInstance()->GetTemplateByTheme(theme);
        _OutputTemplate(_temp);
    }
    else
        app()->Close(view());
}

void TemplatePresenter::_GetParameters(Args const& args)
{
    auto new_args = Args::array();
    auto params   = _temp.GetAllParameters();

    for (auto const& str : params) new_args.push_back(str);

    view()->Output("template-params-reply", std::move(new_args));
}

void TemplatePresenter::_FillTemplate(Args const& args)
{
    std::unordered_map<std::string, std::string> map;

    for (auto it = args.begin(); it != args.end(); ++it)
        if (it.value().is_string())
            map.insert(std::make_pair(it.key(), it.value().get<std::string>()));

    _OutputTemplate(_temp.Generate(map));
}

void TemplatePresenter::_OutputTemplate(Template const& temp)
{
    auto email = temp.ToEmail();

    view()->Output("template-out",
                   { { "theme", temp.theme() },
                     { "subject", email.subject },
                     { "content", email.content } });
}
