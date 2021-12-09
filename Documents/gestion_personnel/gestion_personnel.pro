#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------
QT       += core gui sql serialport printsupport network charts multimedia
QT       += core gui charts
QT       += core gui sql
QT += core
QT       += core gui charts #-----satistiques
QT       += core gui sql network printsupport charts serialport multimedia
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestion_personnel
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
    arduino.cpp \
    client.cpp \
    excel.cpp \
    facture.cpp \
    historique.cpp \
    login.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    personnel.cpp \
    qrcode.cpp \
    smtp.cpp \
    voiture.cpp

HEADERS += \
    arduino.h \
    client.h \
    excel.h \
    facture.h \
    historique.h \
    login.h \
        mainwindow.h \
    connection.h \
    personnel.h \
    qrcode.h \
    smtp.h \
    voiture.h

FORMS += \
        login.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressorce.qrc
