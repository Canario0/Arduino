#ifndef OBSERVERSERIAL_H
#define OBSERVERSERIAL_H

#include "Observer.h"
#include "HardwareSerial.h"

class ObserverSerial : public Observer
{
public:
    void testSerial();
    void onReceivedDataFromSubject(const Subject*) override;
};
#endif
