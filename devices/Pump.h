class Pump
{
private:
    int pin;

    void turnOn();

    void turnOff();

public:
    Pump(int pin);

    void turnOn(int duration);
};