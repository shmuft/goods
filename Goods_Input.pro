#-------------------------------------------------
#
# Project created by QtCreator 2016-02-04T10:33:57
#
#-------------------------------------------------

QT       += core gui sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Goods_Input
TEMPLATE = app
VERSION = 0.0.1
SOURCES += main.cpp\
    egais.cpp \
    good_input.cpp \
    goods_card.cpp

HEADERS  += \
    egais.h \
    good_input.h \
    goods_card.h

FORMS    += \
    good_input.ui \
    goods_card.ui
