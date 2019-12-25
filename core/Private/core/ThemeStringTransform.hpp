// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef _H_CORE_THEME_STRING_TRANSFORM__
#define _H_CORE_THEME_STRING_TRANSFORM__

#include <core/CodaStringTransform.hpp>

/*
    ThemeStringTransform 클래스는 조사 은/는를 붙이는 문자열 변환 함수입니다.
*/
class ThemeStringTransform : public CodaStringTransform
{
  public:
    virtual std::string Transform(std::string const& input) noexcept override
    {
        try
        {
            if (_EndsWithCoda(input))
                return input + u8"은";
            else
                return input + u8"는";
        }
        catch (...)
        {
            return std::string();
        }
    }
};

#endif