#include <qapplication.h>
#include <qfile.h>
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

	if (!mediaFilePath.isEmpty()) {
		if (QFile::exists(mediaFilePath)) {
			mainWindow.ProcessFile(mediaFilePath);
		}
		else {
			qWarning() << "Media file path does not exist:" << mediaFilePath;
		}
	}

	return application.exec();
}
