DEFINES += QT5
QT       += core gui widgets 
#QT       += webkitwidgets
QT       += webenginewidgets

include(QSingleInstance/de_skycoder42_qsingleinstance.pri)
include(qtterminalwidget/qtterminalwidget.pri)


#CONFIG += c++11

# Pour QTermWidget
INCLUDEPATH +=  QSingleInstance /usr/include/x86_64-linux-gnu/qt5/QtWebKit/


#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets
#greaterThan(QT_MAJOR_VERSION, 5): QT += webenginewidgets

CONFIG += g++

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    parametermanager.cpp \
    templateEngineQt.cpp 


HEADERS += \
    mainwindow.h \
    parametermanager.h \
    templateEngineQt.h

LIBS +=  -L/home/charles/MYSTUFF/BACKUP2/C++/QT/termweb/termweb2/qtterminalwidget
LIBS +=  -lqtterminalwidget

CONFIG(debug, debug|release) {
    DESTDIR = ../../
} else {
    DESTDIR = ../../
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
