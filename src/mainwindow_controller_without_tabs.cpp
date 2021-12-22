#include "mainwindow_controller_without_tabs.h"
#include "ui_mainwindow_without_tabs.h"

using namespace QtFE;

MainWindowController_without_tabs::MainWindowController_without_tabs(QObject* parent)
	:AbstractMainWindowController(parent)
{
	
}


MainWindowController_without_tabs::~MainWindowController_without_tabs()
{
	
}


void MainWindowController_without_tabs::setup()
{
	Ui::MainWindow_without_tabs ui;
	ui.setupUi(dynamic_cast<QMainWindow*>(parent()));
	
	QFileSystemModel* const fsmodel=new QFileSystemModel(this);
	ui.fileList->setModel(fsmodel);
	currentFileList=ui.fileList;
	
	QDirModel* const dmodel=new QDirModel(this);
	dmodel->setFilter(QDir::AllDirs|QDir::NoDotAndDotDot|QDir::Dirs|QDir::Drives|QDir::CaseSensitive);
	dmodel->setSorting(QDir::Name|QDir::IgnoreCase);
	ui.folderTree->setModel(dmodel);
	ui.folderTree->hideColumn(1);
	ui.folderTree->hideColumn(2);
	ui.folderTree->hideColumn(3);
	ui.folderTree->setHeaderHidden(true);
	currentFolderTree=ui.folderTree;
	
	connect(ui.folderTree, &QTreeView::clicked, this, &MainWindowController_without_tabs::selectFolder);
}


QTreeView* MainWindowController_without_tabs::currentTreeView(void)const
{
	return currentFolderTree;
}


QListView* MainWindowController_without_tabs::currentListView(void)const
{
	return currentFileList;
}