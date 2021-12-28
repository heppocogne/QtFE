#ifndef ABSTRACT_MAINWINDOW_CONTROLLER_H
	#define ABSTRACT_MAINWINDOW_CONTROLLER_H

	#include <QObject>
	#include <QListView>
	#include <QTreeView>
	#include <QFileSystemModel>
	#include <QMainWindow>
	#include <QMenu>
	#include <QString>
	
	#include "foldermodel.h"

	namespace QtFE
	{
		class AbstractMainWindowController: public QObject
		{
			Q_OBJECT
		protected:
			QMenu* const folderMenu;
			
		protected slots:
			void selectFolder(const QModelIndex& index);
			void expandFolder(const QModelIndex& index);
			
		public:
			AbstractMainWindowController(QObject* parent);
			virtual ~AbstractMainWindowController();
			virtual void setup()=0;
			virtual QTreeView* currentTreeView(void)const=0;
			virtual QListView* currentListView(void)const=0;
			FolderModel* currentFolderModel(void)const;
			QFileSystemModel* currentFileSystemModel(void)const;
		};
	};

#endif