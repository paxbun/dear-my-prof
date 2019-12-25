// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef _H_CORE_THEME_STRING_TRANSFORM__
#define _H_CORE_THEME_STRING_TRANSFORM__

#include <core/CodaStringTransform.hpp>

/*
    ThemeStringTransform 클래스는 조사 이/가를 붙이는 문자열 변환 함수입니다.
*/
class ThemeStringTransform
{
  public:
    virtual std::string Transform(std::string const& input) noexcept override
    {
        try
        {
            if (_EndsWithCoda(input))
                return input + u8"이";
            else
                return input + u8"가";
        }
        catch (...)
        {
            return std::string();
        }
    }
};

#endif