// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_HAS_APP__
#define __H_CORE_HAS_APP__

class App;

/*
    HasApp 클래스는 App을 멤버 변수로 가지고, getter를 제공하는 클래스입니다.
    View, Presenter 등 App 객체에 접근해야 하는 클래스는 이 클래스를
    상속하여야 합니다.
*/
class HasApp
{
    /*
        App 클래스는 HasApp 클래스의 _app 멤버 변수에 접근할 수 있습니다.
    */
    friend App;

  private:
    App* _app;

  public:
    /*
        현재 애플리케이션의 App 객체를 반환합니다.
    */
    App* app()
    {
        return _app;
    }

  public:
    HasApp() : _app(nullptr) {}
};

#endif