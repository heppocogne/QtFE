#ifndef ABSTRACT_FOLDERTREE_ITEM_H
#define ABSTRACT_FOLDERTREE_ITEM_H

	#include <QTreeWidgetItem> 
	#include <QString>
	#include <QObject>
	
	class QTreeWidget;
	class QFileIconProvider;
	class QIcon;
	
	namespace QtFE
	{
		class AbstractFolderTreeItem: public QObject, public QTreeWidgetItem
		{
			Q_OBJECT
			
		public:
			enum FolderTreeItemType
			{
				Entry,
				//EntryFolder,
				Folder
			};
			const FolderTreeItemType itemType;
			static QFileIconProvider* const iconProvider;
			
			AbstractFolderTreeItem(FolderTreeItemType _itemType, QTreeWidget *parent);
			AbstractFolderTreeItem(FolderTreeItemType _itemType, QTreeWidgetItem* parent);
			
			//AbstractFolderTreeItem(AbstractFolderTreeItem* parent, const QString& path ,const QString& text, const QIcon& icon);
			virtual ~AbstractFolderTreeItem();
			
			//virtual const AbstractFolderTreeItemTypes itemType(void)const=0;
			void setText(const QString& _text);
			QString getText(void)const;
			void setPath(const QString& _path);
			QString getPath(void)const;
			void setIcon(const QIcon& icon);
			
			AbstractFolderTreeItem* addFolder(const QString& path, const QString& text="");
			//AbstractFolderTreeItem* addFolderItem(AbstractFolderTreeItem* const item);
			//QIcon getIcon(void)const;
			
			//virtual void releadChildren(void);
		public slots:
			virtual void refreshChildren(void)=0;
			void refreshGrandChildren(void);
		};
	};
	
#endif