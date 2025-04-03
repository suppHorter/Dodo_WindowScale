#ifndef __PERIPHERY_SENSOR_
class Sensor {
  private:
    int analogPin;
    int meassurement;
    int maxMeassurement;

  public:
    Sensor(int analogPin) {
      this->analogPin = analogPin;
    }

  void init() {
    pinMode(this->analogPin, INPUT);
  }

  int read() {
    this->meassurement = analogRead(this->analogPin);

    if (this->meassurement > this->maxMeassurement) {
      this->maxMeassurement = this->meassurement;
    }

    return analogRead(this->meassurement);
  }

  void reset() {
    this->maxMeassurement = 0;
    this->meassurement = 0;
  }

  int getMaxMeassurement() {
    return this->maxMeassurement;
  }

  int getLastMeassurement() {
    return this->meassurement;
  }
};
#endif