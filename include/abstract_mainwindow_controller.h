#ifndef ABSTRACT_MAINWINDOW_CONTROLLER_H
	#define ABSTRACT_MAINWINDOW_CONTROLLER_H

	#include <QObject>
	
	class QWidget;
	class QTableWidget;
	//class QMenu;
	class QTreeWidget;
	

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
			virtual QTableWidget* currentFileList(void)const=0;
		
		public slots:
			virtual void switchTab(int new_tab)=0;
		};
	};

#endif