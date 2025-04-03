#ifndef __PERIPHERY_SENSOR_
#define __PERIPHERY_SENSOR_

#include <EEPROM.h>

class Sensor {
  private:
    int analogPin;
    int zeroValueOffset = 0;
    int eepromAddress;

    float weight;
    float maxWeight;

  public:
    Sensor(int analogPin) {
      this->analogPin = analogPin;
      this->eepromAddress = analogPin - A0;
    }

  void init() {
    pinMode(this->analogPin, INPUT);
    // Todo: discuss if this should be set every time the arduino starts via:
    // this->zeroValueOffset = analogRead(this->analogPin);
    //  => EEPROM has limited writes (unlimited reads)
    this->zeroValueOffset = EEPROM.read(this->eepromAddress);
  }

  void read() {
    this->weight = Sensor::parseVoltageToKilogram(analogRead(this->analogPin) + zeroValueOffset);

    if (this->weight > this->maxWeight) {
      this->maxWeight = this->weight;
    }
  }

  void setZero() {
    this->zeroValueOffset = analogRead(this->analogPin);
    EEPROM.write(this->eepromAddress, this->zeroValueOffset);
    EEPROM.commit();
  }

  static float parseVoltageToKilogram(int _weight) {
    if (_weight <= 0) {
      return 0.0f;
    }

    return 0.0f; //(_weight / 1023.0) * 5.0;
  }

  void reset() {
    this->maxWeight = 0;
    this->weight = 0;
  }

  int getMaxWeight() {
    return this->maxWeight;
  }

  int getLastWeight() {
    return this->weight;
  }
};

#endif
