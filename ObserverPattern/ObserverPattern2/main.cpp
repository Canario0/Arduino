#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "ObserverSerial.h"
#include "SensorLM35.h"
using namespace std; //Simplifíca el uso de los flujos de E/S

int main(void){
    const double x = 1.35;
    ObserverSerial* observer = new ObserverSerial();
    SensorLM35* sensor = new SensorLM35();

    observer->attachSubject(sensor);
    sensor->setValue(x);


    return 0;
}