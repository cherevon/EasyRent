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

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    FormUserQueries.cpp \
    RealEstateObject.cpp \
    ResidentialRealEstateObject.cpp \
    RealEstateQuery.cpp \
    DlgUserQueryEditor.cpp \
    RealEstateQueryModel.cpp

HEADERS += \
    MainWindow.h \
    FormUserQueries.h \
    RealEstateObject.h \
    ResidentialRealEstateObject.h \
    RealEstateQuery.h \
    DlgUserQueryEditor.h \
    RealEstateQueryModel.h

OTHER_FILES +=

CONFIG += c++11

FORMS += \
    MainWindow.ui \
    FormUserQueries.ui \
    DlgUserQueryEditor.ui

RESOURCES += \
    resources.qrc
