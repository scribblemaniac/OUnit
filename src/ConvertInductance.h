#ifndef CONVERTINDUCTANCE_H
#define CONVERTINDUCTANCE_H

#include "Convert.h"

class ConvertInductance : public Convert
{
public:
    ConvertInductance();
    QString getSIUnit() override;
};

#endif // CONVERTINDUCTANCE_H
