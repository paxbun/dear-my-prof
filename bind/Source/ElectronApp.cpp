// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <bind/Conversions.hpp>
#include <bind/ElectronApp.hpp>

Napi::FunctionReference ElectronApp::_ctor;

ElectronApp::~ElectronApp()
{
    for (auto const& pair : _id2view) delete pair.second;
}

void ElectronApp::Navigate(View* current_view, View* new_view)
{
    auto it = _view2id.find(current_view);
    if (it != _view2id.end())
    {
        auto id = it->second;
        _view2id.erase(it);
        _view2id.insert(std::make_pair(new_view, id));

        auto it2    = _id2view.find(id);
        it2->second = new_view;
        delete current_view;

        UseApp(new_view);
        new_view->Start();

        _navigate.Call({ Napi::Number::New(_env, id),
                         Napi::String::New(_env, new_view->viewName()) });
    }
}

void ElectronApp::NewWindow(View* new_view, View* parent_view)
{
    auto it = _view2id.find(new_view);
    if (it == _view2id.end())
    {
        Napi::Value new_win;

        UseApp(new_view);
        new_view->Start();

        auto it = _view2id.find(parent_view);
        if (it == _view2id.end())
        {
            new_win = _newWindow.Call(
                { Napi::String::New(_env, new_view->viewName()) });
        }
        else
            new_win = _newWindow.Call(
                { Napi::String::New(_env, new_view->viewName()),
                  Napi::Number::New(_env, it->second) });

        auto new_id = static_cast<ViewId>(new_win.ToNumber().Int64Value());

        _id2view.insert(std::make_pair(new_id, new_view));
        _view2id.insert(std::make_pair(new_view, new_id));
    }
}

void ElectronApp::Close(View* current_view)
{
    auto it = _view2id.find(current_view);
    if (it != _view2id.end())
    {
        auto id = it->second;
        _view2id.erase(it);
        _id2view.erase(id);
        delete current_view;

        _close.Call({ Napi::Number::New(_env, id) });
    }
}

View* ElectronApp::GetViewById(ViewId view_id)
{
    auto it = _id2view.find(view_id);
    if (it != _id2view.end())
        return it->second;
    else
        return nullptr;
}

ElectronApp::ViewId ElectronApp::GetIdByView(View* view)
{
    auto it = _view2id.find(view);
    if (it != _view2id.end())
        return it->second;
    else
        return InvalidId;
}

void ElectronApp::Output(View*              view,
                         std::string const& response_name,
                         Args const&        response_args)
{
    auto it = _view2id.find(view);
    if (it != _view2id.end())
    {
        auto win = Napi::Number::New(_env, it->second);
        _output.Call({ win,
                       Napi::String::New(_env, response_name),
                       Conversions::ConvertArgs(_env, response_args) });
    }
}

Napi::Object ElectronApp::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    Napi::Function func
        = DefineClass(env,
                      "CppImpl",
                      {
                          InstanceMethod("start", &ElectronApp::_Start),
                          InstanceMethod("input", &ElectronApp::_Input),
                      });

    _ctor = Napi::Persistent(func);
    _ctor.SuppressDestruct();
    exports.Set("CppImpl", func);
    return Napi::Object();
}

ElectronApp::ElectronApp(Napi::CallbackInfo const& info)
    : Napi::ObjectWrap<ElectronApp>(info), _env(info.Env())
{
    Napi::HandleScope scope(_env);

    auto obj   = info[0].ToObject();
    _navigate  = Napi::Persistent(obj.Get("navigate").As<Napi::Function>());
    _newWindow = Napi::Persistent(obj.Get("newWindow").As<Napi::Function>());
    _close     = Napi::Persistent(obj.Get("close").As<Napi::Function>());
    _output    = Napi::Persistent(obj.Get("output").As<Napi::Function>());
}

Napi::Value ElectronApp::_Start(Napi::CallbackInfo const& info)
{
    App::Start();
    return Napi::Value();
}

Napi::Value ElectronApp::_Input(Napi::CallbackInfo const& info)
{
    auto id   = static_cast<ViewId>(info[0].ToNumber().Int64Value());
    auto view = _id2view.at(id);

    auto event_name = std::string(info[1].ToString());
    auto event_args = Conversions::ConvertObject(_env, info[2]);

    view->Input(event_name, event_args);
    return Napi::Value();
}
