
#可以指定不加载对应的资源文件
RESOURCES += $$PWD/qrc/image.qrc
RESOURCES += $$PWD/qrc/qm.qrc
RESOURCES += $$PWD/qrc/font.qrc
RESOURCES += $$PWD/qrc/main.qrc
RESOURCES += $$PWD/qrc/qss.qrc

SOURCES += \
    $$PWD/quihelper.cpp\
    $$PWD/iconhelper.cpp

HEADERS += \
    $$PWD/quihelper.h\
    $$PWD/iconhelper.h


# 软件图标
RC_ICONS    = $$PWD/image/myico.ico
