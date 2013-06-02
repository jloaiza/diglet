TEMPLATE = app
CONFIG += console
CONFIG += app_bundle
CONFIG += -qt

TARGET = principalserver

SOURCES += \
    servernetworkhandler.cpp \
    serveroperations.cpp \
    noraid.cpp \
    registerspace.cpp \
    session.cpp

HEADERS += \
    diskgroup.h \
    servernetworkhandler.h \
    serveroperations.h \
    session.h \
    noraid.h \
    registerspace.h \
    registerbuffer.h

