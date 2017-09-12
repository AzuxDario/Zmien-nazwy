#-------------------------------------------------
#
# Project created by QtCreator 2017-07-19T15:38:22
#
#-------------------------------------------------

QT       += testlib

QT       -= gui
QT       += widgets

TARGET = tst_usun_podkreslenia_test
CONFIG   += console
CONFIG   -= app_bundle

CONFIG   += testcase

TEMPLATE = app

HEADERS += ../Usun_podkreslenia/namechanger.h

SOURCES += tst_usun_podkreslenia_test.cpp \
    namechangertest.cpp \
    ../Usun_podkreslenia\namechanger.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
