
CONFIG += qt
QT += xml
QT += xmlpatterns

HEADERS += $$PWD/parserxml.h \
    xml/usersxml.h \
    xml/diskgroupsxml.h \ 

SOURCES += $$PWD/parserxml.cpp \
    xml/usersxml.cpp \
    xml/diskgroupsxml.cpp \
