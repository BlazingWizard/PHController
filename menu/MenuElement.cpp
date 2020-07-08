#include "MenuElement.h"
#include <Arduino.h>

MenuElement::MenuElement(void (*onShowAction)()){
    this->fillMenuElement(onShowAction, NULL, NULL, NULL);
}

MenuElement::MenuElement(void (*onShowAction)(), void (*onHoldRightAction)(), void (*onHoldLeftAction)()){
    this->fillMenuElement(onShowAction, onHoldRightAction, onHoldLeftAction, NULL);
}

MenuElement::MenuElement(void (*onShowAction)(), void (*onHoldRightAction)(), void (*onHoldLeftAction)(), void (*onClickAction)()){
    this->fillMenuElement(onShowAction, onHoldRightAction, onHoldLeftAction, onClickAction);
}

MenuElement::~MenuElement(){

}

void MenuElement::fillMenuElement(void (*onShowAction)(), void (*onHoldRightAction)(), void (*onHoldLeftAction)(), void (*onClickAction)()){
    this->next = NULL;
    this->prev = NULL;
    this->subMenu = NULL;

    this->onShow = onShowAction;
    this->onHoldRight = onHoldRightAction;
    this->onHoldLeft = onHoldLeftAction;
    this->onClick = onClickAction;
}