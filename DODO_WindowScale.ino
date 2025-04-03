#include "periphery.h"

Periphery periphery;

void setup() {
  Serial.begin(9600);
  periphery.init();
}

void loop() {
  periphery.readSensors();
  periphery.updateDisplay();
  delay(1000);
}
