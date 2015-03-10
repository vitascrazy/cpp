#include "subject.h"

Subject::Subject()
{
}

void Subject::init(IObserver* observer)
{
    observers.push_back(observer);
}

void Subject::notifyAllObservers()
{
    for (auto obs: observers)
        obs->update();
}

void Subject::notifyAllScenes()
{
    for (auto obs: observers)
        obs->updateScene();
}
