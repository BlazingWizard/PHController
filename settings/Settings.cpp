#include "Settings.h"

#define MAX_INT_VALUE 32767

Settings::Settings(char** modeDisplayValues, char** ledDisplayValues)
{
    this->mode = new IntSettingsField(0, 0, 1, modeDisplayValues);
    this->phLow = new IntSettingsField(0, 0, 14);
    this->phHigh = new IntSettingsField(0, 0, 14);
    this->smallAdjust = new IntSettingsField(1, 1, MAX_INT_VALUE);
    this->largeAdjust = new IntSettingsField(1, 1, MAX_INT_VALUE);
    this->delay = new IntSettingsField(0, 1, 60);
    this->LED = new IntSettingsField(0, 0, 1, ledDisplayValues);
}

Settings::~Settings()
{
}