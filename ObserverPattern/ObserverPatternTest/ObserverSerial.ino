#include "ObserverSerial.h"

void ObserverSerial::testSerial() {
  Serial.println("Test serial");
}

void ObserverSerial::onReceivedDataFromSubject(const Subject *sub) {
  Serial.println("Value is "); 
  Serial.println(sub->getValue());
}
