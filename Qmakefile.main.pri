QT += core gui widgets
TARGET = QtFE
VERSION = 0.0.0
TEMPLATE = app

INCLUDEPATH += $$PWD/include

#HEADERS += 	include/mainwindow.h	include/abstract_mainwindow_controller.h	include/mainwindow_controller_without_tabs.h	include/foldertree_controller.h	include/filelist_controller.h	include/foldertree_model.h	include/filelist_model.h	include/filesystem_controller.h

#SOURCES +=	src/main.cpp	src/mainwindow.cpp	src/abstract_mainwindow_controller.cpp	src/mainwindow_controller_without_tabs.cpp	src/foldertree_controller.cpp	src/filelist_controller.cpp	src/foldertree_model.cpp	src/filelist_model.cpp	src/filesystem_controller.cpp

HEADERS += \
include/mainwindow.h \
include/abstract_mainwindow_controller.h \
include/mainwindow_controller_without_tabs.h \
include/foldertree_controller.h \
include/abstract_foldertree_item.h \
include/foldertree_folder.h \
include/foldertree_entry.h \
include/filelist_controller.h \


SOURCES += \
src/main.cpp \
src/mainwindow.cpp \
src/abstract_mainwindow_controller.cpp \
src/mainwindow_controller_without_tabs.cpp \
src/foldertree_controller.cpp \
src/abstract_foldertree_item.cpp \
src/foldertree_folder.cpp \
src/foldertree_entry.cpp \
src/filelist_controller.cpp \


#RESOURCES = rc/reosurce.qrc

FORMS += ui/mainwindow_without_tabs.ui
