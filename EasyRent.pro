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
    PropertyStorage.cpp \
    FormPriorityCreate.cpp \
    GlobalDataManager.cpp \
    PriorityQuery.cpp \
    AbstractQuery.cpp \
    ResponseQuery.cpp \
    Tools/ContainerUtils.cpp \
    MainWindow.cpp \
    FormPriorityShow.cpp \
    AppInfo.cpp

HEADERS  += \
    Queries.h \
    PropertyStorage.h \
    FormPriorityCreate.h \
    GlobalDataManager.h \
    PriorityQuery.h \
    AbstractQuery.h \
    ResponseQuery.h \
    Tools/ContainerUtils.h \
    MainWindow.h \
    FormPriorityShow.h \
    Interfaces.h \
    AppInfo.h

FORMS    += \
    FormPriorityShow.ui \
    MainWindow.ui

RESOURCES += \
    resources.qrc
