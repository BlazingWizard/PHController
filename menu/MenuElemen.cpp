#include "MenuElemen.h"
#include <Arduino.h>

MenuElement::MenuElement(char* title){
    this->title = title;
    this->next = NULL;
    this->prev = NULL;
}

MenuElement::~MenuElement(){

}

char* MenuElement::getTitle(){
    return this->title;
}