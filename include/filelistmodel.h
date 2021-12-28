#ifndef FILELISTMODEL_H
#define FILELISTMODEL_H

	#include <QStandardItemModel>

	namespace QtFE
	{
		class FileListModel: public QStandardItemModel
		{
			Q_OBJECT
		public:
			FileListModel(QObject* parent=nullptr);
			~FileListModel();
		};
	};

#endif