// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/Args.hpp>
#include <core/CredentialManager.hpp>
#include <core/EnvironmentPresenter.hpp>
#include <core/View.hpp>

void EnvironmentPresenter::Input(std::string const& event_name,
                                 Args const&        args)
{
    auto cred = CredentialManager::GetInstance();

    view()->Output(
        "environment-reply",
        { { u8"이름", cred->name() },
          { u8"학번", cred->sid() },
          { u8"교수님성함",
            view()->creationArgs().at("name").get<std::string>() } });
}