TEMPLATE = app
CONFIG += console
CONFIG += app_bundle
CONFIG += c++11
CONFIG += qt

QT += xml

TARGET = principalserver



SOURCES += \
    servernetworkhandler.cpp \
    serveroperations.cpp \
    noraid.cpp \
    registerspace.cpp \
    session.cpp \
    main.cpp \
    generalmanager.cpp

HEADERS += \
    diskgroup.h \
    servernetworkhandler.h \
    serveroperations.h \
    session.h \
    noraid.h \
    registerspace.h \
    registerbuffer.h \
    generalmanager.h

