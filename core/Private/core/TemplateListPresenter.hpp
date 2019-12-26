// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_TEMPLATE_LIST_PRESENTER__
#define __H_CORE_TEMPLATE_LIST_PRESENTER__

#include <core/Observer.hpp>
#include <core/Presenter.hpp>

class TemplateListPresenter : public Presenter, public Observer
{
  public:
    virtual void Start() override;

    virtual void Input(std::string const& event_name,
                       Args const&        args) override;

    virtual void Update() override;

    virtual ~TemplateListPresenter();

  public:
    void UpdateTemplates();
};

#endif