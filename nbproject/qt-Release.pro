# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/MinGW-Windows
TARGET = KPaths
VERSION = 20.16.0421
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += LASD/GB/GB.c LASD/Strutture/Grafo.c LASD/Strutture/Heap.c LASD/Strutture/Lista.c LASD/Strutture/ListaDP.c LASD/Strutture/PriorityQueue.c LASD/Strutture/Queue.c LASD/Strutture/Set.c LASD/Strutture/Stack.c LASD/Strutture/Vector.c QGraphicsViewEc.cpp fAbout.cpp fArco.cpp fDatiGrafoCasuale.cpp fDettaglioNodo.cpp fDotLanguage.cpp fGraphDesign.cpp fKPercorsi.cpp fPercorso.cpp main.cpp
HEADERS += LASD/Headers/Grafo.h LASD/Headers/Heap.h LASD/Headers/Lista.h LASD/Headers/ListaDP.h LASD/Headers/PriorityQueue.h LASD/Headers/Queue.h LASD/Headers/Set.h LASD/Headers/Stack.h LASD/Headers/Vector.h QGraphicsViewEc.h fAbout.h fArco.h fDatiGrafoCasuale.h fDettaglioNodo.h fDotLanguage.h fGraphDesign.h fKPercorsi.h fPercorso.h
FORMS += fAbout.ui fArco.ui fDatiGrafoCasuale.ui fDettaglioNodo.ui fDotLanguage.ui fGraphDesign.ui fKPercorsi.ui fPercorso.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/MinGW-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../QGVCore/QGVCore ../QGVCore/QGVCore/private 
LIBS += -L"../QGVCore/lib" -lQGVCore  
