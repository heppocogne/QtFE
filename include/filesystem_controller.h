#ifndef FILESYSTEM_CONTROLLER_H
#define FILESYSTEM_CONTROLLER_H

	namespace QtFE
	{
		class FileSystemController: public QObject
		{
			Q_OBJECT
		public:
			FileSystemController(QObject* parent=nullptr);
			~FileSystemController();
			
		public slots:
			bool rename(const QString& old_name, const QString& new_name);
			bool remove(const QString& target);
			bool createFile(const QString& name);
			bool createFolder(const QString& name);
			bool createSymLink(const QString& name, const QString& linkTarget);
		};
	};

#endif