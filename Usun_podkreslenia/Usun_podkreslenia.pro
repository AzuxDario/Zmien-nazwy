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
    widgetrejestrzmian.cpp \
    namechangeparameters.cpp \
    settings.cpp \
    core.cpp \
    folderdetector.cpp \
    namechanger.cpp \
    widgetabout.cpp \
    widgetsettings.cpp

HEADERS  += widget.h \
    widgetrejestrzmian.h \
    namechangeparameters.h \
    settings.h \
    core.h \
    folderdetetor.h \
    namechanger.h \
    widgetabout.h \
    widgetsettings.h

FORMS    += widget.ui \
    widgetrejestrzmian.ui \
    widgetabout.ui \
    widgetsettings.ui

RESOURCES += \
    icons.qrc

DISTFILES +=
