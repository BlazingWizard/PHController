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
    this->turnOn();
    delay(duration * 1000);
    this->turnOff();
}
