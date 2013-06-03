TEMPLATE = subdirs
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

CONFIG += qt
QT += xmlpatterns


SUBDIRS += \
    src/principalserver \
    src/clientcpp \
    src/lss \
    src/misc.pro


