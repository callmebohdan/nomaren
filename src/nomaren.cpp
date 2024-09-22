#include <qaction.h>
#include <qaudiooutput.h>
#include <qboxlayout.h>
#include <qcontainerfwd.h>
#include <qdir.h>
#include <qevent.h>
#include <qfile.h>
#include <qfileinfo.h>
#include <qforeach.h>
#include <qimage.h>
#include <qinputdialog.h>
#include <qiodevice.h>
#include <qiodevicebase.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlogging.h>
#include <qmainwindow.h>
#include <qmediametadata.h>
#include <qmediaplayer.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qplaintextedit.h>
#include <qsizepolicy.h>
#include <qslider.h>
#include <qstackedwidget.h>
#include <qstring.h>
#include <qtextstream.h>
#include <qtoolbar.h>
#include <qtypes.h>
#include <qurl.h>
#include <qvariant.h>
#include <qvideowidget.h>
#include <qwidget.h>
#include "nomaren.hpp"
#include "ui_nomaren.h"

Nomaren::Nomaren(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::Nomaren)
	, imageLabel(new QLabel(this))
	, textEdit(new QPlainTextEdit(this))
	, player(new QMediaPlayer(this))
	, audioOutput(new QAudioOutput(this))
	, musicWidget(new QWidget(this))
	, videoOutput(new QVideoWidget(this))
	, stackedWidget(new QStackedWidget(this))
{
	ui->setupUi(this);
	SetupWindow();
	SetupWidgets();
	SetupActions();
	SetupVolumeSlider();
	SetupPlaybackSlider();
}

void Nomaren::SetupWindow() {
	move(screen()->geometry().center() - frameGeometry().center());
	setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

void Nomaren::SetupWidgets() {
	stackedWidget->addWidget(imageLabel);
	stackedWidget->addWidget(musicWidget);
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

void Nomaren::SetupActions() {
	connect(ui->actionOpenMediaFile, &QAction::triggered, this, &Nomaren::ProcessFileFromUserPrompt);
	connect(ui->actionExit, &QAction::triggered, this, &QMainWindow::close);
	connect(ui->actionMediaPlaybackPause, &QAction::triggered, player, &QMediaPlayer::pause);
	connect(ui->actionMediaPlaybackStart, &QAction::triggered, player, &QMediaPlayer::play);
	connect(ui->actionMediaPlaybackStop, &QAction::triggered, player, &QMediaPlayer::stop);
	connect(ui->actionToggleVolume, &QAction::triggered, this, &Nomaren::ToggleVolume);
	connect(ui->actionAbout, &QAction::triggered, this, &Nomaren::ShowAboutSection);
	connect(ui->actionDocumentProperties, &QAction::triggered, this, &Nomaren::ShowDocumentProperties);
	connect(ui->actionAbout, &QAction::triggered, this, &Nomaren::ShowAboutSection);
}

void Nomaren::SetupVolumeSlider() {
	QSlider* volumeSlider(new QSlider(this));
	volumeSlider->setOrientation(Qt::Orientation::Horizontal);
	volumeSlider->setMaximumSize(75, 30);
	volumeSlider->setRange(0, 100);
	volumeSlider->setValue(player->audioOutput()->volume() * 100);
	ui->toolBar->insertWidget(ui->toolBar->actions().value(9), volumeSlider);
	connect(volumeSlider, &QSlider::valueChanged, this, [=](int value) { audioOutput->setVolume(value / 100.0); });
}

void Nomaren::SetupPlaybackSlider() {
	if (player->videoOutput()) {
		QSlider* playbackSlider(new QSlider(this));
		playbackSlider->setOrientation(Qt::Orientation::Horizontal);
		playbackSlider->setMaximumHeight(30);
		QLabel* playerDuration(new QLabel(this));
		connect(player, &QMediaPlayer::durationChanged, this, [=](qint64 duration) {
			playbackSlider->setRange(0, duration);
			playerDuration->setText("0/" + convertMillisecondsToHMS(duration));
			});
		connect(player, &QMediaPlayer::positionChanged, this, [=](qint64 position) {
			playbackSlider->setValue(position);
			playerDuration->setText(convertMillisecondsToHMS(position) + "/" + convertMillisecondsToHMS(player->duration()));
			});
		connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
			if (status == QMediaPlayer::LoadedMedia || status == QMediaPlayer::BufferedMedia) {
				playerDuration->setText("0/" + convertMillisecondsToHMS(player->duration()));
			}
			});
		connect(playbackSlider, &QSlider::valueChanged, this, [=](int value) { player->setPosition(value); });
		playerDuration->setMaximumHeight(30);
		playbackSlider->setMaximumHeight(30);
		QHBoxLayout* layout = new QHBoxLayout;
		layout->addWidget(playbackSlider);
		layout->addWidget(playerDuration);
		layout->setStretch(0, 30);
		layout->setStretch(1, 1);
		QWidget* container = new QWidget(this);
		container->setLayout(layout);
		ui->playbackToolBar->addWidget(container);
	}
}

QString Nomaren::convertMillisecondsToHMS(qint64 milliseconds) {
	auto totalTime = milliseconds / 1000;

	auto hours = totalTime / 3600;
	totalTime -= hours * 3600;
	auto minutes = totalTime / 60;
	totalTime -= hours * 60;
	auto seconds = totalTime / 60;

	return QString::number(hours) + ":" + QString::number(minutes) + ":" + QString::number(seconds);
}

void Nomaren::ToggleVolume() {
	if (player->audioOutput()) {
		bool isMuted = player->audioOutput()->isMuted();
		player->audioOutput()->setMuted(!isMuted);

		if (isMuted) {
			ui->actionToggleVolume->setText(tr("Unmute"));
		}
		else {
			ui->actionToggleVolume->setText(tr("Mute"));
		}
	}
}

void Nomaren::IncreaseVolume() {
	if (player->audioOutput()) {
		float currentVolume = player->audioOutput()->volume();
		player->audioOutput()->setVolume(currentVolume + 0.10);
	}
}

void Nomaren::DecreaseVolume() {
	if (player->audioOutput()) {
		float currentVolume = player->audioOutput()->volume();
		player->audioOutput()->setVolume(currentVolume - 0.10);
	}
}


void Nomaren::ToggleFullScreen() {
	if (!isFullScreen()) {
		showFullScreen();
		menuBar()->setVisible(false);
		foreach(QToolBar * toolbar, findChildren<QToolBar*>()) {
			toolbar->setVisible(false);
		}
	}
	else {
		showNormal();
		menuBar()->setVisible(true);
		foreach(QToolBar * toolbar, findChildren<QToolBar*>()) {
			toolbar->setVisible(true);
		}
	}
}

void Nomaren::TogglePausePlay() {
	if (player->audioOutput() || player->videoOutput()) {
		if (player->isPlaying()) {
			player->pause();
		}
		else {
			player->play();
		}
	}
}

void Nomaren::ShowAboutSection() {
	QMessageBox::about(this,
		"About nomaren",
		"nomaren is a C++ Cross-Platform Media Player built using the Qt6 framework. "
		"It supports music, pictures, videos, and text.");
}

void Nomaren::ShowDocumentProperties() {
	QString metadataText;

	QMediaMetaData metaData = player->metaData();

	for (auto key : metaData.keys()) {
		QVariant value = metaData.value(key);

		QString stringKey;

		switch (key) {
		case QMediaMetaData::Title:
			stringKey = "Title";
			break;
		case QMediaMetaData::Author:
			stringKey = "Author";
			break;
		case QMediaMetaData::Comment:
			stringKey = "Comment";
			break;
		case QMediaMetaData::Description:
			stringKey = "Description";
			break;
		case QMediaMetaData::Genre:
			stringKey = "Genre";
			break;
		case QMediaMetaData::Date:
			stringKey = "Date";
			break;
		case QMediaMetaData::Language:
			stringKey = "Language";
			break;
		case QMediaMetaData::Publisher:
			stringKey = "Publisher";
			break;
		case QMediaMetaData::Copyright:
			stringKey = "Copyright";
			break;
		case QMediaMetaData::Url:
			stringKey = "Url";
			break;
		case QMediaMetaData::Duration:
			stringKey = "Duration";
			break;
		case QMediaMetaData::MediaType:
			stringKey = "MediaType";
			break;
		case QMediaMetaData::FileFormat:
			stringKey = "FileFormat";
			break;
		case QMediaMetaData::AudioBitRate:
			stringKey = "AudioBitRate";
			break;
		case QMediaMetaData::AudioCodec:
			stringKey = "AudioCodec";
			break;
		case QMediaMetaData::VideoBitRate:
			stringKey = "VideoBitRate";
			break;
		case QMediaMetaData::VideoCodec:
			stringKey = "VideoCodec";
			break;
		case QMediaMetaData::VideoFrameRate:
			stringKey = "VideoFrameRate";
			break;
		case QMediaMetaData::AlbumTitle:
			stringKey = "AlbumTitle";
			break;
		case QMediaMetaData::AlbumArtist:
			stringKey = "AlbumArtist";
			break;
		case QMediaMetaData::ContributingArtist:
			stringKey = "ContributingArtist";
			break;
		case QMediaMetaData::TrackNumber:
			stringKey = "TrackNumber";
			break;
		case QMediaMetaData::Composer:
			stringKey = "Composer";
			break;
		case QMediaMetaData::LeadPerformer:
			stringKey = "LeadPerformer";
			break;
		case QMediaMetaData::ThumbnailImage:
			stringKey = "ThumbnailImage";
			break;
		case QMediaMetaData::CoverArtImage:
			stringKey = "CoverArtImage";
			break;
		case QMediaMetaData::Orientation:
			stringKey = "Orientation";
			break;
		case QMediaMetaData::Resolution:
			stringKey = "Resolution";
			break;
		default:
			stringKey = QString("Unknown Key (%1)").arg(key);
			break;
		}
		metadataText += QString("%1: %2\n").arg(stringKey).arg(value.toString());
	}

	QMessageBox::information(this,
		"Document Properties",
		metadataText);
}

Nomaren::~Nomaren() {
	delete ui;
	ui = nullptr;
}

bool Nomaren::IsImageFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList imageExtensions = {"bmp", "gif", "jpeg", "jpg", "png", "pbm", "pgm", "ppm", "tiff", "xbm", "xpm", "webp", "ico", "dds", "tga", "heif", "avif"};
	return imageExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

bool Nomaren::IsMusicFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList musicExtensions = {"mp3", "wav", "flac", "aac", "ogg", "wma", "m4a", "aiff"};
	return musicExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

bool Nomaren::IsTextFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList textExtensions = {
	"txt", "md", "log", "csv", "json", "xml", "html", "htm", "ini", "yml", "yaml", "rtf"};
	return textExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

bool Nomaren::IsVideoFile(const QString& filePath) {
	QFileInfo file(filePath);
	QString fileExtension = file.suffix();
	static const QStringList videoExtensions = {"mp4", "avi", "mkv", "mov", "flv", "wmv", "webm", "mpg", "mpeg", "3gp"};
	return videoExtensions.contains(fileExtension, Qt::CaseInsensitive);
}

void Nomaren::ProcessFileFromCommandLine(const QString& filePath) {
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
		stackedWidget->setCurrentWidget(musicWidget);
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

void Nomaren::ProcessFileFromUserPrompt() {
	bool ok;
	QString text = QInputDialog::getText(this, tr("Open File"), tr("File Path:"), QLineEdit::Normal, QDir::home().dirName(), &ok);
	if (ok && !text.isEmpty()) {
		ProcessFileFromCommandLine(text);
	}
}

void Nomaren::keyPressEvent(QKeyEvent* event) {
	switch (event->key())
	{
	case Qt::Key_Space:
		TogglePausePlay();
		break;
	case Qt::Key_Up:
		IncreaseVolume();
		break;
	case Qt::Key_Down:
		DecreaseVolume();
		break;
	case Qt::Key_F11:
		ToggleFullScreen();
		break;
	default:
		break;
	}

	QMainWindow::keyPressEvent(event);
}

void Nomaren::mousePressEvent(QMouseEvent* event) {
	switch (event->button())
	{
	case Qt::LeftButton:
		TogglePausePlay();
		break;
	case Qt::RightButton:
	default:
		break;
	}

	QMainWindow::mousePressEvent(event);
}

void Nomaren::wheelEvent(QWheelEvent* event) {
	int delta = event->angleDelta().y();

	if (delta > 0)
	{
		IncreaseVolume();
	}
	else if (delta < 0)
	{
		DecreaseVolume();
	}

	QMainWindow::wheelEvent(event);
}

void Nomaren::ClosePreviousFile() {
	imageLabel->clear();
	textEdit->clear();
	player->stop();
	player->setSource(QUrl());
	player->setPosition(0);
}

void Nomaren::DisplayImage(const QString& filePath) {
	QImage image(filePath);

	if (image.isNull()) {
		qDebug() << "Error: Invalid image file.";
		QMessageBox::critical(this, "Error", "Failed to load image: " + filePath);
		return;
	}

	imageLabel->setAlignment(Qt::AlignCenter);
	imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	imageLabel->setPixmap(QPixmap::fromImage(image));

	stackedWidget->setCurrentWidget(imageLabel);
}

void Nomaren::DisplayMusic(const QString& filePath) {
	player->setSource(QUrl::fromLocalFile(filePath));

	if (!player->source().isValid()) {
		qDebug() << "Error: Invalid music file.";
		QMessageBox::critical(this, "Error", "Failed to load music: " + filePath);
		return;
	}

	player->play();
}

void Nomaren::DisplayText(const QString& filePath) {
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

void Nomaren::DisplayVideo(const QString& filePath) {
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
