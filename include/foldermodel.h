#ifndef FOLDERMODEL_H
	#define FOLDERMODEL_H
	
	#include <Qt>
	//#include <QAbstractItemModel>
	#include <QModelIndex>
	#include <QVariant>
	#include <QStorageInfo>
	#include <QFileInfo>
	#include <QDir>
	#include <QIcon>
	#include <QFileIconProvider>
	#include <QString>
	#include <QStandardItemModel>
	#include <QStandardItem>
	//#include <vector>
	#include <fstream>
	//#include <QJsonObject>
	//#include <QJsonDocument>
	
	namespace QtFE
	{
		class FolderModel: public QStandardItemModel
		{
			Q_OBJECT
			QFileIconProvider iconProvider;
			QStringList childrenChecked;
			//std::vector<QString> childrenChecked;
			void appendExistingChildrenRecursive(QStandardItem* item, int  recurse,
															QDir::Filters filters=QDir::AllDirs|QDir::NoDotAndDotDot|QDir::Dirs|QDir::Drives|QDir::CaseSensitive, 
															QDir::SortFlags sort=QDir::Name);
		public:
			FolderModel(QObject* parent=nullptr);
			~FolderModel();
			
			std::ofstream logfile;
			
			QStandardItem* const rootItem;
			
			void appendFolderEntry(const QDir& folderPath, const QString& text="");
			void appendFolderEntry(const QDir& folderPath, const QIcon& icon, const QString& text="");
			QStandardItem* appendFolderItem(QStandardItem* parentItem, const QDir& folderPath, const QString& text="");
			QStandardItem* appendFolderItem(QStandardItem* parentItem, const QDir& folderPath, const QIcon& icon, const QString& text="");
			void appendExistingChildren(QStandardItem* item, int  recurse,
															QDir::Filters filters=QDir::AllDirs|QDir::NoDotAndDotDot|QDir::Dirs|QDir::Drives|QDir::CaseSensitive, 
															QDir::SortFlags sort=QDir::Name);
		
			//QJsonObject serialize(void);
		
		signals:
			void itemUpdated(const QModelIndex &index)const;
		};
	};
	
	QJsonObject serializeItem(const QStandardItem* item);
	
#endif