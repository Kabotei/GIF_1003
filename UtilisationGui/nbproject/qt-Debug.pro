# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = UtilisationGui
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjouterJournalInterface.cpp AjouterOuvrageInterface.cpp BibliographieInterface.cpp SupprimerReferenceInterface.cpp main.cpp
HEADERS += AjouterJournalInterface.h AjouterOuvrageInterface.h BibliographieInterface.h SupprimerReferenceInterface.h
FORMS += AjouterJournalInterface.ui AjouterOuvrageInterface.ui BibliographieInterface.ui SupprimerReferenceInterface.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-10
DEFINES += 
INCLUDEPATH += ../source 
LIBS += ../source/dist/Debug/GNU-Linux/libsource.a  
