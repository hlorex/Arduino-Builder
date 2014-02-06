TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp

HEADERS += \
    common.h \
    mainwindow.h

contains(QT_VERSION, ^5.*) {
    QT += widgets
}
