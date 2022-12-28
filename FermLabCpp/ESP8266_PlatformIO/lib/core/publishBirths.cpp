#include <Arduino.h>
#include "publishBirths.h"

void publishBirthCertificates() {
    publishNodeBirth();
    publishDeviceBirth();
    return;
}

void publishNodeBirth() {
    Serial.println("publish Node Birth");
    return;
}

void publishDeviceBirth() {
    Serial.println("publish Device Birth");
    return;
}