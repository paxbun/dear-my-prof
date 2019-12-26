// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_TEMPLATE_LIST_VIEW__
#define __H_CORE_TEMPLATE_LIST_VIEW__

#include <core/Args.hpp>
#include <core/OpenDetailTemplatePresenter.hpp>
#include <core/OpenNewTemplatePresenter.hpp>
#include <core/TemplateListPresenter.hpp>
#include <core/View.hpp>

class TemplateListView : public View
{
    OpenNewTemplatePresenter    _openNewTemplate;
    OpenDetailTemplatePresenter _openDetailTemplate;
    TemplateListPresenter       _templateList;

  public:
    TemplateListView()
        : View("template.html",
               { { "create-new-template-window", &_openNewTemplate },
                 { "create-detail-template-window", &_openDetailTemplate },
                 { "template-refresh", &_templateList } })
    {}
};

#endif