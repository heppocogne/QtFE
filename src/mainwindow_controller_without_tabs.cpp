#include "mainwindow_controller_without_tabs.h"
#include "ui_mainwindow_without_tabs.h"

#include <QTimer>

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
	//QStandardItemModel* fsmodel=new FolderModel(this);
	//fsmodel->setOptions(QFileSystemModel::DontWatchForChanges);
	ui.fileList->setModel(fsmodel);
	currentFileList=ui.fileList;
	
	FolderModel* const dmodel=new FolderModel(this);
	/*
	dmodel->setRootPath(":");
	dmodel->setFilter(QDir::AllDirs|QDir::NoDotAndDotDot|QDir::Dirs|QDir::Drives|QDir::CaseSensitive);
	dmodel->setOptions(QFileSystemModel::DontWatchForChanges);
	dmodel->sort(0);
	*/
	/*
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/OneDrive"));
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/3D Objects"));
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/Downloads"));
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/Desktop"));
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/Documents"));
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/Pictures"));
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/Videos"));
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/Music"));
	dmodel->appendFolderEntry(QDir("C:/"), "Windows (C:)");
	dmodel->appendFolderEntry(QDir("D:/"), "Lenovo (D:)");
	dmodel->appendFolderEntry(QDir("G:/"), "Google Drive (G:)");
	*/
	dmodel->appendFolderEntry(QDir("C:/OpenJDK"), "OpenJDK");
	dmodel->appendFolderEntry(QDir("C:/Users/usk10/GodotProjects"), "GodotProjects");
	
	//dmodel->appendExistingChildren(dmodel->invisibleRootItem(), 2);
	
	ui.folderTree->setModel(dmodel);
//	ui.folderTree->hideColumn(1);
//	ui.folderTree->hideColumn(2);
//	ui.folderTree->hideColumn(3);
	ui.folderTree->setHeaderHidden(true);
	currentFolderTree=ui.folderTree;
	
	connect(ui.folderTree, &QTreeView::clicked, this, &MainWindowController_without_tabs::selectFolder);
	connect(ui.folderTree, &QTreeView::expanded, this, &MainWindowController_without_tabs::expandFolder);
	connect(dmodel, &QStandardItemModel::itemChanged, );
	//connect(dmodel, &FolderModel::itemUpdated, ui.folderTree, QOverload<const QModelIndex&>::of(&QAbstractItemView::update));
}


QTreeView* MainWindowController_without_tabs::currentTreeView(void)const
{
	return currentFolderTree;
}


QListView* MainWindowController_without_tabs::currentListView(void)const
{
	return currentFileList;
}
