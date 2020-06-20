#include "MenuElemen.h"
#include <Arduino.h>

MenuElement::MenuElement(void (*onShowAction)()){
    this->next = NULL;
    this->prev = NULL;
    this->onShow = onShowAction;
}

MenuElement::~MenuElement(){

}