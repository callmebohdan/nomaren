#include <qcontainerfwd.h>
#include <qfileinfo.h>
#include <qimage.h>
#include <qlabel.h>
#include <qlogging.h>
#include <qmainwindow.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qstring.h>
#include <qtypes.h>
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

bool MainWindow::isImageFile(const QString& filePath) {
	static const QStringList imageExtensions = {"bmp", "gif", "jpeg", "jpg", "png", "pbm", "pgm", "ppm", "tiff", "xbm", "xpm", "webp", "ico", "dds", "tga", "heif", "avif"};
	QFileInfo fileInfo(filePath);
	return imageExtensions.contains(fileInfo.suffix().toLower());
}

bool MainWindow::isMusicFile(const QString& filePath) {
	static const QStringList musicExtensions = {"mp3", "wav", "flac", "aac", "ogg", "wma", "m4a", "aiff"};
	QFileInfo fileInfo(filePath);
	return musicExtensions.contains(fileInfo.suffix().toLower());
}

bool MainWindow::isVideoFile(const QString& filePath) {
	static const QStringList videoExtensions = {"mp4", "avi", "mkv", "mov", "flv", "wmv", "webm", "mpg", "mpeg", "3gp"};
	QFileInfo fileInfo(filePath);
	return videoExtensions.contains(fileInfo.suffix().toLower());
}

void MainWindow::ProcessFile(const QString& filePath)
{
	bool isImage = isImageFile(filePath);
	bool isMusic = isMusicFile(filePath);
	bool isVideo = isVideoFile(filePath);

	if (isImage) {
		DisplayImage(filePath);
	}

	if (isMusic) {
		DisplayMusic(filePath);
	}

	if (isVideo) {
		DisplayVideo(filePath);
	}
}

void MainWindow::PositionChanged(qint64 position)
{
	qDebug() << "Current position: " << position;
}

void MainWindow::DisplayImage(const QString& filePath) {
	QImage image(filePath);

	if (image.isNull()) {
		QMessageBox::critical(this, "Error", "Failed to load image: " + filePath);
		return;
	}

	imageLabel->setPixmap(QPixmap::fromImage(image));

	imageLabel->adjustSize();
}

void MainWindow::DisplayMusic(const QString& filePath)
{
}

void MainWindow::DisplayVideo(const QString& filePath)
{
}