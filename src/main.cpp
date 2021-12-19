#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QString>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	QCommandLineParser parser;
	parser.setApplicationDescription("description");
	parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
	
	//QCommandLineOption aaaa=	{"aaaa",	"description"};
	//if(parser.isSet(aaaa))) {}

    QPushButton quit("Quit");

    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    quit.show();

    return app.exec();
}
