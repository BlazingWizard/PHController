#include <microWire.h>
#include <microLiquidCrystal_I2C.h>
#include <GyverEncoder.h>

#include "Menu.h"
#include "CreateMenu.h"

Encoder enc1(2, 3, 4, TYPE2);
Menu *menu = NULL;

void setup() {
  Serial.begin(38400);
  initLCD();
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

  menu->callOnShowAction();
}
