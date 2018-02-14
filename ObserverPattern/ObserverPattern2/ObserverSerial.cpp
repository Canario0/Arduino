#include "ObserverSerial.h"
#include "SensorLM35.h"
#include <iostream>
using namespace std;
//#include "HardwareSerial.h"

ObserverSerial::ObserverSerial(){
    
}

void ObserverSerial::onReceivedDataFromSubject() {
    printf("Value is "); cout << sensor->getValue()<< endl;//printf("%d",aux->getValue());
}

void ObserverSerial::attachSubject(SensorLM35 * _sensor){
    sensor = _sensor;
    sensor->registerObserver(this);
}
