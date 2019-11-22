// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_INTERNAL__
#define __H_CORE_INTERNAL__

#include <string>

inline std::string CoreFooFunctionInternal(std::string const& str)
{
    return std::string(str.rbegin(), str.rend());
}

#endif