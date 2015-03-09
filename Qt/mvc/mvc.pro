TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gamemodel.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    gamemodel.h

