// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_STRING_TRANSFORM__
#define __H_CORE_STRING_TRANSFORM__

#include <string>

/*
    StringTransform 인터페이스는 문자열 변환 함수의 추상화입니다.
*/
class StringTransform
{
  public:
    /*
        Parameters
        input: 변환하고 싶은 문자열입니다.

        Return Value
        주어진 문자열에 대한 변환 결과를 반환합니다.
    */
    virtual std::string Transform(std::string const& input) noexcept = 0;
};

#endif