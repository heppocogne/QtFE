#ifndef ABSTRACT_MAINWINDOW_CONTROLLER_H
	#define ABSTRACT_MAINWINDOW_CONTROLLER_H

	#include <QObject>
	
	class QWidget;
	class QListWidget;
	//class QMenu;
	class QTreeWidget;
	//class QFileSystemModel;
	//class QModelIndex;

	namespace QtFE
	{
		/*
		class FolderModel;
		class FileListModel;
		class FileSystemController;
		*/
		
		class AbstractMainWindowController: public QObject
		{
			Q_OBJECT
			
		protected:
			
		protected slots:
			
		public:
			AbstractMainWindowController(QWidget* parent=nullptr);
			virtual ~AbstractMainWindowController();
			
			virtual QTreeWidget* currentFolderTree(void)const=0;
			virtual QListWidget* currentFileList(void)const=0;
		
		public slots:
			virtual void switchTab(int new_tab)=0;
		};
	};

#endif