#include "IntSettingsField.h"
#include <Arduino.h>

IntSettingsField::IntSettingsField(int defaultValue){
    this->fillSettingsField(defaultValue, 0, 0);
}

IntSettingsField::IntSettingsField(int defaultValue, int minValue, int maxValue){
    this->fillSettingsField(defaultValue, minValue, maxValue);
}

void IntSettingsField::fillSettingsField(int defaultValue, int minValue, int maxValue){
    this->minValue = minValue;
    this->maxValue = maxValue;
    
    this->setValue(defaultValue); 
}

IntSettingsField::~IntSettingsField(){

}

void IntSettingsField::setValue(int value){
    this->setValue(value, NULL);
}

void IntSettingsField::setValue(int value, char *displayValue){
    this->displayValue = displayValue;
    
    // if not need check bound set received value
    if (!this->needCheckBounds()){
        this->value = value;
        return;
    }

    // if received value to large, set max
    if (value > this->maxValue){
        this->value = this->maxValue;
        return;
    }
    
    // if received value to small, set min
    if (value < this->minValue){
        this->value = this->minValue;
        return;
    }

    // if diapason correct received value
    this->value = value;
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

void IntSettingsField::inc(){  
    if(this->needCheckBounds() && this->value == this->maxValue){
        return;
    }

    this->value++;
    return;
}

void IntSettingsField::dec(){
    if(this->needCheckBounds() && this->value == this->minValue){
        return;
    }

    this->value--;
    return;
}

bool IntSettingsField::needCheckBounds(){
    return this->minValue != 0 || this->maxValue != 0;
}