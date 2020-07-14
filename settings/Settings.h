#include "IntSettingsField.h"
#include "DoubleSettingsField.h"

class Settings
{
private:
public:
    IntSettingsField *mode;
    DoubleSettingsField *phLow;
    DoubleSettingsField *phHigh;
    IntSettingsField *smallAdjust;
    IntSettingsField *largeAdjust;
    IntSettingsField *delay;
    IntSettingsField *LED;

    Settings(char** modeDisplayValues, char** ledDisplayValues);
    ~Settings();
};