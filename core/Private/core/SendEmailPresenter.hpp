// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_SEND_EMAIL_PRESENTER__
#define __H_CORE_SEND_EMAIL_PRESENTER__

#include <core/Presenter.hpp>

class SendEmailPresenter : public Presenter
{
  private:
    Address              _Args2Addr(Args const& args);
    std::vector<Address> _Args2Addrs(Args const& args);

  public:
    virtual void Input(std::string const& event_name,
                       Args const&        args) override;

  private:
    bool _TrySend(Args const& args);
};

#endif