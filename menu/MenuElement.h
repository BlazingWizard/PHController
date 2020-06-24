#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Menu.h"

class Menu;

class MenuElement
{
private:
public:
    MenuElement *next;
    MenuElement *prev;

    Menu *subMenu;
    
    void (*onShow)();
    void (*onClick)();
    void (*onHoldRight)();
    void (*onHoldLeft)();

    MenuElement(void (*onShowAction)());
    ~MenuElement();
};

#endif