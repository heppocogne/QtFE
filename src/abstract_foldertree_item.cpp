#include "abstract_foldertree_item.h"

#include <QFileInfo>
#include <QFileIconProvider>
#include <QTreeWidget>
#include <QIcon>


#include "foldertree_folder.h"

using namespace QtFE;

QFileIconProvider* const AbstractFolderTreeItem::iconProvider=new QFileIconProvider();


AbstractFolderTreeItem::AbstractFolderTreeItem(FolderTreeItemType _itemType, QTreeWidgetItem* parent)
	:QTreeWidgetItem(parent),
	itemType(_itemType)
{
	
}


AbstractFolderTreeItem::AbstractFolderTreeItem(FolderTreeItemType _itemType, QTreeWidget* parent)
	:QTreeWidgetItem(parent),
	itemType(_itemType)
{
	
}


AbstractFolderTreeItem::~AbstractFolderTreeItem()
{
	
}


void AbstractFolderTreeItem::setText(const QString& _text)
{
	QTreeWidgetItem::setText(0, _text);
}


QString AbstractFolderTreeItem::getText(void)const
{
	return QTreeWidgetItem::text(0);
}


void AbstractFolderTreeItem::setPath(const QString& _path)
{
	QTreeWidgetItem::setText(1, _path);
}


QString AbstractFolderTreeItem::getPath(void)const
{
	return QTreeWidgetItem::text(1);
}


void AbstractFolderTreeItem::setIcon(const QIcon& icon)
{
	QTreeWidgetItem::setIcon(0, icon);
}


AbstractFolderTreeItem* AbstractFolderTreeItem::addFolder(const QString& path, const QString& text)
{
	QFileInfo info(path);
	auto* const item=new FolderTreeFolder(this);
	item->setText(text==""?info.fileName():text);
	item->setPath(path);
	item->setIcon(iconProvider->icon(path));
	return item;
}


void AbstractFolderTreeItem::refreshGrandChildren(void)
{
	refreshChildren();
	for(int i=0; i<childCount(); i++)
	{
		auto* const item=dynamic_cast<AbstractFolderTreeItem*>(child(i));
		item->refreshChildren();
	}
}
