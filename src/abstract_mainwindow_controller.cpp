#include "abstract_mainwindow_controller.h"

#include <QListView>
#include <QTreeView>
#include <QFileSystemModel>
#include <QMainWindow>
#include <QMenu>
#include <QString>
#include <QFileInfo>

//#include "foldermodel.h"
//#include "filelistmodel.h"
//#include "filesystem_controller.h"

using namespace QtFE;

AbstractMainWindowController::AbstractMainWindowController(QWidget* parent)
	:QObject(parent)
{
	
}


AbstractMainWindowController::~AbstractMainWindowController()
{
	
}

