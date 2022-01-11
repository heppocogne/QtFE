#ifndef FOLDERTREE_CONTROLLER_H
#define FOLDERTREE_CONTROLLER_H

	#include <QObject>
	#include <QString>
	
	class QWidget;
	class QTreeWidgetItem;
	class QFileIconProvider;
	class QIcon;
	class QTreeWidget;
	
	namespace QtFE
	{
		class AbstractFolderTreeItem;
		
		class FolderTreeController: public QObject
		{
			Q_OBJECT
			QTreeWidget* const tree;
			
			static AbstractFolderTreeItem* _cast(QTreeWidgetItem* const _item);
			
		public:
			FolderTreeController(QTreeWidget* parent=nullptr);
			~FolderTreeController();
			
			void updateEntries(void);	//update all toplevel items
			
		public slots:
			void updateEntry(QTreeWidgetItem* const item);
			void onSelectItem(QTreeWidgetItem* const item);
			void onExpandItem(QTreeWidgetItem* const item);
		};
	};
	
#endif