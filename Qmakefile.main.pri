QT += core gui widgets
TARGET = QtFE
VERSION = 0.0.0
TEMPLATE = app

INCLUDEPATH += $$PWD/include

HEADERS += 	include/mainwindow.h	include/abstract_mainwindow_controller.h	include/mainwindow_controller_without_tabs.h	include/foldermodel.h	include/filelistmodel.h	include/filesystem_controller.h

SOURCES +=	src/main.cpp	src/mainwindow.cpp	src/abstract_mainwindow_controller.cpp	src/mainwindow_controller_without_tabs.cpp	src/foldermodel.cpp	src/filelistmodel.cpp	src/filesystem_controller.cpp

#RESOURCES = rc/reosurce.qrc

FORMS += ui/mainwindow_without_tabs.ui
