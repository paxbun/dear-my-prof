// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <bind/Conversions.hpp>
#include <bind/ElectronApp.hpp>

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

        _navigate.Call(
            { _id2win.at(id), Napi::String::New(_env, new_view->viewName()) });
    }
}

void ElectronApp::NewWindow(View* new_view, View* parent_view)
{
    auto it = _view2id.find(new_view);
    if (it == _view2id.end())
    {
        Napi::Object new_win = [&]() {
            auto it = _view2id.find(parent_view);
            if (it == _view2id.end())
                return _newWindow
                    .Call({ Napi::String::New(_env, new_view->viewName()),
                            Conversions::ConvertArgs(
                                _env, new_view->creationArgs()) })
                    .ToObject();
            else
                return _newWindow
                    .Call({ Napi::String::New(_env, new_view->viewName()),
                            Conversions::ConvertArgs(_env,
                                                     new_view->creationArgs()),
                            _id2win.at(it->second) })
                    .ToObject();
        }();

        auto new_id = static_cast<ViewId>(new_win.Get("webContents")
                                              .ToObject()
                                              .Get("id")
                                              .ToNumber()
                                              .Int64Value());

        _id2view.insert(std::make_pair(new_id, new_view));
        _id2win.insert(std::make_pair(new_id, new_win));
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

        _navigate.Call({ _id2win.at(id) });
        _id2win.erase(id);
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
        auto win = _id2win.at(it->second);
        _output.Call({ win,
                       Napi::String::New(_env, response_name),
                       Conversions::ConvertArgs(_env, response_args) });
    }
}

Napi::Object ElectronApp::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "CppImpl", {});

    _ctor = Napi::Persistent(func);
    _ctor.SuppressDestruct();
    exports.Set("CppImpl", func);
    return Napi::Object();
}

ElectronApp::ElectronApp(Napi::CallbackInfo const& info)
    : Napi::ObjectWrap<ElectronApp>(info), _env(info.Env())
{
    Napi::HandleScope scope(_env);

    auto obj = info[0].ToObject();

    _navigate  = obj.Get("navigate").As<Napi::Function>();
    _newWindow = obj.Get("newWindow").As<Napi::Function>();
    _close     = obj.Get("close").As<Napi::Function>();
    _output    = obj.Get("output").As<Napi::Function>();
}

Napi::Value ElectronApp::Start(Napi::CallbackInfo const& info)
{
    App::Start();
    return Napi::Value();
}

Napi::Value ElectronApp::Input(Napi::CallbackInfo const& info)
{
    // TODO
    return Napi::Value();
}
