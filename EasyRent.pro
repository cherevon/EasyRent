#-------------------------------------------------
#
# Project created by QtCreator 2014-02-24T01:51:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyRent
TEMPLATE = app


SOURCES += main.cpp\
    FormPriorityShow.cpp \
    MainForm.cpp \
    PropertyStorage.cpp \
    FormPriorityCreate.cpp \
    GlobalDataManager.cpp \
    PriorityQuery.cpp \
    AbstractQuery.cpp \
    ResponseQuery.cpp \
    Tools/ContainerUtils.cpp

HEADERS  += \
    Queries.h \
    MainForm.h \
    FormPriorityShow.h \
    PropertyStorage.h \
    FormPriorityCreate.h \
    GlobalDataManager.h \
    PriorityQuery.h \
    AbstractQuery.h \
    ResponseQuery.h \
    Tools/ContainerUtils.h \
    Tools/Interfaces.h

FORMS    +=
