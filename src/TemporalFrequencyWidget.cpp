#include "TemporalFrequencyWidget.h"
#include "ui_TemporalFrequencyWidget.h"

#include <QDebug>

#include "ConversionUtilities.h"

TemporalFrequencyWidget::TemporalFrequencyWidget(QApplication *app, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemporalFrequencyWidget),
    m_app(app)
{
    ui->setupUi(this);

    ui->iNum->setValidator( new QDoubleValidator(this) );
    ui->iNum->setInputMethodHints(Qt::ImhPreferNumbers);

    connect(ui->iNum, &QLineEdit::textChanged, this, &TemporalFrequencyWidget::updateConversion);
    connect(ui->iPrefix, &QComboBox::currentTextChanged, [this] () { updateConversion(ui->iNum->text()); });
    connect(ui->oPrefix, &QComboBox::currentTextChanged, [this] () { updateConversion(ui->iNum->text()); });

    connect(m_app->inputMethod(), &QInputMethod::visibleChanged, this, &TemporalFrequencyWidget::updateKeyboardSpace);
    connect(m_app->inputMethod(), &QInputMethod::keyboardRectangleChanged, this, &TemporalFrequencyWidget::updateKeyboardSpace);

    updateKeyboardSpace();
}

TemporalFrequencyWidget::~TemporalFrequencyWidget()
{
    delete ui;
}

void TemporalFrequencyWidget::updateConversion(const QString &input)
{
    QStringList inputModifiers, outputModifiers;
    if(ui->iPrefix->isVisible()) inputModifiers.append(ui->iPrefix->currentText());
    if(ui->oPrefix->isVisible()) outputModifiers.append(ui->oPrefix->currentText());
    ui->oNum->setText(QString::number(converter.convert(input.toDouble(), QString("Hertz"), QString("Hertz"), inputModifiers, outputModifiers)));
}

void TemporalFrequencyWidget::updateKeyboardSpace()
{
    if(m_app->inputMethod()->isVisible()) {
        ui->keyboardSpacer->changeSize(20, m_app->inputMethod()->keyboardRectangle().height(), QSizePolicy::Minimum, QSizePolicy::Minimum);
    }
    else {
        ui->keyboardSpacer->changeSize(20, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
    }
    this->layout()->invalidate();
}
