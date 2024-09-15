#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <qaudiooutput.h>
#include <qlabel.h>
#include <qmainwindow.h>
#include <qmediaplayer.h>
#include <qplaintextedit.h>
#include <qstackedwidget.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qvideowidget.h>
#include <qwidget.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	bool isImageFile(const QString& filePath);
	bool isMusicFile(const QString& filePath);
	bool isTextFile(const QString& filePath);
	bool isVideoFile(const QString& filePath);
	bool IsImageFile(const QString& filePath);
	bool IsMusicFile(const QString& filePath);
	bool IsTextFile(const QString& filePath);
	bool IsVideoFile(const QString& filePath);
	void DisplayImage(const QString& filePath);
	void DisplayMusic(const QString& filePath);
	void DisplayText(const QString& filePath);
	void DisplayVideo(const QString& filePath);
	void ClosePreviousFile();
	void ProcessFileFromCommandLine(const QString& filePath);
	void ProcessFileFromUserPrompt();

private:
	Ui::MainWindow* ui;
	QLabel* imageLabel;
	QPlainTextEdit* textEdit;
	QMediaPlayer* player;
	QAudioOutput* audioOutput;
	QVideoWidget* videoOutput;
	QWidget* musicWidget;
	QStackedWidget* stackedWidget;
};

#endif // MAINWINDOW_H
