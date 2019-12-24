// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_PRESENTER__
#define __H_CORE_PRESENTER__

#include <core/Args.hpp>

#include <string>

/*
    View 클래스는 하나의 프레젠터를 표현합니다. 주어진 데이터를 알맞은 서식으로
    가공하는 역할을 합니다.
*/
class Presenter
{
  private:
    View* _view;

  protected:
    /*
        이 프리젠터에 바인딩된 View를 반환합니다.
    */
    View* view()
    {
        return _view;
    }

  public:
    /*
        Parameters
        view: Presenter에 바인딩될 뷰입니다.
    */
    Presenter(View* view) : _view(view) {}

  public:
    /*
        이 함수는 View 객체에 의해 뷰에서 이 프리젠터가 바인딩된 이벤트가
        발생되었을 때 호출됩니다.

        Parameters
        event_name: 이벤트의 이름입니다.
        event_args: 이벤트와 함께 전달받은 인자입니다.
    */
    virtual void Input(std::string const& event_name, Args const& args) = 0;
};

#endif