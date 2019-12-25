// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_EMAIL__
#define __H_CORE_EMAIL__

#include <string>
#include <vector>

/*
    Email 클래스는 하나의 이메일을 저장하는 모델입니다.
*/
class Email
{
  public:
    std::string              subject;
    std::string              to;
    std::vector<std::string> cc;
    std::vector<std::string> bcc;
    std::string              content;

  public:
    Email() {}

    template <typename SubjectT = std::string,
              typename ToT      = std::string,
              typename ContentT = std::string,
              typename CcT      = std::vector<std::string>,
              typename BccT     = std::vector<std::string>>
    Email(SubjectT&& subject,
          ToT&&      to,
          ContentT&& content,
          CcT&&      cc  = CcT(),
          BccT&      bcc = BccT())
        : subject(std::forward<SubjectT>(subject)),
          to(std::forward<ToT>(to)),
          cc(std::forward<CcT>(cc)),
          bcc(std::forward<BccT>(bcc)),
          content(std::forward<ContentT>(content))
    {}
};

#endif