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
			
			
			#if 0
			QFileIconProvider* const iconProvider;
			QTreeWidget* const tree;
			static QTreeWidgetItem* addFolderItem(QTreeWidgetItem* const item, const QString& path);
			
		public:
			FolderTreeController(QWidget* parent=nullptr);
			~FolderTreeController();
			static QString getFolderPath(QTreeWidgetItem* const item)const;
			
		public slots:
			void selectItem(QTreeWidgetItem* const item);
			QTreeWidgetItem* addEntryGroup(const QString& text);
			QTreeWidgetItem* addEntryGroup(const QString& text, const QIcon& icon);
			QTreeWidgetItem* addEntryFolder(const QString& path, QTreeWidgetItem* const group=nullptr, const QString& text="");
			void reloadChildren(QTreeWidgetItem* const item);
		
		signals:
			void currentDirectoryChanged(const QString& path);
			#endif
		};
	};
	
#endif