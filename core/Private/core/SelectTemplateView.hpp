// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_SELECT_TEMPLATE_VIEW__
#define __H_CORE_SELECT_TEMPLATE_VIEW__

#include <core/Args.hpp>
#include <core/OpenSelectProfessorPresenter.hpp>
#include <core/TemplateListPresenter.hpp>
#include <core/View.hpp>

class SelectTemplateView : public View
{
  private:
    TemplateListPresenter        _templateList;
    OpenSelectProfessorPresenter _openSelectProfessor;

  public:
    SelectTemplateView()
        : View("selecttemplate.html",
               { { "template-refresh", &_templateList },
                 { "create-select-professor", &_openSelectProfessor } })
    {}
};

#endif