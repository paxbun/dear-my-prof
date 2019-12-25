#ifndef __SUBJECT__
#define __SUBJECT__

#include <core/Observer.hpp>
#include <unordered_set>

class Subject : public Observer
{

  private:
    std::unordered_set<Observer*> _observers;

  public:
    void AddObserver(Observer*);
    void RemoveObserver(Observer*);

  protected:
    void _NotifyObservers();


};

#endif