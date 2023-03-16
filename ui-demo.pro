#################################################
#
#                  工程配置文件
#
#################################################


TARGET      = creekwater    # 指定生成的应用程序名和图标
TEMPLATE    = app           # 工程所使用的模版;app表示是应用程序;lib则表明是库

QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

################  编译生成的路径  #################
#临时文件存放位置
MOC_DIR         = tmp/moc  # 指定moc命令将含Q_OBJECT的头文件转换成标准.h文件的存放目录
RCC_DIR         = tmp/rcc  # 指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
UI_DIR          = tmp/ui   # 指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
OBJECTS_DIR     = tmp/obj  # 指定目标文件(obj)的存放目录

#指定编译生成的可执行文件目录
!android {
!wasm {
DESTDIR = $$PWD/build/bin
}}
#################################################


#把所有警告都关掉眼不见为净
CONFIG += warn_off
#开启大资源支持
CONFIG += resources_big
#开启后会将打印信息用控制台输出
#CONFIG += console
#开启后不会生成空的 debug release 目录
#CONFIG -= debug_and_release

#SOURCES     += main.cpp


INCLUDEPATH += $$PWD

INCLUDEPATH += $$PWD/app
include ($$PWD/app/app.pri)

INCLUDEPATH += $$PWD/ui
include ($$PWD/ui/ui.pri)

INCLUDEPATH += $$PWD/form
include ($$PWD/form/form.pri)

#INCLUDEPATH += $$PWD/styledemo
#include ($$PWD/styledemo/styledemo.pri)
