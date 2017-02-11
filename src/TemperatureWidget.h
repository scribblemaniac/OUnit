#ifndef TEMPERATUREWIDGET_H
#define TEMPERATUREWIDGET_H

#include <QWidget>
#include <QApplication>

#include "ConvertTemperature.h"

namespace Ui {
class TemperatureWidget;
}

class TemperatureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TemperatureWidget(QApplication *app, QWidget *parent = 0);
    ~TemperatureWidget();

public slots:
    void updateUnit(QString text);
    void updateConversion(const QString &input);
    void updateKeyboardSpace();

private:
    Ui::TemperatureWidget *ui;
    QApplication *m_app;

    ConvertTemperature converter;
};

#endif // TEMPERATUREWIDGET_H
