// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_NEW_TEMPLATE_VIEW__
#define __H_CORE_NEW_TEMPLATE_VIEW__

#include <core/Args.hpp>
#include <core/SaveTemplatePresenter.hpp>
#include <core/View.hpp>

class NewTemplateView : public View
{
  private:
    SaveTemplatePresenter _saveTemplate;

  public:
    NewTemplateView()
        : View("newtemplate.html", { { "save-template", &_saveTemplate } })
    {}
};

#endif