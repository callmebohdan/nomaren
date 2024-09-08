#include <qapplication.h>
#include <qstring.h>
#include "mainwindow.hpp"

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QString mediaFilePath;
	if (argc > 1) {
		mediaFilePath = argv[1];
	}

	MainWindow mainWindow;
	mainWindow.show();
	//mainWindow.DisplayImage(mediaFilePath);
	//mainWindow.DisplayMusic(mediaFilePath);
	//mainWindow.DisplayText(mediaFilePath);
	//mainWindow.DisplayVideo(mediaFilePath);
	//mainWindow.ProcessFile(mediaFilePath);
	return application.exec();
}
