// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_EMAIL__
#define __H_CORE_EMAIL__

#include <cstddef>
#include <string>
#include <vector>

/*
    Email 클래스는 하나의 이메일을 저장하는 모델입니다.
*/
class Email
{
  public:
    using EmailId = size_t;

  public:
    EmailId                  id;
    std::string              subject;
    std::string              from;
    std::string              to;
    std::vector<std::string> cc;
    std::vector<std::string> bcc;
    std::string              content;

  public:
    Email() {}

    template <typename SubjectT = std::string,
              typename FromT    = std::string,
              typename ToT      = std::string,
              typename ContentT = std::string,
              typename CcT      = std::vector<std::string>,
              typename BccT     = std::vector<std::string>>
    Email(SubjectT&& subject,
          FromT&&    from,
          ToT&&      to,
          ContentT&& content,
          CcT&&      cc  = CcT(),
          BccT&      bcc = BccT(),
          EmailId    id  = EmailId(0))
        : id(id),
          subject(std::forward<SubjectT>(subject)),
          from(std::forward<FromT>(from)),
          to(std::forward<ToT>(to)),
          cc(std::forward<CcT>(cc)),
          bcc(std::forward<BccT>(bcc)),
          content(std::forward<ContentT>(content))
    {}
};

#endif