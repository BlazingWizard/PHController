#include "Menu.h"
#include <Arduino.h>

#define UPDATE_SCREEN_PERIOD 5000

Menu::Menu()
{
    this->current = NULL;
    this->isChanged = false;
    this->last = NULL;
    this->nowInSubMenu = false;
}

Menu::~Menu()
{
}

void Menu::next()
{
    if (this->nowInSubMenu)
    {
        this->current->subMenu->next();
        return;
    }

    if (this->current == NULL)
    {
        return;
    }

    MenuElement *next = this->current->next;
    if (next != NULL)
    {
        this->current = next;
        this->isChanged = true;
    }
}

void Menu::previos()
{
    if (this->nowInSubMenu)
    {
        this->current->subMenu->previos();
        return;
    }

    if (this->current == NULL)
    {
        return;
    }

    MenuElement *prev = this->current->prev;
    if (prev != NULL)
    {
        this->current = prev;
        this->isChanged = true;
    }
}

void Menu::add(MenuElement *newElement)
{
    if (this->last == NULL)
    {
        this->last = newElement;
        this->current = newElement;
        this->isChanged = true;
        return;
    }

    newElement->prev = this->last;
    this->last->next = newElement;
    this->last = newElement;
}

bool Menu::currentIsChanged(bool returnToDefault)
{
    if (this->nowInSubMenu)
    {
        return this->current->subMenu->currentIsChanged(returnToDefault);
    }

    bool currVal = this->isChanged;
    if (returnToDefault)
    {
        this->isChanged = false;
    }
    return currVal;
}

bool Menu::needUpdateScreen()
{
    if (!this->current->isUpdateble)
    {
        return false;
    }

    unsigned long currentMillis = millis();
    return currentMillis - this->current->lastScreenUpdate > UPDATE_SCREEN_PERIOD;
}

MenuElement *Menu::getCurrent()
{
    if (this->nowInSubMenu)
    {
        Menu *subMenu = this->current->subMenu;
        if (subMenu != NULL)
        {
            return subMenu->getCurrent();
        }
        return NULL;
    }
    return this->current;
}

void Menu::callOnShowAction()
{
    MenuElement *curr = this->getCurrent();
    if (curr == NULL)
    {
        return;
    }

    if (!this->currentIsChanged(true) && !this->needUpdateScreen())
    {
        return;
    }

    if (curr->onShow != NULL)
    {
        curr->lastScreenUpdate = millis();
        curr->onShow();
    }
}

void Menu::callOnClickAction()
{
    MenuElement *curr = this->getCurrent();
    if (curr == NULL)
    {
        return;
    }

    if (curr->onClick != NULL)
    {
        curr->onClick();
        return;
    }

    // if not have onClick enter or exit in submenu
    if (this->current->subMenu != NULL)
    {
        this->nowInSubMenu = !this->nowInSubMenu;
        this->isChanged = true;
        this->current->subMenu->isChanged = true;
    }
}

void Menu::callOnHoldRightAction()
{
    MenuElement *curr = this->getCurrent();
    if (curr == NULL)
    {
        return;
    }

    if (curr->onHoldRight != NULL)
    {
        curr->onHoldRight();
        return;
    }
}

void Menu::callOnHoldLeftAction()
{
    MenuElement *curr = this->getCurrent();
    if (curr == NULL)
    {
        return;
    }

    if (curr->onHoldLeft != NULL)
    {
        curr->onHoldLeft();
        return;
    }
}