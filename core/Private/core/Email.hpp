// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_EMAIL__
#define __H_CORE_EMAIL__

#include <core/Address.hpp>

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
    EmailId              id;
    std::string          subject;
    Address              from;
    Address              to;
    std::vector<Address> cc;
    std::vector<Address> bcc;
    std::string          content;

  public:
    template <typename SubjectT = std::string,
              typename FromT    = Address,
              typename ToT      = Address,
              typename ContentT = std::string,
              typename CcT      = std::vector<Address>,
              typename BccT     = std::vector<Address>>
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