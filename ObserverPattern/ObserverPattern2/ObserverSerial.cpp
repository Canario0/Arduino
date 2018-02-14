#include "ObserverSerial.h"
#include "SensorLM35.h"
#include "HardwareSerial.h"

ObserverSerial::ObserverSerial(){
    
}

void ObserverSerial::onReceivedDataFromSubject() {
    Serial.print("Value is "); Serial.println(sensor->getValue());
}

void ObserverSerial::attachSubject(SensorLM35 * _sensor){
    sensor = _sensor;
    sensor->registerObserver(this);
}
