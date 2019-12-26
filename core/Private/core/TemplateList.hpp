// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_TEMPLATE_LIST__
#define __H_CORE_TEMPLATE_LIST__

#include <core/Subject.hpp>
#include <core/Template.hpp>

#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_map>

/*
    TemplateList 클래스는 모든 템플릿 정보를 담고 있는 모델입니다.
    템플릿의 추가는 이 클래스에서 이루어집니다.
*/
class TemplateList : public Subject
{
  public:
    static TemplateList* GetInstance();

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

    TemplateList(std::istream& is)
    {
        _ReadFrom(is);
    }

  public:
    ~TemplateList()
    {
        _WriteTo(_path);
    }

  public:
    /*
        Parameters
        theme: 템플릿의 테마입니다.

        Return Value
        주어진 테마를 가진 이메일을 반환합니다.

        Exceptionpublic Observer
        주어진 테마를 가진 이메일이 없을 경우, std::out_of_range를 던집니다.
    */
    Template const& GetTemplateByTheme(std::string const& theme);

    /*
        주어진 템플릿을 템플릿 목록에 추가합니다. 만약 같은 테마를 가진 템플릿이
        목록에 있다면, 그 템플릿에 덮어쓰기 합니다.

        Parameters
        temp: 추가할 템플릿입니다.
    */
    void AddTemplate(Template&& temp);

    /*
        정해진 파일로부터 템플릿 목록을 읽습니다. 읽은 후에는 옵저버들에게
       통지합니다.
    */
    void LoadList()
    {
        _ReadFrom(_path);
        _NotifyObservers();
    }

  private:
    void _ReadFrom(std::filesystem::path const& path)
    {
        std::ifstream ifs(path);
        _ReadFrom(ifs);
    }

    void _ReadFrom(std::istream& is);

    void _WriteTo(std::filesystem::path const& path);
};

#endif