#include "ConversionUtilities.h"

#include <QtMath>

QHash<QString,int> ConversionUtilities::SIMap;

ConversionUtilities::ConversionUtilities()
{

}

double ConversionUtilities::SIConversion(double num, const QString &prefixFrom, const QString &prefixTo) {
    if(SIMap.isEmpty()) {
        SIMap.insert("yotta", 24);
        SIMap.insert("zetta", 21);
        SIMap.insert("exa", 18);
        SIMap.insert("peta", 15);
        SIMap.insert("tera", 12);
        SIMap.insert("giga", 9);
        SIMap.insert("mega", 6);
        SIMap.insert("kilo", 3);
        SIMap.insert("hecto", 2);
        SIMap.insert("deka", 1);
        SIMap.insert("deci", -1);
        SIMap.insert("centi", -2);
        SIMap.insert("milli", -3);
        SIMap.insert("micro", -6);
        SIMap.insert("nano", -9);
        SIMap.insert("pico", -12);
        SIMap.insert("femto", -15);
        SIMap.insert("atto", -18);
        SIMap.insert("zepto", -21);
        SIMap.insert("yocto", -24);
    }

    return num * qPow(10, SIMap.value(prefixFrom, 0) - SIMap.value(prefixTo, 0));
}

QString ConversionUtilities::SIConversionString(const QString &num, const QString &prefixFrom, const QString &prefixTo) {
    return QString::number(SIConversion(num.toDouble(), prefixFrom, prefixTo));
}
