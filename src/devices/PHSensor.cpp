#include "PHSensor.h"
#include <Arduino.h>

#define DEFAULT_CALIBRATION_COEFF 22.62
#define SENSOR_ACCURACY 0.1

PHSensor::PHSensor(int pin, float calibration)
{
    this->pin = pin;
    
    float calibrationCoeff = calibration != 0.0 ? calibration : DEFAULT_CALIBRATION_COEFF;
    this->calibration = calibrationCoeff;
}

float PHSensor::read()
{

    // Get ten values
    int buf[10];
    for (int i = 0; i < 10; i++)
    {
        buf[i] = analogRead(this->pin);
        delay(30);
    }

    // Sort values
    int temp;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (buf[i] > buf[j])
            {
                temp = buf[i];
                buf[i] = buf[j];
                buf[j] = temp;
            }
        }
    }

    // Get avarenge without 2 start and 2 last element
    unsigned long int avgValue = 0;
    for (int i = 2; i < 8; i++)
    {
        avgValue += buf[i];
    }
    avgValue /= 6;

    // Get PH
    float pHVol = (float)avgValue * 5.0 / 1024;
    float phValue = -5.70 * pHVol + calibration;
    return phValue;
}

void PHSensor::calibrate(float standartPh){
    float currPH = this->read();
    float diff = standartPh - currPH;

    if (abs(diff) > SENSOR_ACCURACY){
        this->calibration += diff;
    }
}