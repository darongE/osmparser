#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T15:26:45
#
#-------------------------------------------------

QT       += xml widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = osmparser
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    workerthread.cpp

HEADERS  += widget.h \
    workerthread.h \
    typedef.h

FORMS    += widget.ui
