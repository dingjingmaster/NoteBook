#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T22:00:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NoteBookPlus
TEMPLATE = app


SOURCES += main.cpp\
        notebook.cpp \
    setting.cpp \
    color.cpp \
    configinfo.cpp

HEADERS  += notebook.h \
    setting.h \
    color.h \
    configinfo.h

FORMS    += notebook.ui \
    setting.ui

RESOURCES += \
    res.qrc

RC_FILE = ICO.rc

