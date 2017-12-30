#include "ObserverTester.h"
#include "HardwareSerial.h"

void ObserverTester::onReceivedDataFromSubject(const Subject *sub) {
    Serial.print("Value is "); Serial.println(sub->getValue());
}
