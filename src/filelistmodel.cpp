#if 0
#include "filelistmodel.h"

#include <QStandardItem>
#include <QString>
#include <QDir>
#include <QFileIconProvider>

using namespace QtFE;


FileListModel::FileListModel(QObject* parent)
	:QStandardItemModel(parent),
	iconProvider(new QFileIconProvider())
	{
		
	}


FileListModel::~FileListModel()
{
	delete iconProvider;
}


QModelIndex FileListModel::setRootPath(const QString& path)
{
	appendRow(new QStandardItem(path));
	QStandardItem* const rootPathItem=item(rowCount()-1);
	
	QDir::Filters filters=QDir::AllEntries|QDir::NoDotAndDotDot|QDir::CaseSensitive;
	QDir::SortFlags sort=QDir::Name;
	
	const QFileInfoList fileInfos=QDir(path).entryInfoList(filters, sort);
	for(const auto& fileInfo: fileInfos)
	{
		rootPathItem->appendRow(new QStandardItem(iconProvider->icon(fileInfo.absoluteFilePath()), fileInfo.fileName()));
	}
	return rootPathItem->index();
}
#endif