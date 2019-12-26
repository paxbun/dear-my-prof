// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/CodaStringTransform.hpp>

#include <boost/locale.hpp>

bool CodaStringTransform::_EndsWithCoda(std::string const& input)
{
    auto conv = boost::locale::conv::utf_to_utf<wchar_t>(input);
    auto back = conv.back();

    return back >= 0xAC00 && back <= 0xD7A3 && ((back - 0xAC00) % 28 != 0);
}
