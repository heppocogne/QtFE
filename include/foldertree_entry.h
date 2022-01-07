#ifndef FOLDERTREE_ENTRY_H
	#define FOLDERTREE_ENTRY_H
	
	#include "abstract_foldertree_item.h"
	
	class QString;
	class QTreeWidget;
	class QTreeWidgetItem;
	
	namespace QtFE
	{
		class FolderTreeEntry: public AbstractFolderTreeItem
		{
			Q_OBJECT
			
		public:
			FolderTreeEntry(QTreeWidget* parent);
			FolderTreeEntry(QTreeWidget* parent, const QString& text);
			FolderTreeEntry(QTreeWidget* parent, const QString& text, const QIcon& icon);
			//~FolderTreeEntry();
		
		public slots:
			void refreshChildren(void);
		};
	};
	
#endif