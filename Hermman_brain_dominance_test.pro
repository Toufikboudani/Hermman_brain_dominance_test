#-------------------------------------------------
#
# Project created by QtCreator 2017-08-01T09:20:00
#
#-------------------------------------------------
QT       += core gui
QT       += core
QT       -= gui
QT       += webkit webkitwidgets
QT       += xml
QT       += multimedia multimediawidgets
QT       += concurrent widgets

CONFIG += c++11
#CONFIG += c++11
#QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS+= -std=c++11
#QMAKE_LFLAGS +=  -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 
TARGET = Hermman_brain_dominance_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mygraph.cpp \
    dialogentredata.cpp \
    hbdtest.cpp \
    datatest.cpp \
    dialoginertdata.cpp \
    dialogabout.cpp \
    dialogaboutt.cpp \
    fields.cpp \
    htmlprepara.cpp \
    MyLabelWarning.cpp \
    mylabelwarningtimer.cpp \
    myqstandarditemmodel.cpp \
    mywstyle.cpp \
    qwidgetimage_border.cpp \
    write_read_file.cpp \
    mycomboboxdelegate.cpp \
    mainwindowinertdata.cpp \
    labellcdpopup.cpp \
    dialogentredataname.cpp \
    mainwindowhbdtest.cpp \
    qspinboxdelegate.cpp \
    dialogaddwigite.cpp

HEADERS  += mainwindow.h \
    mygraph.h \
    dialogentredata.h \
    hbdtest.h \
    datatest.h \
    dialoginertdata.h \
    dialogabout.h \
    dialogaboutt.h \
    fields.h \
    htmlprepara.h \
    MyLabelWarning.h \
    mylabelwarningtimer.h \
    myqstandarditemmodel.h \
    mywstyle.h \
    qwidgetimage_border.h \
    write_read_file.h \
    mycomboboxdelegate.h \
    mainwindowinertdata.h \
    labellcdpopup.h \
    dialogentredataname.h \
    mainwindowhbdtest.h \
    qspinboxdelegate.h \
    dialogaddwigite.h

FORMS    += mainwindow.ui \
    mygraph.ui \
    dialogentredata.ui \
    hbdtest.ui \
    dialoginertdata.ui \
    dialogabout.ui \
    dialogaboutt.ui \
    qwidgetimage_border.ui \
    mainwindowinertdata.ui \
    labellcdpopup.ui \
    dialogentredataname.ui \
    mainwindowhbdtest.ui \
    dialogaddwigite.ui

RESOURCES += \
    images.qrc


#win32{
#RC_FILE +=commercial_shop.rc
#}

win32{
RC_FILE +=Hermman_brain_dominance_test.rc
}
