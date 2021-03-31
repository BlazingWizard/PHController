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
    if(this->isWorking){
      return;
    }

    this->turnOn();
    this->isWorking = true;
    this->workStartAt = millis();
    this->workDuration = duration;
}

void Pump::tick(){
    if (!this->isWorking){
        return;
    }

    unsigned long currentMills = millis();
    if (currentMills - this->workStartAt > this->workDuration){
        this->turnOff();
        this->isWorking = false;
        this->workStartAt = 0;
        this->workDuration = 0;
    }
}
