TEMPLATE = app
CONFIG += console
CONFIG += app_bundle
CONFIG += c++11
CONFIG += qt

QT += xml

TARGET = lssprovider


SOURCES += \
    lss.cpp \
    lssnetworkhandler.cpp \
    lssoperations.cpp \
    lssmanager.cpp \
    lssconsole.cpp \
    lssmain.cpp \
    lssxml.cpp \
    main.cpp

HEADERS += \
    lss.h \
    lssnetworkhandler.h \
    lssoperations.h \
    lssmanager.h \
    info.h \
    lssconsole.h \
    lssxml.h \
