// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_APP__
#define __H_CORE_APP__

#include <core/View.hpp>

#include <cstddef>
#include <memory>
#include <unordered_map>

/*
    App 인터페이스는 View와 관련된 로직을 추상화합니다. App을 상속하는 클래스는
    창을 표시하고, 열려있는 창의 뷰를 전환하는 등의 작업을 구현하여야합니다.
    App 인터페이스를 구현하는 클래스의 인스턴스는 애플리케이션의 생애주기동안
    하나만 존재하여야합니다.
*/
class App
{
  public:
    /*
        ViewId는 View의 ID를 나타낼 때 사용합니다. 창에 표시 중인 각각의 View는
        고유한 ID를 가지고 있으며, 표시 중이 아닌 View는 ID가 없습니다.
    */
    using ViewId = size_t;

  public:
    /*
        열려있는 창의 뷰를 전환합니다.

        Parameters
        current_view: 현재 열려있는 창에 표시되고 있는 뷰입니다.
        new_view: 새로 표시하고 싶은 뷰입니다. 이 뷰는 다른 창에 표시된
        상태여서는 안됩니다.
    */
    virtual void Navigate(std::weak_ptr<View> current_view,
                          std::weak_ptr<View> new_view)
        = 0;

    /*
        새 창을 열고 주어진 뷰를 엽니다.

        Parameters
        new_view: 새로 표시하고 싶은 뷰입니다. 이 뷰는 다른 창에 표시된
        상태여서는 안됩니다.
        parent_view[optional]: 부모 창으로 등록할 이미 열려있는 창입니다.
    */
    virtual void NewWindow(std::weak_ptr<View> new_view,
                           std::weak_ptr<View> parent_view = nullptr)
        = 0;

    /*
        Parameters
        view_id: 뷰의 ID입니다.

        Return Value
        주어진 ID를 가진 뷰를 반환합니다. 그런 뷰가 없을 경우, nullptr를
        반환합니다.
    */
    virtual std::weak_ptr<View> GetViewById(ViewId view_id) = 0;

    /*
        Parameters
        view: 뷰입니다.

        Return Value
        뷰의 ID를 반환합니다.
    */
    virtual ViewId GetIdByView(std::weak_ptr<View> view) = 0;

    /*
        애플리케이션이 실행되었을 때, 초기 뷰를 설정하기 위해 실행됩니다. 이
        함수는 초기에 표시될 뷰 객체를 만들어 반환하여야 합니다.
    */
    virtual std::shared_ptr<View> Start() = 0;
};

#endif