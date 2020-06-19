#include <Arduino.h>

class MenuElement
{
private:
    char* title;
public:
    MenuElement *next;
    MenuElement *prev;
    
    char* getTitle();
    MenuElement(char* title);
    ~MenuElement();
};