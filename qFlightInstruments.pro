#-------------------------------------------------
#
# Project created by QtCreator 2011-06-14T09:29:57
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qFlightInstruments
TEMPLATE = app

LIBS += -lqwt -lm

SOURCES += main.cpp \
        TestWin.cpp \
        qFlightInstruments.cpp \


HEADERS  += qFlightInstruments.h \
            TestWin.h

