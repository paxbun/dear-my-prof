// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_FILL_TEMPLATE_VIEW__
#define __H_CORE_FILL_TEMPLATE_VIEW__

#include <core/Args.hpp>
#include <core/EnvironmentPresenter.hpp>
#include <core/OpenNewEmailPresenter.hpp>
#include <core/TemplatePresenter.hpp>
#include <core/View.hpp>

class FillTemplateView : public View
{
  private:
    TemplatePresenter     _template;
    EnvironmentPresenter  _environment;
    OpenNewEmailPresenter _openNewEmail;

  public:
    FillTemplateView(Args&& args)
        : View("filltemplate.html",
               { { "template-init", &_template },
                 { "template-params", &_template },
                 { "template-fill", &_template },
                 { "environment", &_environment },
                 { "create-new-email", &_openNewEmail } },
               std::move(args))
    {}
};

#endif