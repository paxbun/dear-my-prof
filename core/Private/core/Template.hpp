// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_TEMPLATE__
#define __H_CORE_TEMPLATE__

#include <core/Email.hpp>
#include <core/TemplateString.hpp>

#include <iostream>
#include <map>
#include <set>

/*
    Template 클래스는 하나의 템플릿을 저장하는 모델입니다.
*/
class Template
{
  public:
    static bool ReadFrom(std::istream& is, Template& out);

  private:
    std::string    _theme;
    TemplateString _subject;
    TemplateString _content;

  public:
    std::string const& theme() const
    {
        return _theme;
    }

  public:
    Template() {}

    template <typename SubjectT = TemplateString,
              typename ContentT = TemplateString,
              typename ThemeT   = std::string>
    Template(SubjectT&& subject, ContentT&& content, ThemeT&& theme = ThemeT())
        : _subject(std::forward<SubjectT>(subject)),
          _content(std::forward<ContentT>(content)),
          _theme(std::forward<ThemeT>(theme))
    {}

  public:
    /*
        Parameters
        map: 매개변수의 이름과 들어갈 값을 대응시킨 맵입니다.

        Return Value
        주어진 맵에 따라 변수를 집어넣은 결과를 반환합니다.
    */
    Template
    Generate(std::unordered_map<std::string, std::string> const& map) const;

    /*
        Return Value
        이 템플릿을 Email 객체로 변환합니다. 채워지지 않은 매개변수는 ${}의
        형태로 나타납니다.
    */
    Email ToEmail() const;

    /*
        Return Value
        이 템플릿의 모든 매개변수 이름의 목록을 반환합니다.
    */
    std::set<std::string> GetAllParameters() const;

    /*
        이 템플릿을 해당 스트림에 출력합니다.

        Parameters
        os: 출력할 스트림입니다.
    */
    void WriteTo(std::ostream& os) const;
};

#endif