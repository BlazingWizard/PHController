#include <microWire.h>
#include <microLiquidCrystal_I2C.h>
#include <GyverEncoder.h>

#include "Menu.h"
#include "Settings.h"

LiquidCrystal_I2C lcd(0x3F, 20, 4);
Encoder enc1(2, 3, 4, TYPE2);

Menu *menu = NULL;
Settings *settings = NULL;
char* settingsStr = new char[20];

void setup() {
  Serial.begin(38400);
  lcd.init();
  lcd.backlight();

  settings = new Settings();
  menu = createMenu();
}

void loop() {
  enc1.tick();

  if (enc1.isRight()) {
    menu->next();
  }

  if (enc1.isLeft()) {
    menu->previos();
  }

  if (enc1.isClick()){
     menu->callOnClickAction();
  }

  if (enc1.isRightH()){
    menu->callOnHoldRightAction();
  }

  if (enc1.isLeftH()){
    menu->callOnHoldLeftAction();
  }

  menu->callOnShowAction();
}

#pragma region MainMenu
void onShowMain(){
  lcd.clear();
  lcd.printstr("Main Screen");
}

void onShowSettings(){
  lcd.clear();
  lcd.printstr("Settings");
}

void onShowPhCalibration() {
  lcd.clear();
  lcd.printstr("Ph Calibration");
}

void onShowTestPump(){
  lcd.clear();
  lcd.printstr("Test Pump");
}
#pragma endregion MainMenu

#pragma region SettingsSubmenu
void onShowSetMode(){
  lcd.clear();
  lcd.printstr("Mode");

  lcd.setCursor (0,1);
  settings->mode->getDisplayValue(settingsStr);
  lcd.printstr(settingsStr);
}

void onHoldRightMode(){
  int mode = settings->mode->getValue();
  mode++;
  settings->mode->setValue(mode);
  onShowSetMode();
}

void onHoldLeftMode(){
  int mode = settings->mode->getValue();
  mode--;
  settings->mode->setValue(mode);
  onShowSetMode();
}


void onShowSetPhLow(){
  lcd.clear();
  lcd.printstr("PhLow");
}

void onShowSetPhHigh(){
  lcd.clear();
  lcd.printstr("PhHigh");
}

void onShowSetSmallAdjust(){
  lcd.clear();
  lcd.printstr("Small Adjust");
}

void onShowSetLargeAdjust(){
  lcd.clear();
  lcd.printstr("Large Adjust");
}

void onShowSetDelay(){
  lcd.clear();
  lcd.printstr("Delay");
}

void onShowSetLED(){
  lcd.clear();
  lcd.printstr("LED");
}

void onShowResetAll(){
  lcd.clear();
  lcd.printstr("Reset All");
}
#pragma endregion SettingsSubmenu

#pragma region PhCalibrationSubmenu
void onShowCalibratePh4(){
  lcd.clear();
  lcd.printstr("Calibrate Ph4");
}

void onShowCalibratePh7(){
  lcd.clear();
  lcd.printstr("Calibrate Ph7");
}

void onShowCalibratePh10(){
  lcd.clear();
  lcd.printstr("Calibrate Ph10");
}
#pragma endregion PhCalibrationSubmenu

#pragma region TestPumpSubmenu
void onShowPump1(){
  lcd.clear();
  lcd.printstr("Pump1");
}

void onShowPump2(){
  lcd.clear();
  lcd.printstr("Pump2");
}
#pragma endregion TestPumpSubmenu

Menu* createMenu(){
  Menu* mainMenu = new Menu();
  
  // Create elemnts main menu
  MenuElement *mainScreen = new MenuElement(onShowMain);
  MenuElement *settings = new MenuElement(onShowSettings);
  settings->subMenu = new Menu();
  MenuElement *phCalibration = new MenuElement(onShowPhCalibration);
  phCalibration->subMenu = new Menu();
  MenuElement *testPump = new MenuElement(onShowTestPump);
  testPump->subMenu = new Menu();

  // Create settings submenu
  Menu* settingsSubmenu = settings->subMenu;
  settingsSubmenu->add(new MenuElement(onShowSetMode, onHoldRightMode, onHoldLeftMode));
  settingsSubmenu->add(new MenuElement(onShowSetPhLow));
  settingsSubmenu->add(new MenuElement(onShowSetPhHigh));
  settingsSubmenu->add(new MenuElement(onShowSetSmallAdjust));
  settingsSubmenu->add(new MenuElement(onShowSetLargeAdjust));
  settingsSubmenu->add(new MenuElement(onShowSetDelay));
  settingsSubmenu->add(new MenuElement(onShowSetLED));
  settingsSubmenu->add(new MenuElement(onShowResetAll));

  // Create phCalibration submenu
  Menu* phCalibrationSubmenu = phCalibration->subMenu;
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh4));
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh7));
  phCalibrationSubmenu->add(new MenuElement(onShowCalibratePh10));

  // Create testPump submenu
  Menu* testPumpSubmenu = testPump->subMenu;
  testPumpSubmenu->add(new MenuElement(onShowPump1));
  testPumpSubmenu->add(new MenuElement(onShowPump2));

  // Fill main menu
  mainMenu->add(mainScreen);
  mainMenu->add(settings);
  mainMenu->add(phCalibration);
  mainMenu->add(testPump);

  return mainMenu;
}