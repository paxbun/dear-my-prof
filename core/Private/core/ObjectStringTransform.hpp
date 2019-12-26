// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef _H_CORE_OBJECT_STRING_TRANSFORM__
#define _H_CORE_OBJECT_STRING_TRANSFORM__

#include <core/CodaStringTransform.hpp>

/*
    ObjectStringTransform 클래스는 조사 을/를을 붙이는 문자열 변환 함수입니다.
*/
class ObjectStringTransform : public CodaStringTransform
{
  public:
    virtual std::string Transform(std::string const& input) noexcept override
    {
        try
        {
            if (_EndsWithCoda(input))
                return input + u8"을";
            else
                return input + u8"를";
        }
        catch (...)
        {
            return std::string();
        }
    }
};

#endif