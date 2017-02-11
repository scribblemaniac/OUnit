#include <QDebug>

#include "ConversionUtilities.h"

#include "Convert.h"

Convert::Convert()
{

}

double Convert::convert(double inputNum, QString inputUnit, QString outputUnit, QStringList inputModifiers, QStringList outputModifiers)
{
    qDebug() << inputModifiers << outputModifiers;
    double result = inputNum;
    if(inputModifiers.size() == 1) {
        result = ConversionUtilities::SIConversion(result, inputModifiers.first(), QString());
    }
    if(m_convert.contains(inputUnit)) {
        result = m_convert.value(inputUnit).first(result);
    }
    if(outputModifiers.size() == 1) {
        result = ConversionUtilities::SIConversion(result, QString(), outputModifiers.first());
    }
    if(m_convert.contains(outputUnit)) {
        result = m_convert.value(outputUnit).second(result);
    }
    return result;
}

QString Convert::getSIUnit()
{
    return QString();
}
