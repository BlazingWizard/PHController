class IntSettingsField
{
private:
    int value;
    int maxValue;
    int minValue;

    char *displayValue;

    void fillSettingsField(int defaultValue, int minValue, int maxValue);

    bool needCheckBounds();

public:
    void setValue(int value);
    void setValue(int value, char *displayValue);

    int getValue();

    void getDisplayValue(char *arr);

    void inc();
    void dec();

    IntSettingsField(int defaultValue);
    IntSettingsField(int defaultValue, int minValue, int maxValue);

    ~IntSettingsField();
};