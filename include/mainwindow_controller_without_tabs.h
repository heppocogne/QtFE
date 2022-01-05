#ifndef MAINWINDOW_CONTROLLER_WITHOUT_TABS_H
	#define MAINWINDOW_CONTROLLER_WITHOUT_TABS_H
	
	#include "abstract_mainwindow_controller.h"
	
	namespace QtFE
	{
		class MainWindowController_without_tabs: public  AbstractMainWindowController
		{
			Q_OBJECT
			
			QTreeView* currentFolderTree;
			QListView* currentFileList;
			
		public:
			MainWindowController_without_tabs(QObject* parent=nullptr);
			virtual ~MainWindowController_without_tabs();
			 
			virtual void setup();
			virtual QTreeView* currentTreeView(void)const;
			virtual QListView* currentListView(void)const;
		};
	};
	
#endif