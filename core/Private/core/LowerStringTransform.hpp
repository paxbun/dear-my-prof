// Copyright (c) 2019 Dear My Professor Authors
// Author: ixora99

#ifndef _H_CORE_LOWER_STRING_TRANSFORM__
#define _H_CORE_LOWER_STRING_TRANSFORM__

#include <algorithm>
#include <cctype>
#include <core/CodaStringTransform.hpp>

/*
    UpeerStringTransform Ŭ������ ������ ��� �ҹ��ڷ� �ٲٴ� ���ڿ� ��ȯ
   �Լ��Դϴ�.
*/
class LowerStringTransform : public StringTransform
{
  public:
    virtual std::string Transform(std::string const& input) noexcept override
    {
        try
        {
            std::string out = input;
            std::transform(input.begin(), input.end(), out.begin(), tolower);
            return out;
        }
        catch (...)
        {
            return std::string();
        }
    }
};

#endif