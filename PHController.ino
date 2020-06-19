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

  menu->add(new MenuElement("Main Screen"));
  menu->add(new MenuElement("Settings"));
  menu->add(new MenuElement("Callibration"));
  menu->add(new MenuElement("Test"));

  char* title = menu->getCurrentTitle();
  lcd.printstr(title);
}

void loop() {
  enc1.tick();

  if (enc1.isRight()) {
    menu->next();
  }

  if (enc1.isLeft()) {
    menu->previos();
  }

  if (menu->currentIsChanged(true)) {
    Serial.println("change");
    lcd.clear();
    char* title = menu->getCurrentTitle();
    lcd.printstr(title);
  }
}
