TEMPLATE = app
CONFIG += console
CONFIG += app_bundle
CONFIG += -qt

TARGET = lssprovider

include(../binaryoperations/binaryoperations.pri)
include(../md5/md5.pri)
include(../networkhandler/networkhandler.pri)
include(../structures/structures.pri)
include(../tokenizer/tokenizer.pri)
include(../util/util.pri)
include(../xml/xml.pri)

SOURCES += \
    lss.cpp \
    lssnetworkhandler.cpp \
    lssoperations.cpp \
    lssmanager.cpp \
    lssconsole.cpp \
    lssmain.cpp \
    lssxml.cpp

HEADERS += \
    lss.h \
    lssnetworkhandler.h \
    lssoperations.h \
    lssmanager.h \
    info.h \
    lssconsole.h \
    lssxml.h
