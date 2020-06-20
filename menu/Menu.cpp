#include "Menu.h"
#include <Arduino.h>

Menu::Menu(){
    this->current = NULL;
    this->isChanged = false;
    this->last = NULL;
}

Menu::~Menu(){

}

void Menu::next(){
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
    bool currVal = this->isChanged;
    if (returnToDefault){
        this->isChanged = false;
    }
    return currVal;
}

MenuElement* Menu::getCurrent() {
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