#include <qapplication.h>
#include <qstring.h>
#include <qwindowdefs.h>
#include "nomaren.hpp"

int main(int argc, char* argv[]) {
	QApplication application(argc, argv);

	QString mediaFilePath;
	if (argc > 1) {
		mediaFilePath = argv[1];
	}

	Nomaren nomaren;
	nomaren.show();

	if (!mediaFilePath.isEmpty()) {
		nomaren.ProcessFileFromCommandLine(mediaFilePath);
	}

	return application.exec();
}
