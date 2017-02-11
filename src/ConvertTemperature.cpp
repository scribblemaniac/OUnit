#include "ConvertTemperature.h"

ConvertTemperature::ConvertTemperature() {
    m_convert.insert("Celcius", { [] (double d) -> double { return d + 273.15; }, [] (double d) -> double { return d - 273.15; } });
    m_convert.insert("Delisle", { [] (double d) -> double { return 373.15 - d * 2 / 3; }, [] (double d) -> double { return (373.15 - d) * 3 / 2; } });
    m_convert.insert("Fahrenheit", { [] (double d) -> double { return (d + 459.67) * 5 / 9; }, [] (double d) -> double { return d * 9 / 5 - 459.67; } });
    m_convert.insert("Rankine", { [] (double d) -> double { return d * 5 / 9; }, [] (double d) -> double { return d * 9 / 5; } });
    m_convert.insert("Newton", { [] (double d) -> double { return d * 100 / 33 + 273.15; }, [] (double d) -> double { return (d - 273.15) * 33 / 100; } });
    m_convert.insert("Réaumur", { [] (double d) -> double { return d * 5 / 4 + 273.15; }, [] (double d) -> double { return (d - 273.15) * 4 / 5; } });
    m_convert.insert("Rømer", { [] (double d) -> double { return (d - 7.5) * 40 / 21 + 273.15; }, [] (double d) -> double { return (d - 273.15) * 21 / 40 + 7.5; } });
}

QString ConvertTemperature::getSIUnit() {
    return QString("Kelvin");
}
