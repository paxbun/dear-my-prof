// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_LOGIN_VIEW__
#define __H_CORE_LOGIN_VIEW__

#include <core/LoginPresenter.hpp>
#include <core/View.hpp>

class LoginView : public View
{
  private:
    LoginPresenter _loginPresenter;

  public:
    LoginView() : View("login.html", { { "login", &_loginPresenter } }) {}
};

#endif