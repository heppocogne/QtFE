#ifndef ABSTRACT_MAINWINDOW_CONTROLLER_H
	#define ABSTRACT_MAINWINDOW_CONTROLLER_H

	#include <QObject>
	
	class QListView;
	class QMenu;
	class QTreeView;
	class QFileSystemModel;
	class QModelIndex;

	namespace QtFE
	{
		class FolderModel;
		class FileListModel;
		class FileSystemController;
		
		class AbstractMainWindowController: public QObject
		{
			Q_OBJECT
		protected:
			QMenu* const folderMenu;
			FileSystemController* const fileController;
			
		protected slots:
			void selectFolder(const QModelIndex& index);
			void expandFolder(const QModelIndex& index);
			void openItem(const QModelIndex& index);
			
		public:
			AbstractMainWindowController(QObject* parent=nullptr);
			virtual ~AbstractMainWindowController();
			virtual void setup()=0;
			virtual QTreeView* currentTreeView(void)const=0;
			virtual QListView* currentListView(void)const=0;
			FolderModel* currentFolderModel(void)const;
			//QFileSystemModel* currentFileSystemModel(void)const;
			FileListModel* currentFileSystemModel(void)const;
		};
	};

#endif