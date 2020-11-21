class PHSensor
{
private:
    float calibration = 22.62;
    int pin;
public:
    PHSensor(int pin);

    float read();

    // Change calibration coefficient
    void calibrate(float standartPh);
};
