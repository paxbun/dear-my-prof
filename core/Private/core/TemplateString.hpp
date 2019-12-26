// Copyright (c) 2019 Dear My Professor Authors
// Author: sp301415

#ifndef __H_CORE_TEMPLATE_STRING__
#define __H_CORE_TEMPLATE_STRING__

#include <core/StringTransform.hpp>
#include <core/StringTransformFactory.hpp>

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

/*
    TemplateString 클래스는 템플릿의 채우기 기능을 수행합니다. 내부적으로
    매개변수의 이름과 위치, 변환함수를 가지고 있습니다.
*/
class TemplateString : public StringTransform
{
  private:
    struct _Parameter
    {
      public:
        std::string      name;
        std::string      transformName;
        StringTransform* transform;

      public:
        /*
            Return Value
            이 _Parameter를 순수한 문자열로 반환합니다. 이 문자열은 다시
            파싱할 수 있습니다.
        */
        std::string ToString();
    };

  private:
    std::vector<std::string> _base;
    std::vector<_Parameter>  _param;

  public:
    std::vector<std::string> const& base()
    {
        return _base;
    }

    std::vector<_Parameter> const& param()
    {
        return _param;
    }

  public:
    /*
        Parameters
        str: TemplateString으로 변환할 문자열입니다.

        Return Value
        주어진 문자열을 파싱한 결과를 반환합니다.
    */
    static TemplateString ParseFrom(std::string const& str);

  private:
    template <typename BaseT  = std::vector<std::string>,
              typename ParamT = std::vector<_Parameter>>
    TemplateString(BaseT&& base, ParamT&& param)
        : _base(std::forward<BaseT>(base)), _param(std::forward<ParamT>(param))
    {}

  public:
    TemplateString() : _base(1, std::string()) {}

  public:
    /*
        Parameters
        map: 매개변수의 이름과 들어갈 값을 대응시킨 맵입니다.

        Return Value
        주어진 맵에 따라 변수를 집어넣은 결과를 반환합니다.
    */
    TemplateString
    Generate(std::unordered_map<std::string, std::string> const& map);

    /*
        Return Value
        이 TemplateString을 순수한 문자열로 반환합니다. 이 문자열은 다시 파싱할
        수 있습니다.
    */
    std::string ToString();
};

#endif