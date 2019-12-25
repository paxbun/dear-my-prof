// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_DETAIL_VIEW__
#define __H_CORE_DETAIL_VIEW__

#include <core/Args.hpp>
#include <core/DetailPresenter.hpp>
#include <core/View.hpp>

class DetailView : public View
{
  private:
    DetailPresenter _detail;

  public:
    DetailView(Args&& args)
        : View("detail.html",
               { { "detail-refresh", &_detail } },
               std::move(args))
    {}
};

#endif