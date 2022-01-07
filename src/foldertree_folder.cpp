#include "foldertree_folder.h"

#include <QDir>
#include <QFileIconProvider>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QString>


using namespace QtFE;

FolderTreeFolder::FolderTreeFolder(QTreeWidgetItem* parent)
	:AbstractFolderTreeItem(Folder, parent)
{
	
}


FolderTreeFolder::FolderTreeFolder(QTreeWidget* parent)
	:AbstractFolderTreeItem(Folder, parent)
{
	
}


FolderTreeFolder::FolderTreeFolder(QTreeWidget* parent,  const QString& path, const QString& text)
	:FolderTreeFolder(parent)
{
	setPath(path);
	setText(text==""?QFileInfo(path).fileName():text);
	setIcon(iconProvider->icon(path));
}


FolderTreeFolder::FolderTreeFolder(QTreeWidgetItem* parent, const QString& path, const QString& text)
	:FolderTreeFolder(parent)
{
	setPath(path);
	setText(text==""?QFileInfo(path).fileName():text);
	setIcon(iconProvider->icon(path));
}


void FolderTreeFolder::refreshChildren(void)
{
	takeChildren();
	
	QDir this_dir(getPath());
	const auto childFolders=this_dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs|QDir::Drives, QDir::Name|QDir::IgnoreCase);
	for(const auto& folder: childFolders)
	{
		QtFE::AbstractFolderTreeItem* const item=new FolderTreeFolder(this, folder.absoluteFilePath());
		addChild(item);
	}
}