#include <GyverEncoder.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4); 

#define CLK 2
#define DT 3
#define SW 4

#include "GyverEncoder.h"
Encoder enc1(CLK, DT, SW, TYPE2); 

void setup() {
  Serial.begin(38400);
  lcd.init();
  lcd.backlight();

  lcd.print("Hello, world!");
}

int i = 0;
String nums[] = {"First", "Second", "Third", "Fourth"};
String prevVal = "";

void loop() {
    enc1.tick();
  
    if (enc1.isRight() && i < 3){
      i++;
    }         
    
    if (enc1.isLeft() && i > 0){
      i--;
    }

    if (enc1.isClick()){
      i = 0;
    }
   

    String curVal = nums[i];
    if (curVal != prevVal){
      lcd.clear();
      lcd.print(curVal);
      prevVal = curVal;
    }
    
}
