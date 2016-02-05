#-------------------------------------------------
#
# Project created by QtCreator 2014-02-24T01:51:24
#
#-------------------------------------------------

QT       += core gui quick
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyRent
TEMPLATE = app

SOURCES += main.cpp\
    PropertyStorage.cpp \
    PriorityQuery.cpp \
    ResponseQuery.cpp \
    MainWindow.cpp \
    FormPriorityShow.cpp \
    AppInfo.cpp \
    FormPriorityCreate.cpp \
    AuthWidget.cpp \
    AuthUnit.cpp \
    WgtRegisterUser.cpp \
    Location.cpp \
    RealEstateQuery.cpp

HEADERS  += \
    Queries.h \
    PropertyStorage.h \
    PriorityQuery.h \
    ResponseQuery.h \
    MainWindow.h \
    FormPriorityShow.h \
    Interfaces.h \
    AppInfo.h \
    FormPriorityCreate.h \
    AuthWidget.h \
    AuthUnit.h \
    WgtRegisterUser.h \
    Location.h \
    RealEstateQuery.h

FORMS    += \
    FormPriorityShow.ui \
    FormPriorityCreate.ui \
    AuthWidget.ui \
    WgtRegisterUser.ui \
    MainWindow.ui

RESOURCES += \
    resources.qrc

OTHER_FILES +=
