// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_SELECT_PROFESSOR_VIEW__
#define __H_CORE_SELECT_PROFESSOR_VIEW__

#include <core/Args.hpp>
#include <core/OpenFillTemplatePresenter.hpp>
#include <core/ProfessorPresenter.hpp>
#include <core/View.hpp>

class SelectProfessorView : public View
{
  private:
    ProfessorPresenter        _professor;
    OpenFillTemplatePresenter _openFillTemplate;

  public:
    SelectProfessorView(Args&& args)
        : View("selectprofessor.html",
               { { "professor", &_professor },
                 { "create-fill-template", &_openFillTemplate } },
               std::move(args))
    {}
};

#endif