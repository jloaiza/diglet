TEMPLATE = app
CONFIG += console
CONFIG += app_bundle
CONFIG -= qt
CONFIG += c++11

TARGET = clientcpp

SOURCES += \
    client.cpp \
    main.cpp

HEADERS += \
    client.h
