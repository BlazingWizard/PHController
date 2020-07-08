#include "IntSettingsField.h"
#include <Arduino.h>

IntSettingsField::IntSettingsField(int defaultValue){
    this->fillSettingsField(defaultValue, 0, 0);
}

IntSettingsField::IntSettingsField(int defaultValue, int minValue, int maxValue){
    this->fillSettingsField(defaultValue, minValue, maxValue);
}

void IntSettingsField::fillSettingsField(int defaultValue, int minValue, int maxValue){
    this->value = defaultValue;
    this->minValue = minValue;
    this->maxValue = maxValue; 
    this->displayValue = NULL;   
}

IntSettingsField::~IntSettingsField(){

}

void IntSettingsField::setValue(int value){
    this->setValue(value, NULL);
}

void IntSettingsField::setValue(int value, char *displayValue){
    this->value = value;
    this->displayValue = displayValue;
}

int IntSettingsField::getValue(){
    return this->value;
}

void IntSettingsField::getDisplayValue(char* arr){
    String str;
    if (this->displayValue != NULL){
        str = String(this->displayValue);
    } 
    else
    {
        str = String(this->getValue());
    }
 
    str.toCharArray(arr,10);
}

