#ifndef CONVERTTEMPORALFREQUENCY_H
#define CONVERTTEMPORALFREQUENCY_H

#include "Convert.h"

class ConvertTemporalFrequency : public Convert
{
public:
    ConvertTemporalFrequency();
    QString getSIUnit() override;
};

#endif // CONVERTTEMPORALFREQUENCY_H
