// Copyright (c) 2019 Dear My Professor Authors
// Author: ixora99

#ifndef _H_CORE_LOWER_STRING_TRANSFORM__
#define _H_CORE_LOWER_STRING_TRANSFORM__

#include <algorithm>
#include <cctype>
#include <core/CodaStringTransform.hpp>

/*
    UpeerStringTransform 클래스는 영문을 모두 소문자로 바꾸는 문자열 변환
   함수입니다.
*/
class LowerStringTransform : public CodaStringTransform
{
  public:
    virtual std::string Transform(std::string const& input) noexcept override
    {
        try
        {
            std::string out = input;
            std::transform(input.begin(), input.end(), out.begin(), tolower);
        }
        catch (...)
        {
            return std::string();
        }
    }
};

#endif