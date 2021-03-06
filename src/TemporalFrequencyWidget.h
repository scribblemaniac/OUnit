#ifndef TEMPORALFREQUENCYWIDGET_H
#define TEMPORALFREQUENCYWIDGET_H

#include <QWidget>
#include <QApplication>

#include "ConvertTemporalFrequency.h"

namespace Ui {
class TemporalFrequencyWidget;
}

class TemporalFrequencyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TemporalFrequencyWidget(QApplication *app, QWidget *parent = 0);
    ~TemporalFrequencyWidget();

public slots:
    void updateConversion(const QString &input);
    void updateKeyboardSpace();

private:
    Ui::TemporalFrequencyWidget *ui;
    QApplication *m_app;

    ConvertTemporalFrequency converter;
};

#endif // TEMPORALFREQUENCYWIDGET_H
