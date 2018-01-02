#include "ObserverSerial.h"


Subject* subject;
ObserverSerial* observerSerial;

void setup()
{
    Serial.begin(115200);
    observerSerial = new ObserverSerial();
    subject = new Subject();
    observerSerial->attachSubject(subject);
}

void loop()
{    
    for (int i = 0; i < 10; i++) {
        subject->setVal(i); //this will print data on Serial Monitor
        delay(500);
    }

    Serial.println("Going to unregister Observer");
    subject->unregisterObserver();

    for (int i = 0; i < 10; i++) {
        subject->setVal(i); // we will not be seeing any value on Serial Monitor because we unregister Observer
        delay(500);
    }

    Serial.println("Going to register Observer again");
    subject->registerObserver(observerSerial);
}

