QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += QGVCore/
INCLUDEPATH += QGVCore/private/
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#GraphViz librairie
!include(GraphViz.pri) {
     error("fail open GraphViz.pri")
 }

SOURCES += \
    Dialog_Add_Activity.cpp \
    Dialog_Add_Component.cpp \
    Dialog_Add_Functionality.cpp \
    Dialog_Add_PluginInt.cpp \
    Dialog_Add_Port.cpp \
    Dialog_Add_Property.cpp \
    QGVCore/QGVEdge.cpp \
    QGVCore/QGVNode.cpp \
    QGVCore/QGVScene.cpp \
    QGVCore/QGVSubGraph.cpp \
    QGVCore/private/QGVCore.cpp \
    QGVCore/private/QGVEdgePrivate.cpp \
    QGVCore/private/QGVGraphPrivate.cpp \
    QGVCore/private/QGVGvcPrivate.cpp \
    QGVCore/private/QGVNodePrivate.cpp \
    QGraphicsViewEc.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CmpActivity.h \
    CmpFunctionality.h \
    CmpPlugin.h \
    CmpPort.h \
    CmpProperty.h \
    Component.h \
    Dialog_Add_Activity.h \
    Dialog_Add_Component.h \
    Dialog_Add_Functionality.h \
    Dialog_Add_PluginInt.h \
    Dialog_Add_Port.h \
    Dialog_Add_Property.h \
    QGVCore/QGVEdge.h \
    QGVCore/QGVNode.h \
    QGVCore/QGVScene.h \
    QGVCore/QGVSubGraph.h \
    QGraphicsViewEc.h \
    mainwindow.h

FORMS += \
    Dialog_Add_Activity.ui \
    Dialog_Add_Component.ui \
    Dialog_Add_Functionality.ui \
    Dialog_Add_PluginInt.ui \
    Dialog_Add_Port.ui \
    Dialog_Add_Property.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

