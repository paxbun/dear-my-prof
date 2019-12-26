// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_TEMPLATE_LIST__
#define __H_CORE_TEMPLATE_LIST__

#include <core/Subject.hpp>
#include <core/Template.hpp>

#include <filesystem>
#include <string>
#include <unordered_map>

/*
    TemplateList 클래스는 모든 템플릿 정보를 담고 있는 모델입니다.
    템플릿의 추가는 이 클래스에서 이루어집니다.
*/
class TemplateList : public Subject
{
  private:
    static TemplateList _singleton;

  public:
    static TemplateList* GetInstance()
    {
        return &_singleton;
    }

  private:
    std::unordered_map<std::string, Template> _templateList;
    std::filesystem::path                     _path;

  public:
    std::unordered_map<std::string, Template> const& templateList()
    {
        return _templateList;
    }

  private:
    TemplateList(std::filesystem::path const& path) : _path(path)
    {
        _ReadFrom(path);
    }

  public:
    ~TemplateList()
    {
        _WriteTo(_path);
    }

  public:
    Template const& GetTemplateByTheme(std::string const& theme);

    void AddTemplate(Template&& temp);

  private:
    void _ReadFrom(std::filesystem::path const& path);

    void _WriteTo(std::filesystem::path const& path);
};

#endif