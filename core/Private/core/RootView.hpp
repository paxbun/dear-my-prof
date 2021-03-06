// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_ROOT_VIEW__
#define __H_CORE_ROOT_VIEW__

#include <core/EmailListPresenter.hpp>
#include <core/OpenDetailPresenter.hpp>
#include <core/OpenSelectTemplatePresenter.hpp>
#include <core/OpenTemplateListPresenter.hpp>
#include <core/View.hpp>

class RootView : public View
{
  private:
    OpenTemplateListPresenter   _openTemplateList;
    OpenSelectTemplatePresenter _openSelectTemplate;
    EmailListPresenter          _emailList;
    OpenDetailPresenter         _openDetail;

  public:
    RootView()
        : View("root.html",
               { { "create-templates-window", &_openTemplateList },
                 { "create-new-email-window", &_openSelectTemplate },
                 { "mail-refresh", &_emailList },
                 { "create-detail-window", &_openDetail } })
    {}
};

#endif