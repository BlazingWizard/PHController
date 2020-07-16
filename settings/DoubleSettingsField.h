class DoubleSettingsField
{
private:
    double value;
    double maxValue;
    double minValue;

    void fillSettingsField(double defaultValue, double minValue, double maxValue);

    bool needCheckBounds();
    bool equal(double a, double b);

public:
    void setValue(double value);

    double getValue();

    void getDisplayValue(char *arr);

    void inc();
    void dec();

    DoubleSettingsField(double defaultValue);
    DoubleSettingsField(double defaultValue, double minValue, double maxValue);

    ~DoubleSettingsField();
};