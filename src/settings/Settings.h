#include "IntSettingsField.h"
#include "DoubleSettingsField.h"

class Settings
{
private:
    int modeAdr;
    int phLowAdr;
    int phHighAdr;
    int smallAdjustAdr;
    int largeAdjustAdr;
    int delayAdr;
    int LEDAdr;

public:
    IntSettingsField *mode;
    DoubleSettingsField *phLow;
    DoubleSettingsField *phHigh;
    IntSettingsField *smallAdjust;
    IntSettingsField *largeAdjust;
    IntSettingsField *delay;
    IntSettingsField *LED;

    void loadFromMemory();
    void saveToMemory();
    void returnToDefault();

    Settings(char **modeDisplayValues, char **ledDisplayValues);
    ~Settings();
};