#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T15:42:08
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

TARGET = Usun_podkreslenia
TEMPLATE = app

#win32:RC_FILE += Ikona.rc
win32:RC_ICONS += Ikona.ico# for Qt 5

include(Models/Models.pri)
include(Providers/Providers.pri)
include(Views/Views.pri)
include(ViewProviders/ViewProviders.pri)

SOURCES += main.cpp

HEADERS  +=  

RESOURCES += \
    icons.qrc

DISTFILES +=
