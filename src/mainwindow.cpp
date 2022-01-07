#include "mainwindow.h"
#include "mainwindow_controller_without_tabs.h"

#include <QWidget>

using namespace QtFE;

MainWindow::MainWindow(QWidget *parent, ViewLayout _viewLayout)
	:QMainWindow(parent),
	viewLayout(_viewLayout),
	controller(nullptr)
{
	
}


MainWindow::~MainWindow()
{
	
}


void MainWindow::setup(ViewLayout newViewLayout)
{
	viewLayout=newViewLayout;
	switch(viewLayout)
	{
		case ViewLayout::WITHOUT_TABS:
			controller=new MainWindowController_without_tabs(this);
			//controller->setup();
			break;
		case ViewLayout::SHARED_TREE:
			break;
		case ViewLayout::TREE_FOREACH_LIST:
			break;
		case ViewLayout::DEFAULT:
		default:
			break;
	}
}
