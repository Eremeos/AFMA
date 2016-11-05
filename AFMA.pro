#-------------------------------------------------
#
# Project created by QtCreator 2016-03-17T15:51:57
#
#-------------------------------------------------

QT       += core gui opengl 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AFMA
TEMPLATE = app
CONFIG += debug

SOURCES += main.cpp\
    afma_2d_mainwindow.cpp \
    openglwindow.cpp \
    facemodelcandide.cpp \
    openglannotationwindow.cpp \
    facecomponent.cpp \
    animationdialog.cpp

HEADERS  += \
    afma_2d_mainwindow.h \
    openglwindow.h \
	glm\vec3.hpp \
    facemodelcandide.h \
    openglannotationwindow.h \
    facecomponent.h \
    animationdialog.h

FORMS    += \
    afma_2d_mainwindow.ui

INCLUDEPATH += D:\\Programme\\opencv\\mybuild\\install\\include \
D:\Programme\glm-0.9.7.5\glm \




DISTFILES += \
    modelfragmentshader.frag \
    modelvertexshader.vert \
    annotationvertexshader.vert \
    annotationfragmentshader.frag
