
TEMPLATE = app

CONFIG += qt c++11
CONFIG -= debug_and_release debug_and_release_target
QT += widgets
QT += core gui

HEADERS += $$files(Source/*.h, true)
SOURCES += $$files(Source/*.cpp, true)

QMAKE_CXXFLAGS += /wd4250 /wd4800 /wd5030

INCLUDEPATH += Source

RESOURCES = ameba.qrc

include(deployment.pri)
