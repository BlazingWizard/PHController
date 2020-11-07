#include <microWire.h>
#include <microLiquidCrystal_I2C.h>
#include <GyverEncoder.h>

#include "Menu.h"
#include "Settings.h"
#include "Pump.h"

#define SCREEN_WIDTH 20
#define DEFAULT_PH 6.6

LiquidCrystal_I2C lcd(0x3F, SCREEN_WIDTH, 4);
Encoder enc1(2, 3, 4, TYPE2);

Pump pumpRaisePH(1);
Pump pumpLowerPH(2);
PHSensor pHSensor(A1);

Menu *menu = NULL;
Settings *settings = NULL;

char *secondScreenStr = new char[SCREEN_WIDTH];
char *thirdScreenStr = new char[SCREEN_WIDTH];

char *modes[] = {
    "Auto",
    "Manual"
};

char *led[] = {
    "On",
    "Off"
};

float currPH = DEFAULT_PH;

void setup()
{
  Serial.begin(38400);
  lcd.init();
  lcd.backlight();

  settings = new Settings(modes, led);
  menu = createMenu();
}

void loop()
{
  enc1.tick();

  if (enc1.isRight())
  {
    menu->next();
  }

  if (enc1.isLeft())
  {
    menu->previos();
  }

  if (enc1.isClick())
  {
    menu->callOnClickAction();
  }

  if (enc1.isRightH())
  {
    menu->callOnHoldRightAction();
  }

  if (enc1.isLeftH())
  {
    menu->callOnHoldLeftAction();
  }

  menu->callOnShowAction();

  // Manage PH
  currPH = pHSensor.read();
  Serial.println(currPH);
}