#ifndef INDUCTANCEWIDGET_H
#define INDUCTANCEWIDGET_H

#include <QWidget>

#include "ConvertInductance.h"

namespace Ui {
class InductanceWidget;
}

class InductanceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InductanceWidget(QApplication *app, QWidget *parent = 0);
    ~InductanceWidget();

public slots:
    void updateConversion(const QString &input);
    void updateKeyboardSpace();

private:
    Ui::InductanceWidget *ui;
    QApplication *m_app;

    ConvertInductance converter;
};

#endif // INDUCTANCEWIDGET_H
