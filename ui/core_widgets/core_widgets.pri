#SOURCES += \
#    $$PWD/xxx.cpp\
#    $$PWD/xxx.cpp

HEADERS += \
    $$PWD/ylistwidget.h\
    $$PWD/ipaddress.h\
    $$PWD/savelog.h

INCLUDEPATH += $$PWD

CONFIG(debug, debug|release) {
LIBS += -L$$PWD/ -lqucd
} else {
LIBS += -L$$PWD/ -lquc
}

CONFIG(release, debug|release) {
win32 {
src_file = $$PWD/quc.dll
dst_file = $(DESTDIR)
src_file ~= s,/,\\,g
dst_file ~= s,/,\\,g
dst_file2 ~= s,/,\\,g
QMAKE_POST_LINK += copy $$src_file $$dst_file
}
}

CONFIG(debug, debug|release) {
win32 {
src_file = $$PWD/qucd.dll
dst_file = $(DESTDIR)
src_file ~= s,/,\\,g
dst_file ~= s,/,\\,g
dst_file2 ~= s,/,\\,g
QMAKE_POST_LINK += copy $$src_file $$dst_file
}
}
