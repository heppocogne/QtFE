#include "filelist_controller.h"

#include <QFileInfo>
#include <QDir>
#include <QTableWidget>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>
#include <QString>
#include <QFileIconProvider>
#include <QDateTime>
#include <QHeaderView>

#include <fileapi.h>

#include "abstract_foldertree_item.h"
	
using namespace QtFE;

QFileIconProvider* const FileListController::iconProvider=new QFileIconProvider();


FileListController::FileListController(QTableWidget* parent)
	:QObject(parent),
	list(dynamic_cast<QTableWidget*>(parent)),
	nameColumn(0),
	lastModifiedColumn(1),
	filetypeColumn(2),
	sizeColumn(3)
	{
		list->insertColumn(0);
		list->verticalHeader()->setVisible(false);
		list->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("File Name")));
	}


FileListController::~FileListController()
{
	
}


QList<QTableWidgetItem*> FileListController::addItem(const QString& path, const QString& text)
{
	const auto fileinfo=QFileInfo(path);
	auto* const mainitem=new QTableWidgetItem(iconProvider->icon(path), text==""?fileinfo.fileName():text);
	mainitem->setFlags(Qt::ItemIsSelectable|
									Qt::ItemIsEditable|
									Qt::ItemIsDragEnabled|
									Qt::ItemIsDropEnabled|
									Qt::ItemIsUserCheckable|
									Qt::ItemIsEnabled);
	//auto* const lastModifiedTimestamp=new QTableWidgetItem(fileinfo.lastModified().toString("yyyy/MM/dd HH:mm:ss"));
	
	QList<QTableWidgetItem*> result;
	result.append(mainitem);
	const int row=list->rowCount();
	list->insertRow(row);
	list->setItem(row, 0, mainitem);
	return result;
}


void FileListController::setRootPath(const QString& path)
{
	list->clearContents();
	list->setRowCount(0);
	
	QDir::Filters filters=QDir::AllEntries|QDir::NoDotAndDotDot|QDir::CaseSensitive;
	QDir::SortFlags sort=QDir::Name|QDir::IgnoreCase;
	
	const QFileInfoList fileinfos=QDir(path).entryInfoList(filters, sort);
	for(const auto& fileinfo: fileinfos)
	{
		addItem(fileinfo.absoluteFilePath());
	}
}


void FileListController::setRootItem(AbstractFolderTreeItem* const item)
{
	if(item->itemType==AbstractFolderTreeItem::Entry)
	{
		list->clearContents();
		list->setRowCount(0);
		
		for(int i=0; i<item->childCount(); i++)
		{
			addItem(dynamic_cast<AbstractFolderTreeItem*>(item->child(i))->getPath());
		}
	}else
		setRootPath(item->getPath());
}


void FileListController::setRootTreeItem(QTreeWidgetItem* const item, int dummy)
{
	return setRootItem(dynamic_cast<AbstractFolderTreeItem*>(item));
}


void FileListController::setRootListItem(QTableWidgetItem* const item)
{
	//return setRootItem(dynamic_cast<>);
}


void FileListController::selectItem(QTableWidgetItem* const item)
{
	
}


void FileListController::openItem(QTableWidgetItem* const item)
{
	
}
