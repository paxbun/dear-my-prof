// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/App.hpp>
#include <core/Email.hpp>
#include <core/EmailList.hpp>
#include <core/HasApp.hpp>
#include <core/SendEmailPresenter.hpp>
#include <core/View.hpp>

Address SendEmailPresenter::_Args2Addr(Args const& args)
{
    if (args.is_string())
    {
        auto to_addr = args.get<std::string>();
        if (to_addr.empty())
            throw std::invalid_argument("Not an address.");

        return Address(std::move(to_addr));
    }
    else if (args.is_array() && args.size() == 2)
    {
        auto to_addr = args.at(0).get<std::string>();
        auto to_name = args.at(1).get<std::string>();

        if (to_addr.empty() || to_name.empty())
            throw std::invalid_argument("Not an address.");

        return Address(std::move(to_addr), std::move(to_name));
    }
    else
        throw std::invalid_argument("Not an address.");
}

std::vector<Address> SendEmailPresenter::_Args2Addrs(Args const& args)
{
    if (args.is_array())
    {
        std::vector<Address> rtn;
        rtn.reserve(args.size());
        for (auto& arg : args) rtn.push_back(_Args2Addr(arg));
        return rtn;
    }
    else
        throw std::invalid_argument("Not an address collection.");
}

void SendEmailPresenter::Input(std::string const& event_name, Args const& args)
{
    if (_TrySend(args))
        app()->Close(view());
    else
        view()->Output("send-email-failed");
}

bool SendEmailPresenter::_TrySend(Args const& args)
{
    try
    {
        auto subject_it = args.find("subject");
        auto to_it      = args.find("to");
        auto bcc_it     = args.find("bcc");
        auto cc_it      = args.find("cc");
        auto content_it = args.find("content");

        if (subject_it != args.end() && to_it != args.end()
            && content_it != args.end())
        {
            auto subject = subject_it->get<std::string>();
            auto content = content_it->get<std::string>();
            if (subject.empty() || content.empty())
                return false;

            Address              to  = _Args2Addr(*to_it);
            std::vector<Address> cc  = _Args2Addrs(*cc_it),
                                 bcc = _Args2Addrs(*bcc_it);

            return EmailList::GetInstance()->TrySend(Email(std::move(subject),
                                                           Address(),
                                                           std::move(to),
                                                           std::move(content),
                                                           std::move(cc),
                                                           std::move(bcc)));
        }
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}
