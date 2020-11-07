#ifndef MENU_ELEMEN_H_INCLUDED
#define MENU_ELEMEN_H_INCLUDED

#include "MenuElement.h"

class MenuElement;

class Menu
{
private:
    MenuElement *current;

    MenuElement *last;

    bool isChanged;

    bool nowInSubMenu;

    float lastScreenUpdate;

    bool currentIsChanged(bool returnToDefault);

    bool needUpdateScreen();
public:
    Menu();

    ~Menu();

    void next();

    void previos();

    void add(MenuElement *newElement);

    MenuElement* getCurrent();

    void callOnShowAction();

    void callOnClickAction();

    void callOnHoldRightAction();

    void callOnHoldLeftAction();
};

#endif