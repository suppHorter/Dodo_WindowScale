#ifndef __PERIPHERY_
#include "periphery_sensor.h"
#include "periphery_display.h"

class Periphery {
  private:
    int SENSOR_COUNT = 1;
    int[SENSOR_COUNT] sensorPins = [A0];  // [A0, A1, A2, A3, A4, A5, A6, A7];
    Sensor[SENSOR_COUNT] sensors;
    Display display = Display();

  public:
    Periphery() {}

    void init() {
      for (int i=0; i<sizeof(this->sensors); i++) {
        this->sensors[i] = Sensor(this->sensorPins[i])
      }
    }

    void reset() {
      for (int i=0; i<sizeof(this->sensors); i++) {
        this->sensors[i]->reset();
      }
    }

    int proceedData() {
      for (int i=0; i<sizeof(this->sensors); i++) {
        this->sensors[i]->read();
        this->display->draw(i, this->sensors[i]->getLastMeassurement());
      }
    }

    int getSensorCount() {
      return this->SENSOR_COUNT;
    }
}
#endif