#if 0
#ifndef FILELISTMODEL_H
	#define FILELISTMODEL_H

	#include <QStandardItemModel>
	#include <QModelIndex>
	
	class QStandardItem;
	class QString;
	class QObject;
	class QFileIconProvider;

	namespace QtFE
	{
		class FileListModel: public QStandardItemModel
		{
			Q_OBJECT
			
			QFileIconProvider* const iconProvider;
		public:
			FileListModel(QObject* parent=nullptr);
			~FileListModel();
			
			QModelIndex setRootPath(const QString& path);
		};
	};

#endif
#endif