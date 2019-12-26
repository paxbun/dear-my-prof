// Copyright (c) 2019 Dear My Professor Authors
// Author: ixora99

#ifndef _H_CORE_UPPER_STRING_TRANSFORM__
#define _H_CORE_UPPER_STRING_TRANSFORM__

#include <core/CodaStringTransform.hpp>
#include <algorithm>
#include <cctype>

/*
    UpeerStringTransform Ŭ������ ������ ��� �빮�ڷ� �ٲٴ� ���ڿ� ��ȯ
   �Լ��Դϴ�.
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
            return out;

        }
        catch (...)
        {
            return std::string();
        }
    }
};

#endif