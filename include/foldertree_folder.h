#ifndef FOLDERTREE_FOLDER_H
	#define FOLDERTREE_FOLDER_H
	
	#include "abstract_foldertree_item.h"
	
	class QTreeWidget;
	class QTreeWidgetItem;
	class QString;
	
	namespace QtFE
	{
		class FolderTreeFolder: public AbstractFolderTreeItem
		{
			Q_OBJECT
			
			
		public:
			FolderTreeFolder(QTreeWidget* parent);
			FolderTreeFolder(QTreeWidget* parent,  const QString& path, const QString& text="");
			FolderTreeFolder(QTreeWidgetItem* parent);
			FolderTreeFolder(QTreeWidgetItem* parent, const QString& path, const QString& text="");
			//~FolderTreeFolder();
		
		public slots:
			void refreshChildren(void);
		};
	};
	
#endif