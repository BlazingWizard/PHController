#include "DoubleSettingsField.h"
#include <Arduino.h>

#define CHANGE_DELTA 0.1
#define MAX_STR_LENGTH 20
#define DEFAULT_VALUE 0.0

DoubleSettingsField::DoubleSettingsField(double defaultValue)
{
    this->fillSettingsField(defaultValue, DEFAULT_VALUE, DEFAULT_VALUE);
}

DoubleSettingsField::DoubleSettingsField(double defaultValue, double minValue, double maxValue)
{
    this->fillSettingsField(defaultValue, minValue, maxValue);
}

void DoubleSettingsField::fillSettingsField(double defaultValue, double minValue, double maxValue)
{
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->setValue(defaultValue);
}

DoubleSettingsField::~DoubleSettingsField()
{
}

void DoubleSettingsField::setValue(double value)
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

double DoubleSettingsField::getValue()
{
    return this->value;
}

void DoubleSettingsField::getDisplayValue(char *arr)
{
    String str;
    double val = this->getValue();

    str = String(val);
    str.toCharArray(arr, MAX_STR_LENGTH);
}

void DoubleSettingsField::inc()
{
    if (this->needCheckBounds() && this->equal(this->value, this->maxValue))
    {
        return;
    }

    this->value += CHANGE_DELTA;
    return;
}

void DoubleSettingsField::dec()
{
    if (this->needCheckBounds() && this->equal(this->value, this->minValue))
    {
        return;
    }

    this->value -= CHANGE_DELTA;
    return;
}

bool DoubleSettingsField::needCheckBounds()
{
    return this->minValue != DEFAULT_VALUE || this->maxValue != DEFAULT_VALUE;
}

bool DoubleSettingsField::equal(double a, double b)
{
    double diff = a - b;
    double abc = diff > 0 ? diff : -diff;

    return abc < 0.001;
}