QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TARGET      = styledemo
TEMPLATE    = app
DESTDIR     = $$PWD/../bin

SOURCES     += main.cpp
HEADERS     += frmmain.h
SOURCES     += frmmain.cpp
FORMS       += frmmain.ui

RESOURCES   += $$PWD/../ui/qrc/qss.qrc
RESOURCES   += $$PWD/../ui/qrc/qm.qrc
RESOURCES   += $$PWD/../ui/qrc/font.qrc
RESOURCES   += $$PWD/../ui/qrc/main.qrc

INCLUDEPATH += $$PWD
