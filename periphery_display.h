#ifndef __PERIPHERY_DISPLAY_
#define __PERIPHERY_DISPLAY_

#include "TFT_22_ILI9225.h"
#include <../fonts/FreeSans12pt7b.h>

class Display {
  private:
    const uint8_t TFT_RST = 8;
    const uint8_t TFT_RS  = 9;
    const uint8_t TFT_CS  = 10;
    const uint8_t TFT_SDI = 11;
    const uint8_t TFT_CLK = 13;
    const uint8_t TFT_LED = 3;

    const uint8_t widthPixel = 176;
    const uint8_t heightPixel = 220;
    const uint8_t TFT_BRIGHTNESS = 255;

    TFT_22_ILI9225 display;

  public:
    Display() 
      : display(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED, TFT_BRIGHTNESS) {
    }

    void init() {
      this->display.begin();
      this->display.clear();
    }

    void drawSensorValuesOnGrid(int position, int sensorCount, Sensor *sensor) {
      int positionYDelta = this->heightPixel / (sensorCount + 1);
      int y = positionYDelta * position;
      int x = 10;

      this->display.setGFXFont(&FreeSans12pt7b);
      this->display.drawRectangle(0, y, this->widthPixel, positionYDelta * (position + 1), COLOR_BLACK);

      this->display.drawGFXText(x, y, String(sensor->getLastWeight()).c_str(), COLOR_GREEN);

      x = (this->widthPixel / 2) + 10;

      this->display.drawGFXText(x, y, String(sensor->getMaxWeight()).c_str(), COLOR_RED);
    }
};

#endif
