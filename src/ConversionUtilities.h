#ifndef CONVERSIONUTILITIES_H
#define CONVERSIONUTILITIES_H

#include <QHash>

class ConversionUtilities
{
public:
    ConversionUtilities();

    static double SIConversion(double num, const QString &prefixFrom, const QString &prefixTo);
    static QString SIConversionString(const QString &num, const QString &prefixFrom, const QString &prefixTo);

private:
    static QHash<QString,int> SIMap;
};

#endif // CONVERSIONUTILITIES_H
