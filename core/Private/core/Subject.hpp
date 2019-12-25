// Copyright (c) 2019 Dear My Professor Authors
// Author: ixora99

#ifndef __H_CORE_SUBJECT__
#define __H_CORE_SUBJECT__

#include <core/Observer.hpp>
#include <unordered_set>

/*
    Subject 클래스는 옵저버 패턴에 사용됩니다.
*/
class Subject
{
  private:
    std::unordered_set<Observer*> _observers;

  public:
    /*
        이 객체에 주어진 observer를 등록합니다.

        Parameters
        observer: 등록할 객체입니다.
    */
    void AddObserver(Observer* observer);

    /*
        주어진 observer가 이 객체에 등록되어있었을 경우, 등록을 해제합니다.

        Parameters
        observer: 등록을 해제할 객체입니다.
    */
    void RemoveObserver(Observer* observer);

  protected:
    /*
        이 객체에 등록된 모든 Observer 객체의 Update 함수를 호출합니다.
    */
    void _NotifyObservers();
};

#endif