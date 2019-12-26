// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#ifndef __H_CORE_ENVIRONMENT_PRESENTER__
#define __H_CORE_ENVIRONMENT_PRESENTER__

#include <core/Presenter.hpp>

/*
    EnvironmentPresenter 클래스는 학번, 이름 등 애플리케이션이 자동으로 채워주는
    매개변수를 반환하는 프레젠터입니다.
*/
class EnvironmentPresenter : public Presenter
{
  public:
    virtual void Input(std::string const& event_name,
                       Args const&        args) override;
};

#endif