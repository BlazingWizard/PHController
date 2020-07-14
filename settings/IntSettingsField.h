class IntSettingsField
{
private:
    int value;
    int maxValue;
    int minValue;

    char **displayValues;

    void fillSettingsField(int defaultValue, int minValue, int maxValue, char** displayValues);

    bool needCheckBounds();

public:
    void setValue(int value);

    int getValue();

    void getDisplayValue(char *arr);

    void inc();
    void dec();

    IntSettingsField(int defaultValue);
    IntSettingsField(int defaultValue, int minValue, int maxValue);
    IntSettingsField(int defaultValue, int minValue, int maxValue, char** displayValues);

    ~IntSettingsField();
};