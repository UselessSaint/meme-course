#-------------------------------------------------
#
# Project created by QtCreator 2019-10-27T23:26:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseWork
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    RayTrace/raytrace.cpp \
        drawlabel.cpp \
        main.cpp \
        mainwindow.cpp \
        math/face.cpp \
        math/mesh.cpp \
        math/point.cpp \
    objects/parallelepiped.cpp \
        objects/sphere.cpp \
    render/renderer.cpp \
    scene/light.cpp \
    scene/scene.cpp \
    z_buffer/zbuffer.cpp

HEADERS += \
        RayTrace/raytrace.h \
        drawlabel.h \
        mainwindow.h \
        math/face.h \
        math/mesh.h \
        math/point.h \
        objects/object.h \
        objects/parallelepiped.h \
        objects/sphere.h \
        render/renderer.h \
        scene/light.h \
        scene/scene.h \
        z_buffer/zbuffer.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
