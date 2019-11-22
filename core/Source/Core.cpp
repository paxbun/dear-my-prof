// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/Core.hpp>
#include <core/Internal.hpp>

#include <string>

std::string CoreFooFunction(std::string const& str)
{
    return CoreFooFunctionInternal(str);
}