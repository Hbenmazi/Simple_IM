# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Simple_IM
DESTDIR = ../x64/Debug
QT += core sql gui widgets webchannel websockets network
QT += network
CONFIG += debug
DEFINES += WIN64 QT_DLL QT_SQL_LIB QT_WEBCHANNEL_LIB QT_WEBSOCKETS_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(Simple_IM.pri)
