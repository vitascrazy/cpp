#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "IObserver.h"

class Subject
{
public:
    Subject();
    void init(IObserver*);
    void notifyAllObservers();
    void notifyAllScenes();

private:
    std::vector<IObserver*> observers;
};

#endif // SUBJECT_H
