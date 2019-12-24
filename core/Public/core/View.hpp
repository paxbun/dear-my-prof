// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_VIEW__
#define __H_CORE_VIEW__

#include <core/Args.hpp>
#include <core/HasApp.hpp>
#include <core/Presenter.hpp>

#include <map>
#include <string>

/*
    View 클래스는 하나의 뷰를 표현합니다. 주어진 이벤트를 알맞은
    Presenter에게 전달해주는 역할을 합니다.
*/
class View : public HasApp
{
  private:
    std::string                       _viewName;
    std::map<std::string, Presenter*> _bindMap;
    Args                              _creationArgs;

  public:
    std::string const& viewName()
    {
        return _viewName;
    }

    Args const& creationArgs()
    {
        return _creationArgs;
    }

  public:
    /*
        Parameters
        view_name: 사용할 뷰의 이름입니다.
        bind_map: 이벤트와 프레젠터 바인딩 정보입니다.
        creation_args: 뷰를 생성할 때 추가로 넘길 인자입니다.
    */
    View(std::string&&                       view_name,
         std::map<std::string, Presenter*>&& bind_map,
         Args&&                              creation_args = Args())
        : _viewName(view_name), _bindMap(bind_map), _creationArgs(creation_args)
    {}

    virtual ~View() {}

  public:
    /*
        Start는 App이 뷰를 표시하기 시작했을 때 호출합니다. Presenter의 바인딩은
        이 함수의 구현에서 이루어집니다.
    */
    void Start();

    /*
        Input은 뷰에서 이벤트가 발생되었을 때 호출됩니다. 이 함수는 알맞은
        Presenter에게 이벤트를 전달해주어야 합니다.

        Parameters
        event_name: 이벤트의 이름입니다.
        event_args: 이벤트와 함께 전달받은 인자입니다.
    */
    void Input(std::string const& event_name, Args const& event_args = Args());

    /*
        뷰에게 답변을 전달합니다.

        Parameters
        response_name: 답변의 이름입니다.
        response_args: 답변과 함께 전달할 인자입니다.
    */
    void Output(std::string const& response_name,
                Args const&        response_args = Args());
};

#endif