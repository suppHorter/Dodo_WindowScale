#ifndef __PERIPHERY_
#define __PERIPHERY_

#include "periphery_sensor.h"
#include "periphery_display.h"

static const int SENSOR_COUNT = 1; // 8;

class Periphery {
  private:
    uint8_t sensorPins[SENSOR_COUNT] = {A0};  // [A0, A1, A2, A3, A4, A5, A6, A7];
    Sensor* sensors[SENSOR_COUNT];
    Display display = Display();

  public:
    Periphery() {
      for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i] = new Sensor(sensorPins[i]);
      }
    }

    ~Periphery() {
      for (int i = 0; i < SENSOR_COUNT; i++) {
        delete sensors[i];
      }
    }

    void init() {
      this->display.init();

      for (int i = 0; i < SENSOR_COUNT; i++) {
        this->sensors[i]->init();
      }
    }

    void setSensorsToZero() {
      for (int i = 0; i < SENSOR_COUNT; i++) {
        this->sensors[i]->setZero();
      }
    }

    void reset() {
      for (int i = 0; i < SENSOR_COUNT; i++) {
        this->sensors[i]->reset();
      }
    }

    int readSensors() {
      for (int i = 0; i < SENSOR_COUNT; i++) {
        this->sensors[i]->read();
      }
    }

    void updateDisplay() {
      for (int i = 0; i < SENSOR_COUNT; i++) {
        display.drawSensorValuesInRow(i, SENSOR_COUNT, sensors[i]);
      }
    }
};

#endif
