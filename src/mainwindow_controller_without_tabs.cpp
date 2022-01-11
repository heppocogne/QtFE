#include "mainwindow_controller_without_tabs.h"
#include "ui_mainwindow_without_tabs.h"

#include <QMainWindow>
#include <QMenu>
#include <QString>
#include <QDir>
#include <QFileIconProvider>
//#include <QListWidget>
//#include <QTreeWidget>

//#include "foldertree_model.h"
//#include "filelist_model.h"

#include "foldertree_folder.h"
#include "foldertree_entry.h"
#include "foldertree_controller.h"


using namespace QtFE;

MainWindowController_without_tabs::MainWindowController_without_tabs(QWidget* parent)
	:AbstractMainWindowController(parent)
{
	Ui::MainWindow_without_tabs ui;
	ui.setupUi(dynamic_cast<QMainWindow*>(parent));
	
	fileList=ui.fileList;
	folderTree=ui.folderTree;
	
	folderTree->setHeaderHidden(true);
	treeController=new FolderTreeController(folderTree);
	
	AbstractFolderTreeItem* const oneDrive=new FolderTreeFolder(folderTree, "C:/Users/usk10/OneDrive", tr("OneDrive - Personal"));
	AbstractFolderTreeItem* const pc=new FolderTreeEntry(folderTree, "PC", AbstractFolderTreeItem::iconProvider->icon(QFileIconProvider::Computer));
	
	//These should be written in json or something like that
	new FolderTreeFolder(pc, "C:/Users/usk10/3D Objects",	tr("3D Objects"));
	new FolderTreeFolder(pc, "C:/Users/usk10/Downloads",	tr("Downloads"));
	new FolderTreeFolder(pc, "C:/Users/usk10/Desktop",			tr("Desktop"));
	new FolderTreeFolder(pc, "C:/Users/usk10/Documents",	tr("Documents"));
	new FolderTreeFolder(pc, "C:/Users/usk10/Pictures",			tr("Pictures"));
	new FolderTreeFolder(pc, "C:/Users/usk10/Videos",			tr("Videos"));
	new FolderTreeFolder(pc, "C:/Users/usk10/Music", 			tr("Music"));
	new FolderTreeFolder(folderTree, "C:/",								"Windows (C:)");
	new FolderTreeFolder(folderTree, "D:/",								"Lenovo (D:)");
	new FolderTreeFolder(folderTree, "G:/",								"Google Drive (G:)");
	
	//connect(ui.folderTree, &QTreeView::clicked, this, &MainWindowController_without_tabs::selectFolder);
	//connect(ui.folderTree, &QTreeView::expanded, this, &MainWindowController_without_tabs::expandFolder);
	
	//folderTree->addTopLevelItem(oneDrive);
	//filderTree->addToplevelItem();
	
	connect(folderTree, &QTreeWidget::itemExpanded, treeController, &FolderTreeController::onExpandItem);
	treeController->updateEntries();
}


MainWindowController_without_tabs::~MainWindowController_without_tabs()
{
	
}


void MainWindowController_without_tabs::switchTab(int new_tab)
{
	
}


QTreeWidget* MainWindowController_without_tabs::currentFolderTree(void)const
{
	return folderTree;
}


QListWidget* MainWindowController_without_tabs::currentFileList(void)const
{
	return fileList;
}


#if 0
void MainWindowController_without_tabs::setup()
{
	Ui::MainWindow_without_tabs ui;
	ui.setupUi(dynamic_cast<QMainWindow*>(parent()));
	
	//QFileSystemModel* const fsmodel=new QFileSystemModel(this);
	FileListModel* const fsmodel=new FileListModel(this);
	//QStandardItemModel* fsmodel=new FolderModel(this);
	//fsmodel->setOptions(QFileSystemModel::DontWatchForChanges);
	ui.fileList->setModel(fsmodel);
	currentFileList=ui.fileList;
	
	//connect(ui.fileList, &QListWidget::itemDoubleClicked, this, &MainWindowController_without_tabs::openItem);
	
	FolderModel* const dmodel=new FolderModel(this);
	/*
	dmodel->setRootPath(":");
	dmodel->setFilter(QDir::AllDirs|QDir::NoDotAndDotDot|QDir::Dirs|QDir::Drives|QDir::CaseSensitive);
	dmodel->setOptions(QFileSystemModel::DontWatchForChanges);
	dmodel->sort(0);
	*/
	
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
	
	/*
	Folders in "This PC" sections are bellow:
	コンピューター\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer
	
	コンピューター\HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders
	*/
	
	//dmodel->appendExistingChildren(dmodel->invisibleRootItem(), 2);
	
	ui.folderTree->setModel(dmodel);
//	ui.folderTree->hideColumn(1);
//	ui.folderTree->hideColumn(2);
//	ui.folderTree->hideColumn(3);
	ui.folderTree->setHeaderHidden(true);
	currentFolderTree=ui.folderTree;
	
	connect(ui.folderTree, &QTreeView::clicked, this, &MainWindowController_without_tabs::selectFolder);
	connect(ui.folderTree, &QTreeView::expanded, this, &MainWindowController_without_tabs::expandFolder);
	//connect(dmodel, &QStandardItemModel::itemChanged, );
	//connect(dmodel, &FolderModel::itemUpdated, ui.folderTree, QOverload<const QModelIndex&>::of(&QAbstractItemView::update));
}
#endif