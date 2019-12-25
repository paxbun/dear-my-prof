// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_LOGIN_PRESENTER__
#define __H_CORE_LOGIN_PRESENTER__

#include <core/Presenter.hpp>
#include <core/RootView.hpp>
#include <core/View.hpp>

class LoginPresenter : public Presenter
{
  public:
    virtual void Input(std::string const& event_name, Args const& args) override
    {
        auto id_it = args.find("id");
        auto pw_it = args.find("pw");
        if (id_it != args.end() && pw_it != args.end())
        {
            auto id = id_it.value().get<std::string>();
            auto pw = pw_it.value().get<std::string>();

            if (id == pw)
                app()->Navigate(view(), new RootView);
            else
                view()->Output("login-failed");
        }
        else
            view()->Output("login-failed");
    }
};

#endif