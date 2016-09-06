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
        afma_mainwindow.cpp \
    afma_2d_mainwindow.cpp \
    afma_3d_mainwindow.cpp \
    utility2d.cpp \
    openglwindow.cpp \
    facemodelcandide.cpp \
    openglannotationwindow.cpp \
    facecomponent.cpp \
    animationdialog.cpp

HEADERS  += afma_mainwindow.h \
    afma_2d_mainwindow.h \
    afma_3d_mainwindow.h \
    utility2d.h \
    openglwindow.h \
	glm\vec3.hpp \
    facemodelcandide.h \
    openglannotationwindow.h \
    facecomponent.h \
    animationdialog.h

FORMS    += afma_mainwindow.ui \
    afma_2d_mainwindow.ui \
    afma_3d_mainwindow.ui

INCLUDEPATH += D:\\Programme\\opencv\\mybuild\\install\\include \
D:\Programme\glm-0.9.7.5\glm \


LIBS += -LD:\Qt\5.5\mingw492_32\lib\libQt5OpenGL.a -lopengl32\
-LD:\\Programme\\opencv\\mybuild\\lib\\Debug \
-lopencv_videostab310d \
-lopencv_stitching310d \
-lopencv_calib3d310d \
-lopencv_ts310d \
-lopencv_features2d310d \
-lopencv_objdetect310d \
-lopencv_highgui310d \
-lopencv_superres310d \
-lopencv_videoio310d \
-lopencv_imgcodecs310d \
-lopencv_shape310d \
-lopencv_photo310d \
-lopencv_video310d \
-lopencv_imgproc310d \
-lopencv_flann310d \
-lopencv_ml310d \
-lopencv_core310d 


DISTFILES += \
    images/biometrisches-passbild-fotostudio-bretten.jpg \
    images/black.jpg \
    images/Claudia01.jpg \
    images/images.jpg \
    images/passbild 2.jpg \
    images/Passbild_04.jpg \
    images/Passbild01.jpg \
    images/Result of passbild 2-2.jpg \
    images/Png.PNG \
    images/Unbenannt.PNG \
    images/images edges.tif \
    images/images grey 2.tif \
    images/images grey cut.tif \
    images/images grey.tif \
    images/images-1.tif \
    images/images-binary.tif \
    images/passbild 2 grey.tif \
    images/passbild 2 grey-1.tif \
    images/passbild 2-2.tif \
    images/Result of passbild 2-2.tif \
    modelfragmentshader.frag \
    modelvertexshader.vert \
    annotationvertexshader.vert \
    annotationfragmentshader.frag
