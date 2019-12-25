// Copyright (c) 2019 Dear My Professor Authors
// Author: sp301415

#ifndef __H_CORE_TEMPLATE_STRING__
#define __H_CORE_TEMPLATE_STRING__

#include <core/StringTransform.hpp>
#include <core/StringTransformFactory.hpp>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

class TemplateString : public StringTransform
{
  private:
    std::string                                                 _base;
    std::vector<std::tuple<int, std::string, StringTransform*>> _param;

  public:
    TemplateString ParseFrom(std::string const&);
    TemplateString(
        std::string const&,
        std::vector<std::tuple<int, std::string, StringTransform*>> const&);
    std::string Generate(std::unordered_map<std::string, std::string>);
};

#endif // __H_CORE_TEMPLATE_STRING__
