#ifndef SENSORLM35_H
#define SENSORLM35_H
#include "Subject.h"
//#include "Thread.h"

class SensorLM35 : public Subject
{
  private:
    int pin;
    double temp=0.0;
    
    

  public:
    SensorLM35();
    void setPin(const int);
    int getPin();
    void setValue(const double);
    double getValue();
    //void run();
};

#endif