// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_CREDENTIAL_MANAGER__
#define __H_CORE_CREDENTIAL_MANAGER__

#include <string>

/*
    CredentialManager 클래스는 사용자의 정보를 저장하는 모델입니다.
*/
class CredentialManager
{
  private:
    static CredentialManager _singleton;

  public:
    static CredentialManager* GetInstance()
    {
        return &_singleton;
    }

  private:
    std::string _id;
    std::string _pw;
    std::string _sid;
    std::string _name;

  public:
    std::string const& id()
    {
        return _id;
    }
    std::string const& pw()
    {
        return _pw;
    }
    std::string const& sid()
    {
        return _sid;
    }
    std::string const& name()
    {
        return _name;
    }

  private:
    CredentialManager() {}

  public:
    /*
        로그인을 시도하고, 성공시 로그인 정보를 저장합니다.
        Parameters
        id: 아이디입니다.
        pw: 비밀번호입니다.
        sid: 학번입니다.
        name: 이름입니다.

        Return Value
        성공시 true를 반환하고, 아닐 경우 false를 반환합니다.
    */
    bool TryLogin(std::string const& id,
                  std::string const& pw,
                  std::string const& sid,
                  std::string const& name) noexcept;
};

#endif