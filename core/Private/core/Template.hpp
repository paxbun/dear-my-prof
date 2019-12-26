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
    static Template ParseFrom(std::istream& is);

  public:
    using TemplateId = size_t;

  public:
    TemplateId id;

  private:
    TemplateString _subject;
    TemplateString _content;

  public:
    template <typename SubjectT = TemplateString,
              typename ContentT = TemplateString>
    Template(SubjectT&& subject,
             ContentT&& content,
             TemplateId id = TemplateId(0))
        : _subject(std::forward<SubjectT>(subject)),
          _content(std::forward<ContentT>(content)),
          _id(id)
    {}

  public:
    /*
        Parameters
        map: 매개변수의 이름과 들어갈 값을 대응시킨 맵입니다.

        Return Value
        주어진 맵에 따라 변수를 집어넣은 결과를 반환합니다.
    */
    Template Generate(std::unordered_map<std::string, std::string> const& map);

    /*
        Return Value
        이 템플릿을 Email 객체로 변환합니다. 채워지지 않은 매개변수는 ${}의
        형태로 나타납니다.
    */
    Email ToEmail();

    /*
        Return Value
        이 템플릿의 모든 매개변수 이름의 목록을 반환합니다.
    */
    std::set<std::string> GetAllParameters();
};

#endif