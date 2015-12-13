#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T14:05:38
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = samuGUI
TEMPLATE = app
INCLUDEPATH  += /home/wazemaki/pr/pngwriter/include
INCLUDEPATH += /usr/include/freetype2
INCLUDEPATH += /usr/include/freetype2/config
INCLUDEPATH += /usr/include/boost
INCLUDEPATH += /usr/include

SOURCES += main.cpp\
        samugui.cpp \
    nlp.cpp \
    samu.cpp #\
    #qlc.cu

HEADERS  += samugui.h \
    disp.hpp \
    net.hpp \
    nlp.hpp \
    ql.hpp \
    #qlc.h \
    samu.hpp

FORMS    += samugui.ui

OTHER_FILES += \
    CMakeLists.txt
