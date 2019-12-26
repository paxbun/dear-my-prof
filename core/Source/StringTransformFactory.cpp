// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/ObjectStringTransform.hpp>
#include <core/StringTransformFactory.hpp>
#include <core/SubjectStringTransform.hpp>
#include <core/ThemeStringTransform.hpp>
#include <core/UpperStringTransform.hpp>
#include <core/LowerStringTransform.hpp>
#include <core/PascalStringTransform.hpp>
namespace
{

StringTransform        _default;
ThemeStringTransform   _theme;
SubjectStringTransform _subject;
ObjectStringTransform  _object;
UpperStringTransform   _uppercase;
LowerStringTransform   _lowercase;
PascalStringTransform  _pascalcase;

} // namespace

std::unordered_map<std::string, StringTransform*>
    StringTransformFactory::_transformMap = { {
        { u8"은", &_theme },
        { u8"는", &_theme },
        { u8"이", &_subject },
        { u8"가", &_subject },
        { u8"을", &_object },
        { u8"를", &_object },
		{ u8"upp", &_uppercase},
		{ u8"low", &_lowercase},
		{ u8"pas", &_pascalcase},
    } };

StringTransform*
StringTransformFactory::GetTransform(std::string const& transform_name)
{
    if (auto it = _transformMap.find(transform_name); it != _transformMap.end())
        return it->second;
    else
        return &_default;
}