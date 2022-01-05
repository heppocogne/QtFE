#include "filesystem_controller.h"

#include <QProcess>
#include <QFile>


using namespace QtFE;

FileSystemController::FileSystemController(QObject* parent)
	:QObject(parent)
{
	
}


FileSystemController::~FileSystemController()
{
	
}


bool FileSystemController::rename(QFile& target, const QString& new_name)
{
	return target.rename(new_name);
}


bool FileSystemController::remove(QFile& target)
{
	/*
	QFile file(target);
	return file.remove(target);
	*/
	return target.remove();
}


bool FileSystemController::createTextFile(const QString& name)
{
	//const QString base_name=tr("新しいテキスト ドキュメント.txt");
	return true;
}


bool FileSystemController::createFolder(const QString& name)
{
	return true;
}


bool FileSystemController::createSymLink(const QString& name, const QFile& linkTarget)
{
	return true;
}


bool FileSystemController::openFile(const QString& path)
{
	QProcess process(this);
	process.setProgram(path);
	return process.startDetached();
}
