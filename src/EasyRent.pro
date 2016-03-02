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

SOURCES += RealEstateQuery.cpp \
    main.cpp \
    MainWindow.cpp \
    FormUserQueries.cpp \
    RealEstateQueryModel.cpp \
    CreateUserQueryDialog.cpp

HEADERS += RealEstateQuery.h \
    MainWindow.h \
    FormUserQueries.h \
    RealEstateQueryModel.h \
    CreateUserQueryDialog.h

OTHER_FILES +=

CONFIG += c++11

FORMS += \
    MainWindow.ui \
    FormUserQueries.ui \
    CreateUserQueryDialog.ui

RESOURCES += \
    resources.qrc
