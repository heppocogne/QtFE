#include "foldertree_controller.h"

#include <Qwidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QFileIconProvider>

#include "abstract_foldertree_item.h"

using namespace QtFE;

#include <QMessageBox>



FolderTreeController::FolderTreeController(QTreeWidget* parent)
	:QObject(parent),
	tree(parent)
	{
		
	}


FolderTreeController::~FolderTreeController()
{
	
}


AbstractFolderTreeItem* FolderTreeController::_cast(QTreeWidgetItem* const _item)
{
	return dynamic_cast<AbstractFolderTreeItem*>(_item);
}


void FolderTreeController::updateEntries(void)
{
	QString msg=QString("topLevelItemCount=")+QString::number(tree->topLevelItemCount())+QString("\n");
	
	for(int i=0; i<tree->topLevelItemCount(); i++)
	{
		_cast(tree->topLevelItem(i))->refreshChildren();
		msg+=_cast(tree->topLevelItem(i))->getText()+QString("\n");
	}
	
	QMessageBox::information(nullptr, "debug", msg);
}


void FolderTreeController::updateEntry(QTreeWidgetItem* const _item)
{
	auto* const item=_cast(_item);
	item->refreshChildren();
}


void FolderTreeController::onSelectItem(QTreeWidgetItem* const _item)
{
	auto* const item=_cast(_item);
}


void FolderTreeController::onExpandItem(QTreeWidgetItem* const _item)
{
	auto* const item=_cast(_item);
	item->refreshGrandChildren();
}


#if 0
void FolderTreeController::selectItem(QTreeWidgetItem* const item)
{
	emit currentDirectoryChanged();
}


QTreeWidgetItem* FolderTreeController::addEntryGroup(const QString& text)
{
	return addEntryGroup(text, iconProvider->icon(QFileIconProvider::Folder));
}


QTreeWidgetItem* FolderTreeController::addEntryGroup(const QString& text, const QIcon& icon)
{
	auto* item const=new QTreeWidgetItem(tree);
	item->setText(0, text);
	item->setIcon(0, icon);
	item->setText(1, "EntryGroup");
	tree->addTopLevelItem(item);
	
	return item;
}


QTreeWidgetItem* FolderTreeController::addEntryFolder(const QString& path, QTreeWidgetItem* const group, const QString& text)
{
	QTreeWidgetItem* item;
	if(group)
		item=new QTreeWidgetItem(group);
	else
		item=new QTreeWidgetItem(tree);
	//EntryFolder
	//icon+folder name(text), type(=EntryFolder), path
	item->setText(0, text);
	item->setIcon(0, iconProvider->icon(path));
	item->setText(1, "EntryFolder");
	item->setText(2, path);
	
	//Folder
	//icon+folder name(text), type(=Folder), path
	
	//tree->setColumnHidden(1);
	//tree->setColumnHidden(2);
	
	return item;
}


void FolderTreeController::reloadChildren(QTreeWidgetItem* const item)
{
	
}


QTreeWidgetItem* FolderTreeController::addFolderItem(QTreeWidgetItem* const parentItem, const QString& path)
{
	QTreeWidgetItem* const item=new QTreeWidgetItem(parentItem);
	
}


QString FolderTreeController::getFolderPath(QTreeWidgetItem* const item)const
{
	return item->text(2);
}
#endif