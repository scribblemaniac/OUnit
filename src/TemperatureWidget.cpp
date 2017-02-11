#include "TemperatureWidget.h"
#include "ui_TemperatureWidget.h"

#include <QDebug>

#include "ConversionUtilities.h"

TemperatureWidget::TemperatureWidget(QApplication *app, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperatureWidget),
    m_app(app),
    converter()
{
    ui->setupUi(this);

    ui->iNum->setValidator( new QDoubleValidator(this) );
    ui->iNum->setInputMethodHints(Qt::ImhPreferNumbers);

    connect(ui->iNum, &QLineEdit::textChanged, this, &TemperatureWidget::updateConversion);
    connect(ui->iPrefix, &QComboBox::currentTextChanged, this, &TemperatureWidget::updateUnit);
    connect(ui->oPrefix, &QComboBox::currentTextChanged, this, &TemperatureWidget::updateUnit);
    connect(ui->iUnit, &QComboBox::currentTextChanged, this, &TemperatureWidget::updateUnit);
    connect(ui->oUnit, &QComboBox::currentTextChanged, this, &TemperatureWidget::updateUnit);

    connect(m_app->inputMethod(), &QInputMethod::visibleChanged, this, &TemperatureWidget::updateKeyboardSpace);
    connect(m_app->inputMethod(), &QInputMethod::keyboardRectangleChanged, this, &TemperatureWidget::updateKeyboardSpace);

    updateKeyboardSpace();
}

TemperatureWidget::~TemperatureWidget() {
    delete ui;
}

void TemperatureWidget::updateUnit(QString text) {
    if(sender() == ui->iUnit) {
        if(text == converter.getSIUnit()) {
            ui->iPrefix->show();
        }
        else {
            ui->iPrefix->hide();
        }
    }
    else if(sender() == ui->oUnit) {
        if(text == converter.getSIUnit()) {
            ui->oPrefix->show();
        }
        else {
            ui->oPrefix->hide();
        }
    }
    updateConversion(ui->iNum->text());
}

void TemperatureWidget::updateConversion(const QString &input) {
    QStringList inputModifiers, outputModifiers;
    if(ui->iPrefix->isVisible()) inputModifiers.append(ui->iPrefix->currentText());
    if(ui->oPrefix->isVisible()) outputModifiers.append(ui->oPrefix->currentText());
    ui->oNum->setText(QString::number(converter.convert(input.toDouble(), ui->iUnit->currentText(), ui->oUnit->currentText(), inputModifiers, outputModifiers)));
}

void TemperatureWidget::updateKeyboardSpace() {
    if(m_app->inputMethod()->isVisible()) {
        ui->keyboardSpacer->changeSize(20, m_app->inputMethod()->keyboardRectangle().height(), QSizePolicy::Minimum, QSizePolicy::Minimum);
    }
    else {
        ui->keyboardSpacer->changeSize(20, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
    }
    this->layout()->invalidate();
}
