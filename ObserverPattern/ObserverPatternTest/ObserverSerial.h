#ifndef OBSERVERSERIAL_H
#define OBSERVERSERIAL_H

#include "Observer.h"

class ObserverSerial : public Observer
{
public:
    void onReceivedDataFromSubject(const Subject*) override;
};
#endif
