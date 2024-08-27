#include <qapplication.h>
#include <qstring.h>
#include "mainwindow.hpp"

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QString imagePath;
	if (argc > 1) {
		imagePath = argv[1];
	}

	MainWindow mainWindow;
	mainWindow.show();

	if (!imagePath.isEmpty()) {
		mainWindow.displayImage(imagePath);
		mainWindow.adjustSize();
	}

	return application.exec();
}
