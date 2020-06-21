#ifndef MENU_ELEMEN_H_INCLUDED
#define MENU_ELEMEN_H_INCLUDED

#include "MenuElemen.h"

class MenuElement;

class Menu
{
private:
    MenuElement *current;

    MenuElement *last;
    
    bool isChanged;

    bool nowInSubMenu;

    bool currentIsChanged(bool returnToDefault);
public:
    Menu();
    
    ~Menu();

    void next();
    
    void previos();
    
    void add(MenuElement *newElement);

    MenuElement* getCurrent();

    void callOnShowAction();

    void callOnClickAction();
};

#endif 