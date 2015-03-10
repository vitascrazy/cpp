TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=C++11

SOURCES += main.cpp \
    gamemodel.cpp \
    splashcontroller.cpp \
    subject.cpp \
    controlmanager.cpp \
    viewmanager.cpp \
    splashview.cpp \
    mainmenucontroller.cpp \
    mainmenuview.cpp \
    gamecontroller.cpp \
    gameview.cpp \
    selectsymbolcontroller.cpp \
    selectsymbolview.cpp \
    resultcontroller.cpp \
    resultview.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    gamemodel.h \
    IController.h \
    splashcontroller.h \
    IObserver.h \
    subject.h \
    controlmanager.h \
    viewmanager.h \
    IView.h \
    splashview.h \
    mainmenucontroller.h \
    mainmenuview.h \
    gamecontroller.h \
    gameview.h \
    selectsymbolcontroller.h \
    selectsymbolview.h \
    resultcontroller.h \
    resultview.h

