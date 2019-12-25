// Copyright (c) 2019 Dear My Professor Authors
// Author: ixora99

#include <core/Subject.hpp>

void Subject::AddObserver(Observer* ob)
{
    if (ob)
        _observers.insert(ob);
}

void Subject::RemoveObserver(Observer* ob)
{
    if (ob)
    {
        if (auto it = _observers.find(ob); it != _observers.end())
            _observers.erase(it);
    }
}

void Subject::_NotifyObservers()
{
    for (auto i : _observers) i->Update();
}