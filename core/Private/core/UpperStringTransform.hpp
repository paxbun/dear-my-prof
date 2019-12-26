// Copyright (c) 2019 Dear My Professor Authors
// Author: ixora99

#ifndef _H_CORE_UPPER_STRING_TRANSFORM__
#define _H_CORE_UPPER_STRING_TRANSFORM__

#include <core/CodaStringTransform.hpp>
#include <algorithm>
#include <cctype>

/*
    UpeerStringTransform 클래스는 영문을 모두 대문자로 바꾸는 문자열 변환
   함수입니다.
*/
class UpperStringTransform : public CodaStringTransform
{
  public:
    virtual std::string Transform(std::string const& input) noexcept override
    {
        try
        {
            std::string out = input;
            std::transform(input.begin(), input.end(), out.begin(), toupper);


        }
        catch (...)
        {
            return std::string();
        }
    }
};

#endif