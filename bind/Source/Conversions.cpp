// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <bind/Conversions.hpp>

Napi::Value Conversions::ConvertArgs(Napi::Env env, Args const& args)
{
    using value_t = nlohmann::json::value_t;

    switch (args.type())
    {
    case value_t::object: {
        auto rtn = Napi::Object::New(env);

        for (auto it = args.begin(); it != args.end(); ++it)
            rtn.Set(it.key(), ConvertArgs(env, it.value()));

        return rtn;
    }
    case value_t::array: {
        auto rtn = Napi::Array::New(env, args.size());

        size_t idx = 0;
        for (auto const& elem : args) rtn.Set(idx++, ConvertArgs(env, elem));

        return rtn;
    }
    case value_t::string: {
        return Napi::String::New(env, args.get<std::string>());
    }
    case value_t::boolean: {
        return Napi::Boolean::New(env, args.get<bool>());
    }
    case value_t::number_integer: {
        return Napi::Number::From(env, args.get<int>());
    }
    case value_t::number_unsigned: {
        return Napi::Number::From(env, args.get<unsigned>());
    }
    case value_t::number_float: {
        return Napi::Number::From(env, args.get<double>());
    }
    case value_t::discarded:
    case value_t::null:
    default: {
        return Napi::Object::New(env);
    }
    }
}

Args Conversions::ConvertObject(Napi::Env env, Napi::Value val)
{
    Napi::HandleScope scope(env);

    switch (val.Type())
    {
    case napi_boolean: {
        return Args(val.ToBoolean().Value());
    }
    case napi_number: {
        return Args(val.ToNumber().Int64Value());
    }
    case napi_string: {
        return Args(val.ToString().Utf8Value());
    }
    case napi_object: {
        if (val.IsArray())
        {
            auto array = Napi::Array(env, val);
            auto rtn   = Args::array();

            for (size_t i = 0, l = array.Length(); i < l; ++i)
                rtn.push_back(ConvertObject(env, array.Get(i)));

            return rtn;
        }
        else
        {
            auto obj   = val.ToObject();
            auto rtn   = Args::object();
            auto names = obj.GetPropertyNames();

            for (size_t i = 0, l = names.Length(); i < l; ++i)
            {
                auto idx             = Napi::Value(names[i]).ToString();
                rtn[idx.Utf8Value()] = ConvertObject(env, obj.Get(idx));
            }

            return rtn;
        }
    }
    case napi_symbol:
    case napi_function:
    case napi_external:
    case napi_undefined:
    case napi_null:
    default: {
        return Args();
    }
    }
}
