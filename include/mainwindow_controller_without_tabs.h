#ifndef MAINWINDOW_CONTROLLER_WITHOUT_TABS_H
	#define MAINWINDOW_CONTROLLER_WITHOUT_TABS_H
	
	#include "abstract_mainwindow_controller.h"
	
	class QTreeWidget;
	class QListWidget;
	
	namespace QtFE
	{
		class FolderTreeController;
		
		class MainWindowController_without_tabs: public  AbstractMainWindowController
		{
			Q_OBJECT
			
			QTreeWidget* folderTree;
			FolderTreeController* treeController;
			QListWidget* fileList;
		public:
			MainWindowController_without_tabs(QWidget* parent=nullptr);
			virtual ~MainWindowController_without_tabs();
			void switchTab(int new_tab);
			//virtual void setup();
			QTreeWidget* currentFolderTree(void)const;
			QListWidget* currentFileList(void)const;
		};
	};
	
#endif