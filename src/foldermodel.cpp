#include "foldermodel.h"

using namespace QtFE;


FolderModel::FolderModel(QObject* parent)
	:QStandardItemModel(parent),
	logfile("C:/Users/usk10/git/QtWorkspace/QtFE/debug/QtFE.log"),
	rootItem(invisibleRootItem())
{
	
}


FolderModel::~FolderModel()
{
	
}


void FolderModel::appendExistingChildrenRecursive(QStandardItem* item, int  recurse, QDir::Filters filters, QDir::SortFlags sort)
{
	const QString description=item->accessibleDescription();

	const bool checked=childrenChecked.contains(description);
	if(!checked)
	{
		childrenChecked<<description;
	}
	
	const QFileInfoList subFolders=QDir(description).entryInfoList(filters, sort);
	for(int r=0; r< subFolders.size(); r++)
	{
		const auto& subFolder=subFolders[r];
		const auto& dir=subFolder.filePath();
		
		if(!checked)
		{
			QStandardItem* const child=new QStandardItem(iconProvider.icon(dir), subFolder.fileName());
			child->setAccessibleDescription(dir);
			item->appendRow(child);
		}
		if(0<recurse)
		{
			QStandardItem* const child=item->child(r);
			appendExistingChildrenRecursive(child, recurse-1);
		}
	}
}
#if 0
#include <QJsonArray>
#include <QJsonValue>
QJsonObject serializeItem(const QStandardItem* item)
{
	QJsonObject obj;
	obj["parent"]=item->parent()?item->parent()->accessibleDescription():nullptr;
	obj["text"]=item->text();
	obj["description"]=item->accessibleDescription();
	if(item->hasChildren())
	{
		QJsonArray children;
		for(int i=0; i<item->rowCount(); i++)
		{
			children.push_back(serializeItem(item->child(i)));
		}
		obj["children"]=children;
	}
	return obj;
}


#include <string>
#endif
void FolderModel::appendExistingChildren(QStandardItem* item, int  recurse, QDir::Filters filters, QDir::SortFlags sort)
{
	appendExistingChildrenRecursive(item, recurse, filters, sort);
	emit itemUpdated(item->index());
}


QStandardItem* FolderModel::appendFolderItem(QStandardItem* parentItem, const QDir& folderPath, const QString& text)
{
	return appendFolderItem(parentItem, folderPath, iconProvider.icon(folderPath.absolutePath()), text);
}

QStandardItem* FolderModel::appendFolderItem(QStandardItem* parentItem, const QDir& folderPath, const QIcon& icon, const QString& text)
{
	QFileInfo fileinfo(folderPath.absolutePath());
	QStandardItem* const item=new QStandardItem(icon, text==""?fileinfo.fileName():text);
	item->setAccessibleDescription(folderPath.absolutePath());
	parentItem->appendRow(item);

	return item;
}


void FolderModel::appendFolderEntry(const QDir& folderPath, const QString& text)
{
	appendFolderEntry(folderPath, iconProvider.icon(folderPath.absolutePath()), text);
}

void FolderModel::appendFolderEntry(const QDir& folderPath, const QIcon& icon, const QString& text)
{
	QStandardItem* const item=appendFolderItem(rootItem, folderPath, icon, text);
	appendExistingChildren(item, 1);
}

