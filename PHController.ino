#include <microWire.h>
#include <microLiquidCrystal_I2C.h>
#include <GyverEncoder.h>

#include "Menu.h"
#include "Settings.h"
#include "Pump.h"
#include "PHSensor.h"

#define SCREEN_WIDTH 20
#define DEFAULT_PH 6.6
#define SMALL_ADJUST_BOUND 0.5
#define MILLI_IN_SECOND 1000

LiquidCrystal_I2C lcd(0x3F, SCREEN_WIDTH, 4);
Encoder enc1(12, 11, 10, TYPE2);

Pump* pumpRaisePH = new Pump(1);
Pump* pumpLowerPH = new Pump(2);
PHSensor* pHSensor = new PHSensor(A1);

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
unsigned long int lastReadPH = millis();

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

  unsigned long int currentMills = millis();
  if (currentMills - lastReadPH > settings->delay->getValue() * MILLI_IN_SECOND)
  {
    // Read PH
    lastReadPH = currentMills;
    currPH = pHSensor->read();

    // Change PH in solution if curr PH not between high and low values
    double diff = 0.0;
    bool upPh = false;
    
    double lowPH = settings->phLow->getValue(); 
    if (currPH < lowPH)
    {
      diff = lowPH - currPH;
      upPh = true;
    }

    double highPH = settings->phHigh->getValue();
    if (currPH > highPH)
    {
      diff = currPH - highPH;
    }

    if (diff != 0.0)
    {
      Pump *workingPump = upPh ? pumpRaisePH : pumpLowerPH;
      IntSettingsField* adjust = diff > SMALL_ADJUST_BOUND ? settings->largeAdjust : settings->smallAdjust;
      workingPump->turnOn(adjust->getValue() * MILLI_IN_SECOND);
    }
  }
}