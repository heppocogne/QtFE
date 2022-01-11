#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QString>

#include "mainwindow.h"
//#include <QStorageInfo>
//#include <fstream>

#include <Shldisp.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	QCommandLineParser parser;
	parser.setApplicationDescription("description");
	parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
	
	//QCommandLineOption aaaa=	{"aaaa",	"description"};
	//if(parser.isSet(aaaa))) {}

//    QPushButton quit("Quit");
//
//    quit.resize(75, 30);
//    quit.setFont(QFont("Times", 18, QFont::Bold));
//
//    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
//
//    quit.show();

//	std::ofstream ofs("storages.txt");
//	for(const auto& info: QStorageInfo::mountedVolumes())
//	{
//		ofs<<info.displayName().toStdString()<<std::endl;
//	}

	QtFE::MainWindow* const window=new QtFE::MainWindow(nullptr);
	window->setup(QtFE::MainWindow::ViewLayout::WITHOUT_TABS);
	/*
	SHELLEXECUTEINFO seinfo = {0};
	seinfo.cbSize = sizeof(seinfo);
	seinfo.lpFile = L"C:\\Users\\usk10\\git\\QtWorkspace\\QtFE\\src\\test\\test.cpp";
	seinfo.nShow = SW_SHOW;
	seinfo.fMask = SEE_MASK_INVOKEIDLIST|SEE_MASK_NOCLOSEPROCESS;
	seinfo.lpVerb = L"properties";
	seinfo.hwnd=reinterpret_cast<HWND>(window->winId());
	ShellExecuteEx(&seinfo);
	*/
	window->show();

    return app.exec();
}
