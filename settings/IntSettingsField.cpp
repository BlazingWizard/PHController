#include "IntSettingsField.h"
#include <Arduino.h>

IntSettingsField::IntSettingsField(int defaultValue)
{
    this->fillSettingsField(defaultValue, 0, 0, NULL);
}

IntSettingsField::IntSettingsField(int defaultValue, int minValue, int maxValue)
{
    this->fillSettingsField(defaultValue, minValue, maxValue, NULL);
}

IntSettingsField::IntSettingsField(int defaultValue, int minValue, int maxValue, char** displayValues)
{
    this->fillSettingsField(defaultValue, minValue, maxValue, displayValues);
}

void IntSettingsField::fillSettingsField(int defaultValue, int minValue, int maxValue, char** displayValues)
{
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->displayValues = displayValues;

    this->setValue(defaultValue);
}

IntSettingsField::~IntSettingsField()
{
}

void IntSettingsField::setValue(int value)
{
    // if not need check bound set received value
    if (!this->needCheckBounds())
    {
        this->value = value;
        return;
    }

    // if received value to large, set max
    if (value > this->maxValue)
    {
        this->value = this->maxValue;
        return;
    }

    // if received value to small, set min
    if (value < this->minValue)
    {
        this->value = this->minValue;
        return;
    }

    // if diapason correct received value
    this->value = value;
}

int IntSettingsField::getValue()
{
    return this->value;
}

void IntSettingsField::getDisplayValue(char *arr)
{
    String str;
    int val = this->getValue();
    if (this->displayValues != NULL)
    {
        char** displayValues = this->displayValues;
        str = String(displayValues[val]);
    }
    else
    {
        str = String(val);
    }

    str.toCharArray(arr, 10);
}

void IntSettingsField::inc()
{
    if (this->needCheckBounds() && this->value == this->maxValue)
    {
        return;
    }

    this->value++;
    return;
}

void IntSettingsField::dec()
{
    if (this->needCheckBounds() && this->value == this->minValue)
    {
        return;
    }

    this->value--;
    return;
}

bool IntSettingsField::needCheckBounds()
{
    return this->minValue != 0 || this->maxValue != 0;
}