TEMPLATE = app
CONFIG += console
CONFIG += app_bundle
CONFIG += c++11
CONFIG += qt

QT += xml
QT += xmlpatterns

TARGET = clientcpp

SOURCES += \
    client.cpp \
    main.cpp

HEADERS += \
    client.h
