#include "ObserverSerial.h"

#include "HardwareSerial.h"

void ObserverSerial::onReceivedDataFromSubject(const Subject *sub) {
  Serial.println("Value is "); 
  Serial.println(sub->getValue());
}
