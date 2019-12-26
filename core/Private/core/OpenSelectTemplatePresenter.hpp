// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_OPEN_SELECT_TEMPLATE_PRESENTER__
#define __H_CORE_OPEN_SELECT_TEMPLATE_PRESENTER__

#include <core/Presenter.hpp>

class OpenSelectTemplatePresenter : public Presenter
{
  public:
    virtual void Input(std::string const& event_name,
                       Args const&        args) override;
};

#endif