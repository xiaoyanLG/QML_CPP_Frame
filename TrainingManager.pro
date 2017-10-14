#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T19:06:56
#
#-------------------------------------------------

QT       += core gui quickwidgets sql xml printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainingManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xycourseinfo.cpp \
    xydatabase.cpp \
    xymysql.cpp \
    xypicprinter.cpp \
    xyqmlloader.cpp \
    xyqmlsingleobject.cpp \
    xyqmlsinglerealobject.cpp \
    xyserveinfo.cpp \
    xysqlitebase.cpp \
    xystudentinfo.cpp

HEADERS  += mainwindow.h \
    version.h \
    xystudentinfo.h \
    xysqliteexpression.h \
    xysqlitebase.h \
    xyserveinfo.h \
    xyqmlsinglerealobject.h \
    xyqmlsingleobject.h \
    xyqmlloader.h \
    xypicprinter.h \
    xymysql.h \
    xydatabase.h \
    xycourseinfo.h

RESOURCES += \
    qml/qml.qrc \
    images/images.qrc

RC_FILE = ico.rc
