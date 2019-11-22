#include <core/Core.hpp>

#include <napi.h>

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    exports.Set("hello",
                Napi::Function::New(
                    env, [](const Napi::CallbackInfo& info) -> Napi::String {
                        return Napi::String::New(
                            info.Env(), CoreFooFunction("Hello, world!"));
                    }));
    return exports;
}

NODE_API_MODULE(foo, InitAll)