// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_TEMPLATE_PRESENTER__
#define __H_CORE_TEMPLATE_PRESENTER__

#include <core/Presenter.hpp>
#include <core/Template.hpp>

#include <unordered_map>

class TemplatePresenter : public Presenter
{
  private:
    static std::unordered_map<std::string,
                              void (TemplatePresenter::*)(Args const&)> const
        _eventMap;

  private:
    Template _temp;

  public:
    virtual void Input(std::string const& event_name,
                       Args const&        args) override;

  private:
    void _InitTemplate(Args const& args);

    void _GetParameters(Args const& args);

    void _FillTemplate(Args const& args);

    void _OutputTemplate(Template const& temp);
};

#endif