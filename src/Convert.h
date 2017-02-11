#ifndef CONVERT_H
#define CONVERT_H

#include <QHash>
#include <functional>

class Convert
{
public:
    Convert();
    virtual double convert(double inputNum, QString inputUnit, QString outputUnit, QStringList inputModifiers = QStringList(), QStringList outputModifiers = QStringList());
    virtual QString getSIUnit();
protected:
    QHash<QString, QPair<std::function<double(double)>, std::function<double(double)> > > m_convert;
};

#endif // CONVERT_H
