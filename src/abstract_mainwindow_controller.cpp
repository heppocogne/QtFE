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
	const QString path=currentDirModel()->fileInfo(index).absoluteFilePath();
	currentListView()->setRootIndex(currentFileSystemModel()->setRootPath(path));
}


QDirModel* AbstractMainWindowController::currentDirModel()const
{
	return dynamic_cast<QDirModel*>(currentTreeView()->model());
}


QFileSystemModel* AbstractMainWindowController::currentFileSystemModel()const
{
	return dynamic_cast<QFileSystemModel*>(currentListView()->model());
}