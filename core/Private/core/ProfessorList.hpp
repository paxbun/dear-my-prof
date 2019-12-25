// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_PROFESSOR_LIST__
#define __H_CORE_PROFESSOR_LIST__

#include <core/Address.hpp>

#include <filesystem>
#include <vector>

/*
    ProfessorList 클래스는 교수 목록을 저장하는 모델입니다.
*/
class ProfessorList
{
  private:
    static ProfessorList _singleton;

  public:
    static ProfessorList* GetInstance()
    {
        return &_singleton;
    }

  private:
    struct _Professor
    {
        Address                  addr;
        std::vector<std::string> subjects;
    };

  private:
    std::vector<_Professor> _profList;

  private:
    ProfessorList(std::filesystem::path const& path)
    {
        _ReadFrom(path);
    }

  public:
    /*
        Parameters
        name: 교수님의 성함입니다.

        Return Value
        주어진 성함의 교수님들의 메일 목록을 반환합니다.
    */
    std::vector<Address> GetProfByName(std::string const& name);

    /*
        Parameters
        name: 과목의 이름입니다.

        Return Value
        주어진 이름의 과목을 맡으신 교수님들의 메일 목록을 반환합니다.
    */
    std::vector<Address> GetProfBySubjects(std::string const& name);

  private:
    /*
        주어진 파일에서 교수님 목록을 읽습니다.

        Paramters
        path: 교수님 목록 파일이 있는 경로입니다.
    */
    void _ReadFrom(std::filesystem::path const& path);
};

#endif