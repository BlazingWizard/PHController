#include <microWire.h>
#include <microLiquidCrystal_I2C.h>
#include <GyverEncoder.h>

#include "Menu.h"
#include "Settings.h"

#define SCREEN_WIDTH 20

LiquidCrystal_I2C lcd(0x3F, SCREEN_WIDTH, 4);
Encoder enc1(2, 3, 4, TYPE2);

Menu *menu = NULL;
Settings *settings = NULL;
char *settingsStr = new char[SCREEN_WIDTH];

void setup()
{
  Serial.begin(38400);
  lcd.init();
  lcd.backlight();

  settings = new Settings();
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
}

#pragma region MainMenu
void onShowMain()
{
  lcd.clear();
  lcd.printstr("Main Screen");
}

void onShowSettings()
{
  lcd.clear();
  lcd.printstr("Settings");
}

void onShowPhCalibration()
{
  lcd.clear();
  lcd.printstr("Ph Calibration");
}

void onShowTestPump()
{
  lcd.clear();
  lcd.printstr("Test Pump");
}
#pragma endregion MainMenu

#pragma region SettingsSubmenu
#pragma region Mode
void onShowSetMode()
{
  lcd.clear();
  lcd.printstr("Mode");

  lcd.setCursor(0, 1);
  settings->mode->getDisplayValue(settingsStr);
  lcd.printstr(settingsStr);
}

void onHoldRightMode()
{
  settings->mode->inc();
  onShowSetMode();
}

void onHoldLeftMode()
{
  settings->mode->dec();
  onShowSetMode();
}
#pragma endregion Mode

#pragma region PhLow
void onShowSetPhLow()
{
  lcd.clear();
  lcd.printstr("PhLow");

  lcd.setCursor(0, 1);
  settings->phLow->getDisplayValue(settingsStr);
  lcd.printstr(settingsStr);
}

void onHoldRightPhLow()
{
  settings->phLow->inc();
  onShowSetPhLow();
}

void onHoldLeftPhLow()
{
  settings->phLow->dec();
  onShowSetPhLow();
}
#pragma endregion PhLow

#pragma region PhHigh
void onShowSetPhHigh()
{
  lcd.clear();
  lcd.printstr("PhHigh");

  lcd.setCursor(0, 1);
  settings->phHigh->getDisplayValue(settingsStr);
  lcd.printstr(settingsStr);
}

void onHoldRightPhHigh()
{
  settings->phHigh->inc();
  onShowSetPhHigh();
}

void onHoldLeftPhHigh()
{
  settings->phHigh->dec();
  onShowSetPhHigh();
}
#pragma endregion PhHigh

#pragma region SmallAdjust
void onShowSetSmallAdjust()
{
  lcd.clear();
  lcd.printstr("Small Adjust");

  lcd.setCursor(0, 1);
  settings->smallAdjust->getDisplayValue(settingsStr);
  lcd.printstr(settingsStr);
}

void onHoldRightSmallAdjust()
{
  settings->smallAdjust->inc();
  onShowSetSmallAdjust();
}

void onHoldLeftSmallAdjust()
{
  settings->smallAdjust->dec();
  onShowSetSmallAdjust();
}
#pragma endregion SmallAdjust

#pragma region LargeAdjust
void onShowSetLargeAdjust()
{
  lcd.clear();
  lcd.printstr("Large Adjust");

  lcd.setCursor(0, 1);
  settings->largeAdjust->getDisplayValue(settingsStr);
  lcd.printstr(settingsStr);
}

void onHoldRightLargeAdjust()
{
  settings->largeAdjust->inc();
  onShowSetLargeAdjust();
}

void onHoldLeftLargeAdjust()
{
  settings->largeAdjust->dec();
  onShowSetLargeAdjust();
}
#pragma endregion LargeAdjust

#pragma region Delay
void onShowSetDelay()
{
  lcd.clear();
  lcd.printstr("Delay");

  lcd.setCursor(0, 1);
  settings->delay->getDisplayValue(settingsStr);
  lcd.printstr(settingsStr);
}

void onHoldRightDelay()
{
  settings->delay->inc();
  onShowSetDelay();
}

void onHoldLeftDelay()
{
  settings->delay->dec();
  onShowSetDelay();
}
#pragma endregion Delay

#pragma region LED
void onShowSetLED()
{
  lcd.clear();
  lcd.printstr("LED");

  lcd.setCursor(0, 1);
  settings->LED->getDisplayValue(settingsStr);
  lcd.printstr(settingsStr);
}

void onHoldRightLED()
{
  settings->LED->inc();
  onShowSetLED();
}

void onHoldLeftLED()
{
  settings->LED->dec();
  onShowSetLED();
}
#pragma endregion LED

#pragma region ResetAll
void onShowResetAll()
{
  lcd.clear();
  lcd.printstr("Reset All");
}
#pragma endregion ResetAll
#pragma endregion SettingsSubmenu

#pragma region PhCalibrationSubmenu
void onShowCalibratePh4()
{
  lcd.clear();
  lcd.printstr("Calibrate Ph4");
}

void onShowCalibratePh7()
{
  lcd.clear();
  lcd.printstr("Calibrate Ph7");
}

void onShowCalibratePh10()
{
  lcd.clear();
  lcd.printstr("Calibrate Ph10");
}
#pragma endregion PhCalibrationSubmenu

#pragma region TestPumpSubmenu
void onShowPump1()
{
  lcd.clear();
  lcd.printstr("Pump1");
}

void onShowPump2()
{
  lcd.clear();
  lcd.printstr("Pump2");
}
#pragma endregion TestPumpSubmenu

Menu *createMenu()
{
  Menu *mainMenu = new Menu();

  // Create elemnts main menu
  MenuElement *mainScreen = new MenuElement(onShowMain);
  MenuElement *settings = new MenuElement(onShowSettings);
  settings->subMenu = new Menu();
  MenuElement *phCalibration = new MenuElement(onShowPhCalibration);
  phCalibration->subMenu = new Menu();
  MenuElement *testPump = new MenuElement(onShowTestPump);
  testPump->subMenu = new Menu();

  // Create settings submenu
  Menu *settingsSubmenu = settings->subMenu;
  settingsSubmenu->add(new MenuElement(onShowSetMode, onHoldRightMode, onHoldLeftMode));
  settingsSubmenu->add(new MenuElement(onShowSetPhLow, onHoldRightPhLow, onHoldLeftPhLow));
  settingsSubmenu->add(new MenuElement(onShowSetPhHigh, onHoldRightPhHigh, onHoldLeftPhHigh));
  settingsSubmenu->add(new MenuElement(onShowSetSmallAdjust, onHoldRightSmallAdjust, onHoldLeftSmallAdjust));
  settingsSubmenu->add(new MenuElement(onShowSetLargeAdjust, onHoldRightLargeAdjust, onHoldLeftLargeAdjust));
  settingsSubmenu->add(new MenuElement(onShowSetDelay, onHoldRightDelay, onHoldLeftDelay));
  settingsSubmenu->add(new MenuElement(onShowSetLED, onHoldRightLED, onHoldLeftLED));
  settingsSubmenu->add(new MenuElement(onShowResetAll));

  // Create phCalibration submenu
  Menu *phCalibrationSubmenu = phCalibration->subMenu;
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh4));
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh7));
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh10));

  // Create testPump submenu
  Menu *testPumpSubmenu = testPump->subMenu;
  testPumpSubmenu->add(new MenuElement(onShowPump1));
  testPumpSubmenu->add(new MenuElement(onShowPump2));

  // Fill main menu
  mainMenu->add(mainScreen);
  mainMenu->add(settings);
  mainMenu->add(phCalibration);
  mainMenu->add(testPump);

  return mainMenu;
}