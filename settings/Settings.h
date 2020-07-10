#include "IntSettingsField.h"

class Settings
{
private:
    
public:
    IntSettingsField* mode;
    IntSettingsField* phLow;
    IntSettingsField* phHigh;
    IntSettingsField* smallAdjust;
    IntSettingsField* largeAdjust;
    IntSettingsField* delay;
    IntSettingsField* LED;

    Settings();
    ~Settings();
};