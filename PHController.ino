#include <microWire.h>
#include <microLiquidCrystal_I2C.h>
#include <GyverEncoder.h>

#include "Menu.h"

LiquidCrystal_I2C lcd(0x3F, 20, 4);
Encoder enc1(2, 3, 4, TYPE2);
Menu *menu = new Menu();

void setup() {
  Serial.begin(38400);
  lcd.init();
  lcd.backlight();
  
  MenuElement *ms = new MenuElement(onShowMain);
  MenuElement *s = new MenuElement(onShowSettings);

  ms->subMenu = new Menu();
  ms->subMenu->add(new MenuElement(test1));
  ms->subMenu->add(new MenuElement(test2));
  ms->subMenu->add(new MenuElement(test3));

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

  if (enc1.isClick()){
     menu->callOnClickAction();
  }

  menu->callOnShowAction();
}


void onShowMain(){
  lcd.clear();
  lcd.printstr("Main Screen");
}

void onShowSettings(){
  lcd.clear();
  lcd.printstr("Settings");
}

void test1(){
  lcd.clear();
  lcd.printstr("test1");
}

void test2(){
  lcd.clear();
  lcd.printstr("test2");
}

void test3(){
  lcd.clear();
  lcd.printstr("test3");
}