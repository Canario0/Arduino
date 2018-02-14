#ifndef OBSERVERSERIAL_H
#define OBSERVERSERIAL_H
#include "Observer.h"
#include "SensorLM35.h"
class ObserverSerial : public Observer
{
private:
  SensorLM35 *sensor;

public:
  ObserverSerial();
  void onReceivedDataFromSubject() override;
  void attachSubject(SensorLM35 *);
};
#endif
