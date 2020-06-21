#include "Menu.h"
#include <Arduino.h>

Menu::Menu(){
    this->current = NULL;
    this->isChanged = false;
    this->last = NULL;
    this->nowInSubMenu = false;
}

Menu::~Menu(){

}

void Menu::next(){
    if (this->nowInSubMenu) {
        this->current->subMenu->next();
        return;
    }

    if (this->current == NULL){
        return;
    }

    MenuElement *next = this->current->next;
    if(next != NULL){
        this->current = next;
        this->isChanged = true;
    }
}

void Menu::previos(){
    if (this->nowInSubMenu) {
        this->current->subMenu->previos();
        return;
    }

    if (this->current == NULL){
        return;
    }

    MenuElement *prev = this->current->prev;
    if(prev != NULL){
        this->current = prev;
        this->isChanged = true;
    }
}

void Menu::add(MenuElement *newElement){
    if (this->last == NULL){
        this->last = newElement;
        this->current = newElement;
        this->isChanged = true;
        return;
    }

    newElement->prev = this->last;
    this->last->next = newElement;
    this->last = newElement;
}

bool Menu::currentIsChanged(bool returnToDefault){
    if (this->nowInSubMenu){
        return this->current->subMenu->currentIsChanged(returnToDefault);
    }

    bool currVal = this->isChanged;
    if (returnToDefault){
        this->isChanged = false;
    }
    return currVal;
}

MenuElement* Menu::getCurrent() {
    if ( this->nowInSubMenu){
        Menu* subMenu = this->current->subMenu;
        if (subMenu != NULL){
            return subMenu->getCurrent();
        }
        return NULL;
    }
    return this->current;
}

void Menu::callOnShowAction(){
    MenuElement *curr = this->getCurrent();
    if (curr == NULL){
        return;
    }

    if (!this->currentIsChanged(true)){
        return;
    }

    if (curr->onShow != NULL){
        curr->onShow();
    }
}

// Войти в подменю если у текущего элемента оно есть, если нет, то вызвать onClick
void Menu::callOnClickAction(){
    MenuElement *curr = this->getCurrent();
    if (curr == NULL){
        return;
    }

    if (curr->onClick != NULL){
        curr->onClick();
        return;
    }

    if (this->current->subMenu != NULL){
        this->nowInSubMenu = !this->nowInSubMenu;
        this->isChanged = true;
        this->current->subMenu->isChanged = true;
    }
}