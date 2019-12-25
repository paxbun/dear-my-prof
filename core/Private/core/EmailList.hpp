// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_EMAIL_LIST__
#define __H_CORE_EMAIL_LIST__

#include <core/Email.hpp>

#include <vector>

/*
    EmailList 클래스는 현재 접속 중인 유저의 모든 이메일을 가지고 있는
    모델입니다. 이메일의 불러오기, 보내기는 이 클래스에서 이루어집니다.
*/
class EmailList
{
    // TODO

  private:
    static EmailList _singleton;

  public:
    static EmailList* GetInstance()
    {
        return &_singleton;
    }

  private:
    std::vector<Email> _inbox;

  public:
    std::vector<Email> const& inbox()
    {
        return _inbox;
    }

  public:
    /*
         Parameters
         num_emails: 불러오고 싶은 이메일의 개수입니다.

         Return Valeu
         최근 이메일을 num_emails만큼 반환합니다.
    */
    std::vector<Email> const& FetchInbox(size_t num_emails);

  private:
    void _FetchInbox(size_t num_emails);
};

#endif