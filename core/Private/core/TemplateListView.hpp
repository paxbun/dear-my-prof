// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_TEMPLATE_LIST_VIEW__
#define __H_CORE_TEMPLATE_LIST_VIEW__

#include <core/Args.hpp>
#include <core/OpenDetailTemplatePresenter.hpp>
#include <core/TemplateListPresenter.hpp>
#include <core/View.hpp>

class TemplateListView : public View
{
    // TODO
    OpenDetailTemplatePresenter _openDetailTemplate;
    TemplateListPresenter       _templateList;

  public:
    TemplateListView()
        : View("template.html",
               { { "template-refresh", &_templateList },
                 { "create-detail-template-window", &_openDetailTemplate } })
    {}
};

#endif