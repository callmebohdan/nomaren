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

	if (mediaFilePath.isEmpty()) {
		mainWindow.ProcessFileFromUserPrompt(mediaFilePath);
	}
	else {
		mainWindow.ProcessFileFromCommandLine(mediaFilePath);
	}

	return application.exec();
}
