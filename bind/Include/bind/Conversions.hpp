// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_BIND_CONVERSIONS__
#define __H_BIND_CONVERSIONS__

#include <core/Args.hpp>

#include <napi.h>

/*
    Conversions 클래스는 Napi::Object과 Args 사이의 변환 함수들을 구현합니다.
*/
class Conversions
{
  public:
    /*
        Parameters
        env: 자바스크립트 환경 핸들입니다.
        args: 변환할 Args 객체입니다.

        Return Value
        변환된 Napi::Value 객체를 반환합니다.
    */
    static Napi::Value ConvertArgs(Napi::Env env, Args const& args);

    /*
        Parameters
        env: 자바스크립트 환경 핸들입니다.
        val: 변환할 Napi::Value 객체입니다.

        Return Value
        변환된 Args 객체를 반환합니다.
    */
    static Args ConvertObject(Napi::Env env, Napi::Value val);
};

#endif