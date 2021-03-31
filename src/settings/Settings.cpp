#include "Settings.h"
#include <EEPROMVar.h>
#include <EEPROMex.h>

#define MAX_INT_VALUE 32767

Settings::Settings(char **modeDisplayValues, char **ledDisplayValues)
{
    // TODO find problem with sizeof(T)
    this->modeAdr = 0;
    this->phLowAdr = 20;
    this->phHighAdr = 40;
    this->smallAdjustAdr = 60;
    this->largeAdjustAdr = 80;
    this->delayAdr = 100;
    this->LEDAdr = 120;

    this->mode = new IntSettingsField(0, 0, 1, modeDisplayValues);
    this->phLow = new DoubleSettingsField(0, 0, 14);
    this->phHigh = new DoubleSettingsField(0, 0, 14);
    this->smallAdjust = new IntSettingsField(1, 1, MAX_INT_VALUE);
    this->largeAdjust = new IntSettingsField(1, 1, MAX_INT_VALUE);
    this->delay = new IntSettingsField(0, 1, 60);
    this->LED = new IntSettingsField(0, 0, 1, ledDisplayValues);

    this->loadFromMemory();
}

void Settings::loadFromMemory()
{
    this->mode->setValue(EEPROM.readInt(this->modeAdr));
    this->phLow->setValue(EEPROM.readDouble(this->phLowAdr));
    this->phHigh->setValue(EEPROM.readDouble(this->phHighAdr));
    this->smallAdjust->setValue(EEPROM.readInt(this->smallAdjustAdr));
    this->largeAdjust->setValue(EEPROM.readInt(this->largeAdjustAdr));
    this->delay->setValue(EEPROM.readInt(this->delayAdr));
    this->LED->setValue(EEPROM.readInt(this->LEDAdr));
}

void Settings::saveToMemory()
{
    EEPROM.updateInt(this->modeAdr, this->mode->getValue());
    EEPROM.updateDouble(this->phLowAdr, this->phLow->getValue());
    EEPROM.updateDouble(this->phHighAdr, this->phHigh->getValue());
    EEPROM.updateInt(this->smallAdjustAdr, this->smallAdjust->getValue());
    EEPROM.updateInt(this->largeAdjustAdr, this->largeAdjust->getValue());
    EEPROM.updateInt(this->delayAdr, this->delay->getValue());
    EEPROM.updateInt(this->LEDAdr, this->LED->getValue());
}

void Settings::returnToDefault()
{
    this->mode->setValue(0);
    this->phLow->setValue(0);
    this->phHigh->setValue(0);
    this->smallAdjust->setValue(1);
    this->largeAdjust->setValue(1);
    this->delay->setValue(0);
    this->LED->setValue(0);
}

Settings::~Settings()
{
}