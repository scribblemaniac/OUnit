#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T16:45:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OUnit
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ConversionUtilities.cpp \
    TemporalFrequencyWidget.cpp \
    TemperatureWidget.cpp \
    Convert.cpp \
    ConvertTemperature.cpp \
    ConvertTemporalFrequency.cpp \
    ConvertInductance.cpp \
    InductanceWidget.cpp

HEADERS  += MainWindow.h \
    ConversionUtilities.h \
    TemporalFrequencyWidget.h \
    TemperatureWidget.h \
    Convert.h \
    ConvertTemperature.h \
    ConvertTemporalFrequency.h \
    ConvertInductance.h \
    InductanceWidget.h

FORMS    += MainWindow.ui \
    TemporalFrequencyWidget.ui \
    TemperatureWidget.ui \
    InductanceWidget.ui

RESOURCES += \
    Resources.qrc
