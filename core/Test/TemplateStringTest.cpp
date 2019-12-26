// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/TemplateString.hpp>

#include <iostream>

int main()
{
    {
        auto temp
            = TemplateString::ParseFrom(u8"${ 이름.이 } ${ 객체.를 } 먹는다.");

        if (temp.Generate({ { u8"이름", u8"홍길동" } }).ToString()
            != u8"홍길동이 ${객체.를} 먹는다.")
            return 1;
    }

    {
        auto temp
            = TemplateString::ParseFrom(u8"${ 이름.이 } ${객체} 먹는다.");

        if (temp.Generate({ { u8"이름", u8"홍길서" }, { u8"객체", u8"가방" } })
                .ToString()
            != u8"홍길서가 가방 먹는다.")
            return 1;
    }

    return 0;
}