#include "MenuElemen.h"
#include <Arduino.h>

class Menu
{
private:
    MenuElement *current;

    MenuElement *last;
    
    bool isChanged;

    bool currentIsChanged(bool returnToDefault);
public:
    Menu();
    
    ~Menu();

    void next();
    
    void previos();
    
    void add(MenuElement *newElement);

    MenuElement* getCurrent();

    void callOnShowAction();
};