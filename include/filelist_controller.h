#ifndef FILELIST_CONTROLLER_H
	#define FILELIST_CONTROLLER_H
	
	#include <QObject>
	
	class QListWidgetItem;
	class QListWidget;
	class QString;
	
	namespace QtFE
	{
		class AbstractFolderTreeItem;
		
		class FileListController: public QObject
		{
			Q_OBJECT
			
			QListWidget* const list;
			
			QListWidgetItem* addItem(const QString& path, const QString& text="");
			
		public:
			FileListController(QListWidget* parent=nullptr);
			~FileListController();
			
		public slots:
			void setRootPath(const QString& path);
			void setRootItem(AbstractFolderTreeItem* const item);
			void setRootItem(QListWidgetItem* const item);
			void selectItem(QListWidgetItem* const item);
			void openItem(QListWidgetItem* const item);
		};
	};
	
#endif