class PHSensor
{
private:
    const float calibration = 22.62; //change this value to calibrate
    int pin;
public:
    PHSensor(int pin);

    float read();
};
