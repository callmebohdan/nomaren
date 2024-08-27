#include <qimage.h>
#include <qlabel.h>
#include <qmainwindow.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qstring.h>
#include <qwidget.h>
#include "mainwindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, imageLabel(new QLabel(this))
{
	ui->setupUi(this);
	imageLabel->setAlignment(Qt::AlignCenter);
	setCentralWidget(imageLabel);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::displayImage(const QString& filePath) {
	QImage image(filePath);

	if (image.isNull()) {
		QMessageBox::critical(this, "Error", "Failed to load image: " + filePath);
		return;
	}

	imageLabel->setPixmap(QPixmap::fromImage(image));

	imageLabel->adjustSize();
}
