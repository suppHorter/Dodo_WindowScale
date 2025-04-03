#include "periphery.h"

Periphery periphery;

void setup() {
  Serial.begin(9600);
}

void loop() {
  periphery.proceedData();
  delay(1000);
}
