// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_DETAIL_TEMPLATE_VIEW__
#define __H_CORE_DETAIL_TEMPLATE_VIEW__

#include <core/Args.hpp>
#include <core/DetailTemplatePresenter.hpp>
#include <core/View.hpp>

class DetailTemplateView : public View
{
  private:
    DetailTemplatePresenter _detailTemplate;

  public:
    DetailView(Args&& args)
        : View("detailtemplate.html",
               { { "detail-template-refresh", &_detailTemplate } },
               std::move(args))
    {}
};

#endif