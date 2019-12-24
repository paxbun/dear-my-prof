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
    View 클래스는 하나의 뷰를 표현합니다. 주어진 이벤트를 알맞은 Presenter에게
    전달해주는 역할을 합니다.
*/
class View : public HasApp
{
  private:
    std::string                       _viewName;
    std::map<std::string, Presenter*> _bindMap;
    Args                              _creationArgs;

  public:
    /*
        Parameters
        view_name: 사용할 뷰의 이름입니다.
        creation_args: 뷰를 생성할 때 추가로 넘길 인자입니다.
    */
    View(std::string const& view_name, Args const& creation_args)
        : _viewName(view_name), _creationArgs(creation_args)
    {}

    virtual ~View() {}

  public:
    /*
        Input은 뷰에서 이벤트가 발생되었을 때 호출됩니다. 이 함수는 알맞은
        Presenter에게 이벤트를 전달해주어야 합니다.

        Parameters
        event_name: 이벤트의 이름입니다.
        event_args: 이벤트와 함께 전달받은 인자입니다.
    */
    void Input(std::string const& event_name, Args const& event_args);

    /*
        주어진 이벤트를 해당 Presenter에 바인딩합니다.

        Parameters
        event_name: 이벤트의 이름입니다.
        presenter: 바인딩할 Presenter입니다.
    */
    void Bind(std::string const& event_name, Presenter* presenter);

    /*
        뷰에게 답변을 전달합니다.

        Parameters
        response_name: 답변의 이름입니다.
        response_args: 답변과 함께 전달할 인자입니다.
    */
    void Output(std::string const& response_name, Args const& response_args);
};

#endif