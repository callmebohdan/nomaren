#include <qboxlayout.h>
#include <qcontainerfwd.h>
#include <qfileinfo.h>
#include <qimage.h>
#include <qlabel.h>
#include <qlogging.h>
#include <qmainwindow.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qsizepolicy.h>
#include <qstackedwidget.h>
#include <qstring.h>
#include <qtypes.h>
#include <qurl.h>
#include <qwidget.h>
#include "./ui_mainwindow.h"
#include "mainwindow.hpp"
#include "qtmultimedia/qaudiooutput.h"
#include "qtmultimedia/qmediaplayer.h"
#include "qtmultimediawidgets/qvideowidget.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, imageLabel(new QLabel(this))
	, player(new QMediaPlayer(this))
	, audioOutput(new QAudioOutput(this))
	, videoOutput(new QVideoWidget(this))
	, stackedWidget(new QStackedWidget(this))
{
	ui->setupUi(this);

	imageLabel->setAlignment(Qt::AlignCenter);
	stackedWidget->addWidget(imageLabel);
	stackedWidget->addWidget(videoOutput);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(stackedWidget);
	layout->setContentsMargins(0, 0, 0, 0);

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(layout);
	setCentralWidget(centralWidget);

	player->setVideoOutput(videoOutput);
	player->setAudioOutput(audioOutput);
}

MainWindow::~MainWindow()
{
	delete ui;
}

bool MainWindow::isImageFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList imageExtensions = {"bmp", "gif", "jpeg", "jpg", "png", "pbm", "pgm", "ppm", "tiff", "xbm", "xpm", "webp", "ico", "dds", "tga", "heif", "avif"};
	return imageExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

bool MainWindow::isMusicFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList musicExtensions = {"mp3", "wav", "flac", "aac", "ogg", "wma", "m4a", "aiff"};
	return musicExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

bool MainWindow::isVideoFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList videoExtensions = {"mp4", "avi", "mkv", "mov", "flv", "wmv", "webm", "mpg", "mpeg", "3gp"};
	return videoExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

void MainWindow::ProcessFile(const QString& filePath)
{
	if (!imageLabel || !stackedWidget || !videoOutput) {
		QMessageBox::critical(this, "Error", "One or more components are not initialized.");
		return;
	}

	bool isImage = isImageFile(filePath);
	bool isMusic = isMusicFile(filePath);
	bool isVideo = isVideoFile(filePath);

	if (isImage) {
		DisplayImage(filePath);
		stackedWidget->setCurrentWidget(imageLabel);
	}
	if (isMusic) {
		stackedWidget->setCurrentWidget(nullptr);
		DisplayMusic(filePath);
	}
	if (isVideo) {
		DisplayVideo(filePath);
		stackedWidget->setCurrentWidget(videoOutput);
	}
	else {
		QMessageBox::warning(this, "Unsupported File", "The file type is not supported.");
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
	imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	imageLabel->setPixmap(QPixmap::fromImage(image));
	imageLabel->adjustSize();

	stackedWidget->setCurrentWidget(imageLabel);
}

void MainWindow::DisplayMusic(const QString& filePath)
{
	player->stop();
	player->setSource(QUrl::fromLocalFile(filePath));

	if (!player->source().isValid()) {
		qDebug() << "Error: Invalid music file.";
		QMessageBox::critical(this, "Error", "Failed to load music: " + filePath);
		return;
	}

	player->play();
}

void MainWindow::DisplayVideo(const QString& filePath)
{
	player->stop();
	player->setSource(QUrl::fromLocalFile(filePath));

	if (!player->source().isValid()) {
		qDebug() << "Error: Invalid video file.";
		QMessageBox::critical(this, "Error", "Failed to load video: " + filePath);
		return;
	}

	videoOutput->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	videoOutput->setFullScreen(true);
	videoOutput->show();

	player->play();

	stackedWidget->setCurrentWidget(videoOutput);
}
