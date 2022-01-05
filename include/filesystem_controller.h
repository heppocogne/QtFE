#ifndef FILESYSTEM_CONTROLLER_H
#define FILESYSTEM_CONTROLLER_H

	#include <QObject>

	class QString;
	class QFile;

	namespace QtFE
	{
		class FileSystemController: public QObject
		{
			Q_OBJECT
		public:
			FileSystemController(QObject* parent=nullptr);
			~FileSystemController();
			
			bool rename(QFile& target, const QString& new_name);
			bool createSymLink(const QString& name, const QFile& linkTarget);
			bool remove(QFile& target);
			bool createTextFile(const QString& name);
			bool createFolder(const QString& name);
			
		public slots:
			bool openFile(const QString& path);
		};
	};

#endif