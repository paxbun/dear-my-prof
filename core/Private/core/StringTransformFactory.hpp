// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_STRING_TRANSFORM_FACTORY__
#define __H_CORE_STRING_TRANSFORM_FACTORY__

#include <core/StringTransform.hpp>

#include <unordered_map>

/*
    StringTransformFactory는 주어진 패러미터에 따라 알맞은 StringTransform
    인터페이스 구현을 반환합니다.
*/
class StringTransformFactory
{
  private:
    static std::unordered_map<std::string, StringTransform*> _transformMap;

  public:
    /*
        Parameters
        transform_name: 변환 함수의 이름입니다.

        Return Value
        주어진 이름을 가진 변환 함수를 반환합니다. 만약 그런 함수가 없다면,
        nullptr를 반환합니다.
    */
    static StringTransform* GetTransform(std::string const& transform_name);
};

#endif