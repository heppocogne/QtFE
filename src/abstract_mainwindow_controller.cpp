#include "abstract_mainwindow_controller.h"

#include <QListView>
#include <QTreeView>
#include <QFileSystemModel>
#include <QMainWindow>
#include <QMenu>
#include <QString>
#include <QFileInfo>

#include "foldermodel.h"
#include "filelistmodel.h"
#include "filesystem_controller.h"

using namespace QtFE;

AbstractMainWindowController::AbstractMainWindowController(QObject* parent)
	:QObject(parent),
	folderMenu(new QMenu(dynamic_cast<QMainWindow*>(parent))),
	fileController(new FileSystemController(this))
{
	
}


AbstractMainWindowController::~AbstractMainWindowController()
{
	
}


void AbstractMainWindowController::selectFolder(const QModelIndex &index)
{
	const QString path=currentFolderModel()->itemFromIndex(index)->accessibleDescription();
	currentListView()->setRootIndex(currentFileSystemModel()->setRootPath(path));
}


void AbstractMainWindowController::expandFolder(const QModelIndex& index)
{
	auto* const item=currentFolderModel()->itemFromIndex(index);
	dynamic_cast<FolderModel*>(currentFolderModel())->appendExistingChildren(item, 1);
}


void AbstractMainWindowController::openItem(const QModelIndex& index)
{
	auto* const item=currentFolderModel()->itemFromIndex(index);
	const QString path=item->accessibleDescription();
	
	const QFileInfo fileInfo(path);
	if(fileInfo.isDir())
		expandFolder(index);
	else if(fileInfo.isFile())
		fileController->openFile(path);
}


FolderModel* AbstractMainWindowController::currentFolderModel()const
{
	return dynamic_cast<FolderModel*>(currentTreeView()->model());
}

FileListModel* AbstractMainWindowController::currentFileSystemModel()const
{
	return dynamic_cast<FileListModel*>(currentListView()->model());
}
/*
QFileSystemModel* AbstractMainWindowController::currentFileSystemModel()const
{
	return dynamic_cast<QFileSystemModel*>(currentListView()->model());
}
*/