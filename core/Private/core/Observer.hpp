// Copyright (c) 2019 Dear My Professor Authors
// Author: ixora99

#ifndef __H_CORE_OBSERVER__
#define __H_CORE_OBSERVER__

/*
    Observer 인터페이스는 옵저버 패턴에 사용됩니다.
*/
class Observer
{
  public:
    /*
        Update는 이 객체가 등록된 Subject 내부의 값이 변경되었을 때 호출됩니다.
    */
    virtual void Update() = 0;
};

#endif