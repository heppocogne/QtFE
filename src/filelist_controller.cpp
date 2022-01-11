#include "filelist_controller.h"

#include <QFileInfo>
#include <QDir>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>

#include "abstract_foldertree_item.h"
	
using namespace QtFE;

FileListController::FileListController(QListWidget* parent)
	:QObject(parent),
	list(dynamic_cast<QListWidget*>(parent))
	{
		
	}


FileListController::~FileListController()
{
	
}


QListWidgetItem* FileListController::addItem(const QString& path, const QString& text="")
{
	
}


void FileListController::setRootPath(const QString& path)
{
	QDir::Filters filters=QDir::AllEntries|QDir::NoDotAndDotDot|QDir::CaseSensitive;
	QDir::SortFlags sort=QDir::Name;
	
	const QFileInfoList fileInfos=QDir(path).entryInfoList(filters, sort);
	for(const auto& fileInfo: fileInfos)
	{
		//rootPathItem->appendRow(new QStandardItem(iconProvider->icon(fileInfo.absoluteFilePath()), fileInfo.fileName()));
	}
}


void FileListController::setRootItem(AbstractFolderTreeItem* const item)
{
	
}


void FileListController::setRootItem(QListWidgetItem* const item)
{
	
}


void FileListController::selectItem(QListWidgetItem* const item)
{
	
}


void FileListController::openItem(QListWidgetItem* const item)
{
	
}
