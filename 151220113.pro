#-------------------------------------------------
#
# Project created by QtCreator 2018-04-25T10:38:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 151220113
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    openglwidget.cpp \
    type.cpp \
    LineList.cpp \
    Line.cpp \
    editdialog.cpp \
    editlinedialog.cpp \
    changelinedialog.cpp \
    rotatelinedialog.cpp \
    tranlinedialog.cpp \
    scalelinedialog.cpp \
    circle.cpp \
    circlelist.cpp \
    myshape.cpp \
    editcircledialog.cpp \
    changecircledialog.cpp \
    trancircledialog.cpp \
    scalecircledialog.cpp \
    ellipse.cpp \
    ellipselist.cpp \
    editellipsedialog.cpp \
    changeellipsedialog.cpp \
    tranellipsedialog.cpp \
    scaleellipsedialog.cpp \
    curve.cpp \
    curvelist.cpp \
    editcurvedialog.cpp

HEADERS  += mainwindow.h \
    openglwidget.h \
    type.h \
    editdialog.h \
    editlinedialog.h \
    changelinedialog.h \
    rotatelinedialog.h \
    tranlinedialog.h \
    scalelinedialog.h \
    line.h \
    linelist.h \
    circle.h \
    circlelist.h \
    myshape.h \
    editcircledialog.h \
    changecircledialog.h \
    trancircledialog.h \
    scalecircledialog.h \
    ellipse.h \
    ellipselist.h \
    editellipsedialog.h \
    changeellipsedialog.h \
    tranellipsedialog.h \
    scaleellipsedialog.h \
    curve.h \
    curvelist.h \
    editcurvedialog.h

FORMS    += mainwindow.ui \
    editdialog.ui \
    editlinedialog.ui \
    changelinedialog.ui \
    rotatelinedialog.ui \
    tranlinedialog.ui \
    scalelinedialog.ui \
    editcircledialog.ui \
    changecircledialog.ui \
    trancircledialog.ui \
    scalecircledialog.ui \
    editellipsedialog.ui \
    changeellipsedialog.ui \
    tranellipsedialog.ui \
    scaleellipsedialog.ui \
    editcurvedialog.ui
LIBS += -lOpengl32 \
        -lglu32 \
        -lglut
