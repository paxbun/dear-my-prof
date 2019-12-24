// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/StringTransform.hpp>

#include <boost/locale.hpp>

bool CodaStringTransform::_EndsWithCoda(std::string const& input)
{
    auto conv = boost::locale::utf_to_utf<wchar_t>(input);
    return (conv.back() - 0xAC00) % 28;
}
