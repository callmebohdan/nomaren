#include <qaudiooutput.h>
#include <qboxlayout.h>
#include <qcontainerfwd.h>
#include <qdir.h>
#include <qfile.h>
#include <qfileinfo.h>
#include <qimage.h>
#include <qinputdialog.h>
#include <qiodevice.h>
#include <qiodevicebase.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlogging.h>
#include <qmainwindow.h>
#include <qmediaplayer.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qplaintextedit.h>
#include <qsizepolicy.h>
#include <qstackedwidget.h>
#include <qstring.h>
#include <qtextstream.h>
#include <qurl.h>
#include <qvideowidget.h>
#include <qwidget.h>
#include "./ui_mainwindow.h"
#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, imageLabel(new QLabel(this))
	, textEdit(new QPlainTextEdit(this))
	, player(new QMediaPlayer(this))
	, audioOutput(new QAudioOutput(this))
	, musicWidget(new QWidget(this))
	, videoOutput(new QVideoWidget(this))
	, stackedWidget(new QStackedWidget(this))
{
	ui->setupUi(this);
	move(screen()->geometry().center() - frameGeometry().center());

	imageLabel->setAlignment(Qt::AlignCenter);

	stackedWidget->addWidget(imageLabel);
	stackedWidget->addWidget(textEdit);
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

MainWindow::~MainWindow() {
	delete ui;
	ui = nullptr;
}

bool MainWindow::IsImageFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList imageExtensions = {"bmp", "gif", "jpeg", "jpg", "png", "pbm", "pgm", "ppm", "tiff", "xbm", "xpm", "webp", "ico", "dds", "tga", "heif", "avif"};
	return imageExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

bool MainWindow::IsMusicFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList musicExtensions = {"mp3", "wav", "flac", "aac", "ogg", "wma", "m4a", "aiff"};
	return musicExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

bool MainWindow::IsTextFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList textExtensions = {
	"txt", "md", "log", "csv", "json", "xml", "html", "htm", "ini", "yml", "yaml", "rtf"};
	return textExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

bool MainWindow::IsVideoFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList videoExtensions = {"mp4", "avi", "mkv", "mov", "flv", "wmv", "webm", "mpg", "mpeg", "3gp"};
	return videoExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

void MainWindow::ProcessFileFromCommandLine(const QString& filePath) {
	if (!imageLabel || !stackedWidget || !videoOutput || !textEdit || !musicWidget) {
		QMessageBox::critical(this, "Error", "One or more components are not initialized.");
		return;
	}

	bool isImage = IsImageFile(filePath);
	bool isMusic = IsMusicFile(filePath);
	bool isText = IsTextFile(filePath);
	bool isVideo = IsVideoFile(filePath);

	ClosePreviousFile();

	if (isImage) {
		DisplayImage(filePath);
		stackedWidget->setCurrentWidget(imageLabel);
	}
	else if (isMusic) {
		DisplayMusic(filePath);
		stackedWidget->addWidget(musicWidget);
	}
	else if (isText) {
		DisplayText(filePath);
		stackedWidget->setCurrentWidget(textEdit);
	}
	else if (isVideo) {
		DisplayVideo(filePath);
		stackedWidget->setCurrentWidget(videoOutput);
	}
	else {
		QMessageBox::warning(this, "Unsupported File", "The file type is not supported.");
	}
}

void MainWindow::ProcessFileFromUserPrompt() {
	bool ok;
	QString text = QInputDialog::getText(this, tr("Open File"), tr("File Path:"), QLineEdit::Normal, QDir::home().dirName(), &ok);
	if (ok && !text.isEmpty()) {
		ProcessFileFromCommandLine(text);
	}
}

void MainWindow::ClosePreviousFile() {
	imageLabel->clear();
	textEdit->clear();
	player->stop();
	player->setSource(QUrl());
	player->setPosition(0);
}

void MainWindow::DisplayImage(const QString& filePath) {
	QImage image(filePath);

	if (image.isNull()) {
		qDebug() << "Error: Invalid image file.";
		QMessageBox::critical(this, "Error", "Failed to load image: " + filePath);
		return;
	}
	imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	imageLabel->setPixmap(QPixmap::fromImage(image));

	stackedWidget->setCurrentWidget(imageLabel);
}

void MainWindow::DisplayMusic(const QString& filePath) {
	player->setSource(QUrl::fromLocalFile(filePath));

	if (!player->source().isValid()) {
		qDebug() << "Error: Invalid music file.";
		QMessageBox::critical(this, "Error", "Failed to load music: " + filePath);
		return;
	}

	player->play();
}

void MainWindow::DisplayText(const QString& filePath) {
	QFile text(filePath);
	if (!text.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Could not open text file: " << filePath;
		return;
	}

	QTextStream in(&text);
	QString fileContent = in.readAll();
	text.close();

	textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	textEdit->setPlainText(fileContent);

	stackedWidget->setCurrentWidget(textEdit);
}

void MainWindow::DisplayVideo(const QString& filePath) {
	player->setSource(QUrl::fromLocalFile(filePath));

	if (!player->source().isValid()) {
		qDebug() << "Error: Invalid video file.";
		QMessageBox::critical(this, "Error", "Failed to load video: " + filePath);
		return;
	}

	videoOutput->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	player->play();

	stackedWidget->setCurrentWidget(videoOutput);
}
