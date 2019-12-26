// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_EMAIL_LIST__
#define __H_CORE_EMAIL_LIST__

#include <core/Email.hpp>
#include <core/Subject.hpp>

#include <unordered_map>
#include <vector>

/*
    EmailList 클래스는 현재 접속 중인 유저의 모든 이메일을 가지고 있는
    모델입니다. 이메일의 불러오기, 보내기는 이 클래스에서 이루어집니다.
*/
class EmailList : public Subject
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
    std::unordered_map<Email::EmailId, Email> _inbox;
    std::unordered_map<Email::EmailId, Email> _sent;

  public:
    std::vector<Email> inbox()
    {
        std::vector<Email> rtn;
        rtn.reserve(_inbox.size());
        for (auto& [_, value] : _inbox) rtn.push_back(value);
        return rtn;
    }

  public:
    /*
        Parameters
        num_emails: 불러오고 싶은 이메일의 개수입니다.

        Return Value
        최근 받은 이메일을 num_emails만큼 반환합니다.
    */
    std::vector<Email> FetchInbox(size_t num_emails);

    /*
        Parameters
        num_emails: 불러오고 싶은 이메일의 개수입니다.

        Return Value
        최근 보낸 이메일을 num_emails만큼 반환합니다.
    */
    std::vector<Email> FetchSent(size_t num_emails);

    /*
        Parameters
        id: 이메일의 아이디입니다.

        Return Value
        주어진 id를 가진 이메일을 반환합니다.

        Exception
        주어진 id를 가진 이메일이 없을 경우, std::out_of_range를 던집니다.
    */
    Email const& GetEmailById(Email::EmailId id);

    /*
        이메일 전송을 시도합니다.

        Parameters
        email: 보낼 이메일입니다.

        Return Value
        성공시 true, 실패시 false를 반환합니다.
    */
    bool TrySend(Email&& email);

  private:
    void _FetchInbox(size_t num_emails);
};

#endif