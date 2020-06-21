#include "MenuElemen.h"
#include <Arduino.h>

MenuElement::MenuElement(void (*onShowAction)()){
    this->next = NULL;
    this->prev = NULL;
    this->subMenu = NULL;

    this->onShow = onShowAction;
    this->onClick = NULL;
    this->onHoldRight = NULL;
    this->onHoldLeft = NULL;
}

MenuElement::~MenuElement(){

}