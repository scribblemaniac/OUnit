#ifndef CONVERTTEMPERATURE_H
#define CONVERTTEMPERATURE_H

#include "Convert.h"

class ConvertTemperature: public Convert
{
public:
    ConvertTemperature();
    QString getSIUnit() override;
};

#endif // CONVERTTEMPERATURE_H
