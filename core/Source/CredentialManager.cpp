// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/CredentialManager.hpp>

bool CredentialManager::TryLogin(std::string const& id,
                                 std::string const& pw,
                                 std::string const& sid,
                                 std::string const& name) noexcept
{
    // TODO
    if (!(id.empty() || pw.empty() || sid.empty() || name.empty()))
    {
        _id   = id;
        _pw   = pw;
        _sid  = sid;
        _name = name;
        return true;
    }
    else
        return false;
}