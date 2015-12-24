QT += core gui

TARGET = KEngine
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    window.cpp \
    engine.cpp

HEADERS += \
    window.h \
    engine.h

RESOURCES += \
    resources.qrc

