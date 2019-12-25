// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/Observer.hpp>
#include <core/Subject.hpp>

size_t count = 0;

struct MyObserver : public Observer
{
    virtual void Update() override
    {
        count += 1;
    }
};

struct MySubject : public Subject
{
    void Update()
    {
        _NotifyObservers();
    }
};

int main()
{
    MySubject  subj;
    MyObserver obs1, obs2;

    subj.Update();

    if (count != 0)
        return 1;

    subj.AddObserver(&obs1);
    subj.Update();

    if (count != 1)
        return 1;

    subj.AddObserver(&obs2);
    subj.Update();

    if (count != 3)
        return 1;

    subj.RemoveObserver(&obs1);
    subj.Update();

    if (count != 4)
        return 1;

    subj.RemoveObserver(&obs1);
    subj.Update();

    if (count != 5)
        return 1;

    subj.RemoveObserver(&obs2);
    subj.Update();

    if (count != 5)
        return 1;

    return 0;
}