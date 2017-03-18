TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Game.cpp \
    Input.cpp \
    Menu.cpp \
    TextRender.cpp \
    Level.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Game.h \
    Globals.h \
    Input.h \
    Menu.h \
    TextRender.h \
    Level.h

LIBS += -lSDL2 -lSDL2_ttf -lSDL2_image

QMAKE_CXXFLAGS += -std=c++11
