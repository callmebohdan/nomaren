#include <qapplication.h>
#include <qmessagebox.h>
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
		QMessageBox::warning(nullptr, "No File Provided", "Please provide a valid media file as a command-line argument.");
	}
	else {
		mainWindow.ProcessFile(mediaFilePath);
	}

	return application.exec();
}
