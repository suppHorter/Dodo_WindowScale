#ifndef __PERIPHERY_DISPLAY_
#include "TFT_22_ILI9225.h"
#include <../fonts/FreeSans12pt7b.h>

class Display {
  private:
    int TFT_RST = 8;
    int TFT_RS  = 9;
    int TFT_CS  = 10;
    int TFT_SDI = 11;
    int TFT_CLK = 13;
    int TFT_LED = 3;

    int widthPixel = 176;
    int heightPixel = 220;

    TFT_22_ILI9225 display;

  public:
    Display() {
      this->display = TFT_22_ILI9225(this->TFT_RST, this->TFT_RS, this->TFT_CS, this->TFT_SDI, this->TFT_CLK, this->TFT_LED, this->TFT_BRIGHTNESS);
    }

    void init() {
      this->display.begin();
      this->display.clear();
    }

    void draw(int position, Sensor sensor) {
      int positionYDelta = this->height / (sensor->getSensorCount() + 1);
      int y = positionYDelta * position;
      int x = 10;

      this->display->drawRectangle(x, y, x, positionYDelta * (position + 1), COLOR_BLACK)

      this->display->setGFXFont(&FreeSans12pt7b);
      this->display->drawGFXText(x, y, sensor->getLastMeassurement(), COLOR_GREEN);
    }
}
#endif