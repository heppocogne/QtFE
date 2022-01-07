#include "foldertree_entry.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QString>

using namespace QtFE;


FolderTreeEntry::FolderTreeEntry(QTreeWidget* parent)
	:AbstractFolderTreeItem(Entry, parent)
	{
		
	}


FolderTreeEntry::FolderTreeEntry(QTreeWidget* parent, const QString& text)
	:FolderTreeEntry(parent)
	{
		setText(text);
	}


FolderTreeEntry::FolderTreeEntry(QTreeWidget* parent, const QString& text, const QIcon& icon)
	:FolderTreeEntry(parent)
	{
		setText(text);
		setIcon(icon);
	}


void FolderTreeEntry::refreshChildren(void)
{
	
}