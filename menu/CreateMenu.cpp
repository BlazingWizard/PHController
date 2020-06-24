#include "CreateMenu.h"
#include <microLiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);

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

void initLCD(){
  lcd.init();
  lcd.backlight();
}

Menu* createMenu(){
    Menu *menu = new Menu();

    MenuElement *ms = new MenuElement(onShowMain);
    MenuElement *s = new MenuElement(onShowSettings);

    ms->subMenu = new Menu();
    ms->subMenu->add(new MenuElement(test1));
    ms->subMenu->add(new MenuElement(test2));
    ms->subMenu->add(new MenuElement(test3));

    menu->add(ms);
    menu->add(s);

    return menu;
}

