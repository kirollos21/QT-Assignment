QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    booksdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    User.cpp \
    purchaseddialog.cpp

HEADERS += \
    booksdialog.h \
    mainwindow.h \
    User.h \
    purchaseddialog.h

FORMS += \
    booksdialog.ui \
    mainwindow.ui \
    purchaseddialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
