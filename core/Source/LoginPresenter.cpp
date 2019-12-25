// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/CredentialManager.hpp>
#include <core/HasApp.hpp>
#include <core/LoginPresenter.hpp>
#include <core/RootView.hpp>
#include <core/View.hpp>

void LoginPresenter::Input(std::string const& event_name, Args const& args)
{
    auto id_it   = args.find("id");
    auto pw_it   = args.find("pw");
    auto sid_it  = args.find("sid");
    auto name_it = args.find("name");

    if (id_it != args.end() && pw_it != args.end() && sid_it != args.end()
        && name_it != args.end())
    {
        auto id   = id_it.value().get<std::string>();
        auto pw   = pw_it.value().get<std::string>();
        auto sid  = sid_it.value().get<std::string>();
        auto name = name_it.value().get<std::string>();

        if (CredentialManager::GetInstance()->TryLogin(id, pw, sid, name))
            app()->Navigate(view(), new RootView);
        else
            view()->Output("login-failed");
    }
    else
        view()->Output("login-failed");
}