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
    facecomponent2d.cpp \
    facemodel2d.cpp \
    afma_2d_imagedisplay.cpp \
    grid2d.cpp

HEADERS  += afma_mainwindow.h \
    afma_2d_mainwindow.h \
    afma_3d_mainwindow.h \
    utility2d.h \
    facecomponent2d.h \
    facemodel2d.h \
    afma_2d_imagedisplay.h \
    grid2d.h

FORMS    += afma_mainwindow.ui \
    afma_2d_mainwindow.ui \
    afma_3d_mainwindow.ui

INCLUDEPATH += D:\\Programme\\opencv\\mybuild\\install\\include

LIBS += -LD:\\Programme\\opencv\\mybuild\\lib\\Debug \
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
    haarcascades/haarcascade_eye.xml \
    haarcascades/haarcascade_eye_tree_eyeglasses.xml \
    haarcascades/haarcascade_frontalcatface.xml \
    haarcascades/haarcascade_frontalcatface_extended.xml \
    haarcascades/haarcascade_frontalface_alt.xml \
    haarcascades/haarcascade_frontalface_alt_tree.xml \
    haarcascades/haarcascade_frontalface_alt2.xml \
    haarcascades/haarcascade_frontalface_default.xml \
    haarcascades/haarcascade_fullbody.xml \
    haarcascades/haarcascade_lefteye_2splits.xml \
    haarcascades/haarcascade_licence_plate_rus_16stages.xml \
    haarcascades/haarcascade_lowerbody.xml \
    haarcascades/haarcascade_profileface.xml \
    haarcascades/haarcascade_righteye_2splits.xml \
    haarcascades/haarcascade_russian_plate_number.xml \
    haarcascades/haarcascade_smile.xml \
    haarcascades/haarcascade_upperbody.xml \
    images/biometrisches-passbild-fotostudio-bretten.jpg \
    images/black.jpg \
    images/Claudia01.jpg \
    images/images.jpg \
    images/passbild 2.jpg \
    images/Passbild_04.jpg \
    images/Passbild01.jpg \
    images/Result of passbild 2-2.jpg \
    images/Vroni, 2015, Öl auf Leinwand, 180 x 230 cm.jpg \
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
    images/Result of passbild 2-2.tif



