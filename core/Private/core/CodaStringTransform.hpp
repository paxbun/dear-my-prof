// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_CODA_STRING_TRANSFORM__
#define __H_CORE_CODA_STRING_TRANSFORM__

#include <core/StringTransform.hpp>

/*
    CodaStringTransform 클래스는 어미의 종성 여부에 따라 형태가 달라지는 조사를
    처리하기 위한 문자열 변환 함수의 추상화입니다.
*/
class CodaStringTransform : public StringTransform
{
  protected:
    /*
        주어진 문자가 종성으로 끝나는지의 여부를 반환합니다.

        Parameters
        input: 확인하고 싶은 문자열입니다.

        Return Value
        종성으로 끝나면 true, 아니면 false를 반환합니다.
    */
    bool _EndsWithCoda(std::string const& input);
};

#endif