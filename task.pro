TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

contains(QT_VERSION, ^5.*) {
    QT += widgets
}
