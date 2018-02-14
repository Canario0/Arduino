#include "ObserverSerial.h"
#include "SensorLM35.h"
#include "ThreadController.h"

ObserverSerial* observer = new ObserverSerial();
SensorLM35* sensor = new SensorLM35();
ThreadController controller;

void setup()
{
    analogReference(INTERNAL);
    Serial.begin(9600);
    while (!Serial)
    {
        ;
    }
    observer->attachSubject(sensor);
    sensor->setPin(A0);
    sensor->setInterval(1000);

    controller.add(sensor);
}

void loop()
{
    controller.run();
}