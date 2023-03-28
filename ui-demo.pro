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

MOC_DIR         = $$PWD/build/tmp/moc  
RCC_DIR         = $$PWD/build/tmp/rcc  
UI_DIR          = $$PWD/build/tmp/ui
OBJECTS_DIR     = $$PWD/build/tmp/obj  


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
CONFIG += console
#开启后不会生成空的 debug release 目录
#CONFIG -= debug_and_release



include ($$PWD/ui/ui.pri)
include ($$PWD/form/form.pri)



