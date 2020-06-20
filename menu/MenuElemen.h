#include <Arduino.h>

class MenuElement
{
private:
public:
    MenuElement *next;
    MenuElement *prev;
    
    void (*onShow)();

    MenuElement(void (*onShowAction)());
    ~MenuElement();
};