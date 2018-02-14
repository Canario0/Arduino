#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
  public:
    virtual void onReceivedDataFromSubject() = 0;
};
#endif