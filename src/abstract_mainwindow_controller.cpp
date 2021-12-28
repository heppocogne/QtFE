#include "abstract_mainwindow_controller.h"

using namespace QtFE;

AbstractMainWindowController::AbstractMainWindowController(QObject* parent)
	:QObject(parent),
	folderMenu(new QMenu(dynamic_cast<QMainWindow*>(parent)))
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


FolderModel* AbstractMainWindowController::currentFolderModel()const
{
	return dynamic_cast<FolderModel*>(currentTreeView()->model());
}

QFileSystemModel* AbstractMainWindowController::currentFileSystemModel()const
{
	return dynamic_cast<QFileSystemModel*>(currentListView()->model());
}