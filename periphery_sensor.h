#ifndef __PERIPHERY_SENSOR_
#define __PERIPHERY_SENSOR_

class Sensor {
  private:
    int analogPin;
    float weight;
    float maxWeight;

  public:
    Sensor(int analogPin) {
      this->analogPin = analogPin;
    }

  void init() {
    pinMode(this->analogPin, INPUT);
  }

  void read() {
    this->weight = Sensor::parseVoltageToKilogram(analogRead(this->analogPin));

    if (this->weight > this->maxWeight) {
      this->maxWeight = this->weight;
    }
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
