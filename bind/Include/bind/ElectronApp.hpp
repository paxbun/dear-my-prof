// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_BIND_ELECTRON_APP__
#define __H_BIND_ELECTRON_APP__

#include <core/App.hpp>

#include <napi.h>

#include <unordered_map>

/*
    ElectronApp 클래스는 App 인터페이스를 구현합니다.
*/
class ElectronApp : public App, public Napi::ObjectWrap<ElectronApp>
{
  private:
    static Napi::FunctionReference _ctor;

  public:
    /*
        모듈 초기화 단계에서 ElectronApp을 자바스크립트로 노출하기 위해 사용하는
        함수입니다.

        Parameters
        env: 자바스크립트 환경 핸들입니다.
        export: 익스포트 심볼을 담고 있는 객체입니다.

        Return Value
        export를 반환합니다.
    */
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

  public:
    virtual void   Navigate(View* curent_view, View* new_view) override;
    virtual void   NewWindow(View* new_view, View* parent_view) override;
    virtual void   Close(View* current_view) override;
    virtual View*  GetViewById(ViewId view_id) override;
    virtual ViewId GetIdByView(View* view) override;
    virtual void   Output(View*              view,
                          std::string const& response_name,
                          Args const&        response_args) override;

  private:
    Napi::FunctionReference _navigate;
    Napi::FunctionReference _newWindow;
    Napi::FunctionReference _close;
    Napi::FunctionReference _output;

    Napi::Env _env;

    std::unordered_map<ViewId, View*> _id2view;
    std::unordered_map<View*, ViewId> _view2id;

  public:
    ElectronApp(Napi::CallbackInfo const& info);

    virtual ~ElectronApp();

  private:
    /*
        자바스크립트에서 App::Start를 호출하기 위한 함수입니다.
    */
    Napi::Value _Start(Napi::CallbackInfo const& info);

    /*
        자바스크립트에서 이벤트가 발생했을 때 호출하는 함수입니다.
    */
    Napi::Value _Input(Napi::CallbackInfo const& info);
};

#endif