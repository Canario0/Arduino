#include "SensorLM35.h"
#include "Subject.h"

SensorLM35::SensorLM35():Subject()
{
}

void SensorLM35::setPin(const int _pin)
{
    pin = _pin;
}

int SensorLM35::getPin()
{
    return pin;
}

void SensorLM35::setValue(const double rawADC)
{
    temp = (1.1 * rawADC * 100.0) / 1024.0;
    Subject::_notifyObserver();
}

double SensorLM35::getValue()
{
    return temp;
}


void SensorLM35::run()
{
    setValue(double(analogRead(pin)));
    runned();
}