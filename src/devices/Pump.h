class Pump
{
private:
    int pin;

    bool isWorking;

    unsigned long workStartAt;

    int workDuration;

    void turnOn();

    void turnOff();

public:
    Pump(int pin);

    void turnOn(int duration);

    void tick();
};