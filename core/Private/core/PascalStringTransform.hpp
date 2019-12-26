// Copyright (c) 2019 Dear My Professor Authors
// Author: ixora99

#ifndef _H_CORE_PASCAL_STRING_TRANSFORM__
#define _H_CORE_PASCAL_STRING_TRANSFORM__

#include <algorithm>
#include <cctype>
#include <core/CodaStringTransform.hpp>

/*
    UpeerStringTransform 클래스는 영문을 첫 글자만 대문자로 바꾸는 문자열 변환
   함수입니다.
*/
class PascalStringTransform : public CodaStringTransform
{
  public:
    virtual std::string Transform(std::string const& input) noexcept override
    {
        try
        {
            std::string out = input;
            std::transform(
                input.begin(), input.begin() + 1, out.begin(), toupper);
            std::transform(
                input.begin() + 1, input.end(), out.begin() + 1, tolower);
            return out;
        }
        catch (...)
        {
            return std::string();
        }
    }
};

#endif