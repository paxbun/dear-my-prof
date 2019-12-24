// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/StringTransformFactory.hpp>

std::unordered_map<std::string, StringTransform*>
    StringTransformFactory::_transformMap = {};

StringTransform*
StringTransformFactory::GetTransform(std::string const& transform_name)
{
    if (auto it = _transformMap.find(transform_name); it != _transformMap.end())
        return it->second;
    else
        return nullptr;
}