#include "periphery.h"

Periphery periphery;
bool zeroingRequested = false;
const byte interruptPin = 2; // D2
// todo: decide if display should be updated asynchronous
// #define DISPLAY_UPDATE_INTERVAL 1000

void setup() {
  Serial.begin(9600);
  periphery.init();

  attachInterrupt(digitalPinToInterrupt(interruptPin), requestScaleZeroing, CHANGE);
}

void loop() {
  periphery.readSensors();
  periphery.updateDisplay();

  if (zeroingRequested) {
    zeroingRequested = false;
    Serial.println("Zeroing scale");
    periphery.setSensorsToZero();
  }

  delay(1000);
}

void requestScaleZeroing() {
  zeroingRequested = true;
}