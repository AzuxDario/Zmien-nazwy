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

SOURCES += main.cpp\
        widget.cpp \
    widgetoprogramie.cpp \
    widgetrejestrzmian.cpp \
    czmieniacznazw.cpp \
    widgetustawienia.cpp \
    namechangeparameters.cpp \
    settings.cpp \
    core.cpp \
    folderdetector.cpp

HEADERS  += widget.h \
    widgetoprogramie.h \
    widgetrejestrzmian.h \
    czmieniacznazw.h \
    widgetustawienia.h \
    namechangeparameters.h \
    settings.h \
    core.h \
    folderdetetor.h

FORMS    += widget.ui \
    widgetoprogramie.ui \
    widgetrejestrzmian.ui \
    widgetustawienia.ui

RESOURCES += \
    ikony.qrc

DISTFILES +=
