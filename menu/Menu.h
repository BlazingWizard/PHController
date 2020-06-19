#include "MenuElemen.h"
#include <Arduino.h>

class Menu
{
private:
    MenuElement *current;

    MenuElement *last;
    
    bool isChanged;
public:
    Menu();
    
    ~Menu();

    void next();
    
    void previos();
    
    void add(MenuElement *newElement);
    
    bool currentIsChanged(bool returnToDefault);

    MenuElement* getCurrent();

    char* getCurrentTitle();
};