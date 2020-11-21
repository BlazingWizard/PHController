#include "Pump.h"
#include <Arduino.h>

Pump::Pump(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Pump::turnOn()
{
    digitalWrite(this->pin, HIGH);
}

void Pump::turnOff()
{
    digitalWrite(this->pin, LOW);
}

void Pump::turnOn(int duration)
{
    // TODO delete delay
    this->turnOn();
    delay(duration);
    this->turnOff();
}
