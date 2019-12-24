// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_LOGIN_PRESENTER__
#define __H_CORE_LOGIN_PRESENTER__

#include <core/Presenter.hpp>
#include <core/View.hpp>

class LoginPresenter : public Presenter
{
  public:
    virtual void Input(std::string const& event_name, Args const& args) override
    {
        view()->Output("login-failed");
    }
};

#endif