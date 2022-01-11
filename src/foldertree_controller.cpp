#include "foldertree_controller.h"

#include <Qwidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QFileIconProvider>

#include "abstract_foldertree_item.h"

using namespace QtFE;


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
	for(int i=0; i<tree->topLevelItemCount(); i++)
	{
		_cast(tree->topLevelItem(i))->refreshChildren();
	}
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
