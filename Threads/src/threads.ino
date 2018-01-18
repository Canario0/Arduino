
#include "Thread.h"
#include "ThreadController.h"
#include <math.h>
class SensorThread : public Thread
{
  public:
    double temp = 0;
    int pin;

    void run()
    {
        setTemperature(analogRead(pin));
        runned();
    }

    void setTemperature(int rawADC)
    {
        temp = (5.0 * rawADC * 100.0) / 1023.0;
    }

    double getTemperature()
    {
        return temp;
    }
};

SensorThread sensor = SensorThread();
ThreadController controller = ThreadController();

void setup()
{
    sensor.pin = A0;
    sensor.setInterval(11);

    controller.add(&sensor);
    Serial.begin(9600);

    while (!Serial)
    {
        ;
    }
}

void loop()
{
    controller.run();
    Serial.print("I read: ");
    Serial.println(sensor.getTemperature());
    delay(1000);
}