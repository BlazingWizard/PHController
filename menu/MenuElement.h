#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Menu.h"

class Menu;

class MenuElement
{
private:
    void fillMenuElement(void (*onShowAction)(), void (*onHoldRightAction)(), void (*onHoldLeftAction)(), void (*onClickAction)());

public:
    MenuElement *next;
    MenuElement *prev;

    Menu *subMenu;

    void (*onShow)();
    void (*onClick)();
    void (*onHoldRight)();
    void (*onHoldLeft)();

    MenuElement(void (*onShowAction)());
    MenuElement(void (*onShowAction)(), void (*onClickAction)());
    MenuElement(void (*onShowAction)(), void (*onHoldRightAction)(), void (*onHoldLeftAction)());
    MenuElement(void (*onShowAction)(), void (*onHoldRightAction)(), void (*onHoldLeftAction)(), void (*onClickAction)());

    ~MenuElement();
};

#endif