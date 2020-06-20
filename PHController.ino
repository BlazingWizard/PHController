#include <microWire.h>
#include <microLiquidCrystal_I2C.h>
#include <GyverEncoder.h>

#include "Menu.h"

LiquidCrystal_I2C lcd(0x3F, 20, 4);
Encoder enc1(2, 3, 4, TYPE2);

Menu *menu = new Menu();

void onShowMain(){
  lcd.clear();
  lcd.printstr("Main Screen");
}

void onShowSettings(){
  lcd.clear();
  lcd.printstr("Settings");
}

void setup() {
  Serial.begin(38400);
  lcd.init();
  lcd.backlight();
  
  MenuElement *ms = new MenuElement(onShowMain);
  MenuElement *s = new MenuElement(onShowSettings);
  menu->add(ms);
  menu->add(s);
}

void loop() {
  enc1.tick();

  if (enc1.isRight()) {
    menu->next();
  }

  if (enc1.isLeft()) {
    menu->previos();
  }

  menu->callOnShowAction();
}
