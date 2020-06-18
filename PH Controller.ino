#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4); 

void setup() {
  Serial.begin(38400);
  lcd.init();
  lcd.backlight();

  lcd.print("Hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
