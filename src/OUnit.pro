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
    TemporalFrequencyWidget.cpp

HEADERS  += MainWindow.h \
    ConversionUtilities.h \
    TemporalFrequencyWidget.h

FORMS    += MainWindow.ui \
    TemporalFrequencyWidget.ui

RESOURCES += \
    Resources.qrc