#include <core/Subject.hpp>

void Subject::AddObserver(Observer* ob)
{
    Subject::_observers.insert(ob);
}

void Subject::RemoveObserver(Observer* ob)
{
    if (Subject::_observers.find(ob) != Subject::_observers.end())
    {
        Subject::_observers.erase(ob);
    }
}

void Subject::_NotifyObservers()
{
    for (auto i : Subject::_observers) { i->Update(); }
}