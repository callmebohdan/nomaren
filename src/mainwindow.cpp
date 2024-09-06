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
#include <qsharedpointer.h>
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
	stackedWidget->addWidget(imageLabel.data());

	stackedWidget->addWidget(videoOutput.data());

	setCentralWidget(stackedWidget.data());

	QSharedPointer<QVBoxLayout> layout(new QVBoxLayout(this));
	layout->addWidget(stackedWidget.data());
	layout->setContentsMargins(0, 0, 0, 0);

	QSharedPointer<QWidget> centralWidget(new QWidget(this));
	centralWidget->setLayout(layout.data());
	setCentralWidget(centralWidget.data());

	player->setVideoOutput(videoOutput.data());
	player->setAudioOutput(audioOutput.data());
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
		stackedWidget->setCurrentWidget(imageLabel.data());
	}
	else if (isMusic) {
		DisplayMusic(filePath);
	}
	else if (isVideo) {
		DisplayVideo(filePath);
		stackedWidget->setCurrentWidget(videoOutput.data());
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

	imageLabel->setPixmap(QPixmap::fromImage(image));
	imageLabel->adjustSize();

	stackedWidget->setCurrentWidget(imageLabel.data());
}

void MainWindow::DisplayMusic(const QString& filePath)
{
	player->setSource(QUrl::fromLocalFile(filePath));
	player->play();
}

void MainWindow::DisplayVideo(const QString& filePath)
{
	videoOutput->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	videoOutput->show();

	player->setSource(QUrl::fromLocalFile(filePath));
	player->play();

	stackedWidget->setCurrentWidget(videoOutput.data());
}
