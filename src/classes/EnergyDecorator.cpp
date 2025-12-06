class OutputDecorator {
public:
    OutputDecorator() = default;

    double KwhToWh(double kwh) {
        return kwh * 1000;
    }
    double WhToKwh(double wh) {
        return wh / 1000;
    }
    double NormalizePower(double reading) {
        if (reading < 1) {
            return KwhToWh(reading);
        }

        return reading;
    }
};