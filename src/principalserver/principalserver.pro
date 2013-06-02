TEMPLATE = app
CONFIG += console
CONFIG += app_bundle
CONFIG += c++11
CONFIG += qt

QT += xml

TARGET = principalserver

include(../binaryoperations/binaryoperations.pri)
include(../md5/md5.pri)
include(../networkhandler/networkhandler.pri)
include(../structures/structures.pri)
include(../tokenizer/tokenizer.pri)
include(../util/util.pri)
include(../xml/xml.pri)

SOURCES += \
    servernetworkhandler.cpp \
    serveroperations.cpp \
    noraid.cpp \
    registerspace.cpp \
    session.cpp \
    main.cpp

HEADERS += \
    diskgroup.h \
    servernetworkhandler.h \
    serveroperations.h \
    session.h \
    noraid.h \
    registerspace.h \
    registerbuffer.h

