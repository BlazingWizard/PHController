class PHSensor
{
private:
    float calibration;
    int pin;
public:
    PHSensor(int pin, float calibration);

    float read();

    // Change calibration coefficient
    void calibrate(float standartPh);
};
