#ifndef FILELIST_CONTROLLER_H
	#define FILELIST_CONTROLLER_H
	
	#include <QObject>
	
	class QTableWidgetItem;
	class QTableWidget;
	class QTreeWidgetItem;
	class QString;
	class QFileIconProvider;
	
	namespace QtFE
	{
		class AbstractFolderTreeItem;
		
		class FileListController: public QObject
		{
			Q_OBJECT
			
			QTableWidget* const list;
			static QFileIconProvider* const iconProvider;
			
			QList<QTableWidgetItem*> addItem(const QString& path, const QString& text="");
			void setRootItem(AbstractFolderTreeItem* const item);
			
			int nameColumn;
			int lastModifiedColumn;
			int filetypeColumn;
			int sizeColumn;
		
		public:
			FileListController(QTableWidget* parent=nullptr);
			~FileListController();
			
		public slots:
			void setRootPath(const QString& path);
			void setRootTreeItem(QTreeWidgetItem* const item, int dummy=0);
			void setRootListItem(QTableWidgetItem* const item);
			void selectItem(QTableWidgetItem* const item);
			void openItem(QTableWidgetItem* const item);
		};
	};
	
#endif