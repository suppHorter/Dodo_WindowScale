#include "periphery.h"

Periphery periphery;

// todo: decide if display should be updated asynchronous
// #define DISPLAY_UPDATE_INTERVAL 1000

void setup() {
  Serial.begin(9600);
  periphery.init();
}

void loop() {
  periphery.readSensors();
  periphery.updateDisplay();

  delay(1000);
}
