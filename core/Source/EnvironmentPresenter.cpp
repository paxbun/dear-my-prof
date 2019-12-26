// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/CredentialManager.hpp>
#include <core/EnvironmentPresenter.hpp>

void EnvironmentPresenter::Input(std::string const& event_name,
                                 Args const&        args)
{
    auto cred = CredentialManager::GetInstance();
    view()->Output("environment",
                   { { u8"이름", cred->name() }, { u8"학번", cred->sid() } });
}