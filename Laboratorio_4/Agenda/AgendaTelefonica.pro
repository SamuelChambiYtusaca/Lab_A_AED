QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agenda.cpp \
    agregar.cpp \
    cola.cpp \
    contacto.cpp \
    main.cpp \
    mainwindow.cpp \
    mostrar.cpp \
    node.cpp

HEADERS += \
    agenda.h \
    agregar.h \
    cola.h \
    contacto.h \
    mainwindow.h \
    mostrar.h \
    node.h

FORMS += \
    agregar.ui \
    mainwindow.ui \
    mostrar.ui

RC_ICONS = 7600154_icon.ico
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc
