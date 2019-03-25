#-------------------------------------------------
#
# Project created by QtCreator 2018-07-09T10:31:37
#
#-------------------------------------------------
QT       += core gui
QT     +=serialport
QT    +=charts
QT    +=sql
QT    +=network
QT += virtualkeyboard

RC_ICONS = Banff.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IonTrap
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        mainwindow.cpp \
    main.cpp \
    ringbuffer.cpp \
    chartview.cpp \
    callout.cpp \
    setdialog.cpp \
    crcchecksum.cpp \
    dataacquirethread.cpp \
    searchpeak.cpp \
    normalui.cpp \
    normalui_chosementhod.cpp \
    chosementhod_editmenthod.cpp \
    normalui_instrumentstatus.cpp \
    normalui_historicaldata.cpp \
    normalui_experimentresult.cpp \
    messagedialog.cpp \
    instruction.cpp \
    keyboard.cpp \
    gcinstruction.cpp \
    gcringbuffer.cpp

HEADERS += \
        mainwindow.h \
    ringbuffer.h \
    callout.h \
    chartview.h \
    setdialog.h \
    instruomentpara.h \
    crcchecksum.h \
    dataacquirethread.h \
    searchpeak.h \
    normalui.h \
    normalui_chosementhod.h \
    chosementhod_editmenthod.h \
    normalui_instrumentstatus.h \
    normalui_historicaldata.h \
    menthodparameter.h \
    normalui_experimentresult.h \
    messagedialog.h \
    instruction.h \
    ui_top_para.h \
    keyboard.h \
    gcinstruction.h \
    gcringbuffer.h


FORMS += \
        mainwindow.ui \
    setdialog.ui \
    normalui.ui \
    normalui_chosementhod.ui \
    chosementhod_editmenthod.ui \
    normalui_instrumentstatus.ui \
    normalui_historicaldata.ui \
    normalui_experimentresult.ui \
    messagedialog.ui \
    keyboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=



