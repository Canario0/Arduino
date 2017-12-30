#ifndef OBSERVER_H
#define OBSERVER_H
#include "Subject.h"
class Observer {
public:
    void attachSubject(Subject *subject);
    virtual void onReceivedDataFromSubject(const Subject*) = 0;
};
#endif
