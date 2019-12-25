// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_ROOT_VIEW__
#define __H_CORE_ROOT_VIEW__

#include <core/View.hpp>

class RootView : public View
{
  public:
    RootView() : View("root.html", {}) {}
};

#endif