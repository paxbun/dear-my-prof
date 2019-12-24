#include <bind/Bind.hpp>
#include <bind/ElectronApp.hpp>

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    ElectronApp::Init(env, exports);
    return exports;
}

NODE_API_MODULE(bind, InitAll)