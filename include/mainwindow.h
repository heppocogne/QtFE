#ifndef MAINWINDOW_H
	#define MAINWINDOW_H
	
	#include <QMainWindow>
	//#include <QWidget>
	class QWidget;
	
	#include "abstract_mainwindow_controller.h"
	
	namespace QtFE
	{
		class MainWindow: public QMainWindow
		{
			Q_OBJECT
			
		public:
			enum class ViewLayout
			{
				DEFAULT,
				WITHOUT_TABS,
				SHARED_TREE,
				TREE_FOREACH_LIST,
			};
			
			MainWindow(QWidget *parent=nullptr, ViewLayout _viewLayout=ViewLayout::DEFAULT);
			virtual ~MainWindow();
			
			void setup(ViewLayout newViewLayout);
		protected:
			ViewLayout viewLayout;
			AbstractMainWindowController* controller;
			
			
		};
	};
	
#endif