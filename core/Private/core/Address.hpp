// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_ADDRESS__
#define __H_CORE_ADDRESS__

#include <string>
#include <type_traits>

/*
    Address 클래스는 이메일 주소를 담기 위한 자료형입니다. 이메일을 보낼 때
    사용자 이름이 함께 처리되는 경우를 위해 사용합니다.
*/
class Address
{
  public:
    std::string email;
    std::string realName;

  public:
    template <
        typename EmailT       = std::string,
        typename RealNameT    = std::string,
        std::enable_if_t<!std::is_same_v<std::remove_const_t<
                                             std::remove_reference_t<EmailT>>,
                                         Address>,
                         int> = 0>
    Address(EmailT&& email = EmailT(), RealNameT&& realName = RealNameT())
        : email(std::forward<EmailT>(email)),
          realName(std::forward<RealNameT>(realName))
    {}
};

#endif