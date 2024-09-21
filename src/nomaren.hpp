#ifndef NOMAREN_HPP
#define NOMAREN_HPP

#include <qaudiooutput.h>
#include <qevent.h>
#include <qlabel.h>
#include <qmainwindow.h>
#include <qmediaplayer.h>
#include <qplaintextedit.h>
#include <qstackedwidget.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>
#include <qvideowidget.h>
#include <qwidget.h>

namespace Ui { class Nomaren; }

class Nomaren : public QMainWindow {
	Q_OBJECT

public:
	explicit Nomaren(QWidget* parent = nullptr);
	~Nomaren();

	void DecreaseVolume();
	void ToggleFullScreen();
	void IncreaseVolume();
	QString convertMillisecondsToHMS(qint64 milliseconds);
	void ToggleVolume();
	void TogglePausePlay();
	void ShowAboutSection();
	void ShowDocumentProperties();
	bool IsImageFile(const QString& filePath);
	bool IsMusicFile(const QString& filePath);
	bool IsTextFile(const QString& filePath);
	bool IsVideoFile(const QString& filePath);
	void DisplayImage(const QString& filePath);
	void DisplayMusic(const QString& filePath);
	void DisplayText(const QString& filePath);
	void DisplayVideo(const QString& filePath);
	void ClosePreviousFile();

public slots:
	void ProcessFileFromCommandLine(const QString& filePath);
	void ProcessFileFromUserPrompt();
	void keyPressEvent(QKeyEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent* event);

private:
	Ui::Nomaren* ui;
	QLabel* imageLabel;
	QPlainTextEdit* textEdit;
	QMediaPlayer* player;
	QAudioOutput* audioOutput;
	QVideoWidget* videoOutput;
	QWidget* musicWidget;
	QStackedWidget* stackedWidget;
};

#endif // NOMAREN_HPP
