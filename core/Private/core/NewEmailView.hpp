// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_NEW_EMAIL_VIEW__
#define __H_CORE_NEW_EMAIL_VIEW__

#include <core/Args.hpp>
#include <core/SendEmailPresenter.hpp>
#include <core/View.hpp>

class NewEmailView : public View
{
  private:
    SendEmailPresenter _sendEmail;

  public:
    NewEmailView(Args&& args)
        : View("newemail.html",
               { { "send-email", &_sendEmail } },
               std::move(args))
    {}
};

#endif