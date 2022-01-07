#ifndef FILELIST_CONTROLLER_H
	#define FILELIST_CONTROLLER_H
	
	#include <QObject>
	
	class QListWidgetItem;
	class QString;
	
	namespace QtFE
	{
		class FileListController: public QObject
		{
			Q_OBJECT
			
		public:
			FileListController(QObject* parent=nullptr);
			~FileListController();
			
		public slots:
			void selectItem(QListWidgetItem* const item);
			void openItem(QListWidgetItem* const item);
		};
	};
	
#endif