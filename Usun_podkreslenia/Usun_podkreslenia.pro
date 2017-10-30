#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T15:42:08
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

TARGET = Usun_podkreslenia
TEMPLATE = app

win32:RC_ICONS += Icons\Ikona.ico

include(Models/Models.pri)
include(Providers/Providers.pri)
include(NameChangers/NameChangers.pri)
include(DirectoryDetectors/DirectoryDetectors.pri)
include(Widgets/Widgets.pri)
include(WidgetsProviders/WidgetsProviders.pri)
include(Const/Const.pri)

SOURCES += main.cpp

HEADERS  +=  

RESOURCES += \
    icons.qrc

DISTFILES +=
