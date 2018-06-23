QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DMTool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        dbmanager.cpp \
    helper/appinit.cpp \
    helper/confighelper.cpp \
    helper/iconhelper.cpp \
    uifile/syssetwidget.cpp \
    uifile/infotablewidget.cpp \
    uifile/dataentrywidget.cpp \
    uifile/infoquerywidget.cpp \
    uifile/dataexportwidget.cpp \
    uifile/addorupdatecolumnwidget.cpp

HEADERS  += dbmanager.h \
    helper/appinit.h \
    helper/confighelper.h \
    helper/iconhelper.h \
    helper/myhelper.h \
    uifile/syssetwidget.h \
    uifile/infotablewidget.h \
    uifile/dataentrywidget.h \
    uifile/infoquerywidget.h \
    uifile/dataexportwidget.h \
    uifile/addorupdatecolumnwidget.h

FORMS    += dbmanager.ui \
    uifile/syssetwidget.ui \
    uifile/infotablewidget.ui \
    uifile/dataentrywidget.ui \
    uifile/infoquerywidget.ui \
    uifile/dataexportwidget.ui \
    uifile/addorupdatecolumnwidget.ui


MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = bin

RESOURCES += \
    qss.qrc \
    resource.qrc
