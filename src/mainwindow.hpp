#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <qlabel.h>
#include <qmainwindow.h>
#include <qscopedpointer.h>
#include <qsharedpointer.h>
#include <qstackedwidget.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>
#include <qwidget.h>
#include "qtmultimedia/qaudiooutput.h"
#include "qtmultimedia/qmediaplayer.h"
#include "qtmultimediawidgets/qvideowidget.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	bool isImageFile(const QString& filePath);
	bool isMusicFile(const QString& filePath);
	bool isVideoFile(const QString& filePath);
	void DisplayImage(const QString& filePath);
	void DisplayMusic(const QString& filePath);
	void DisplayVideo(const QString& filePath);
	void ProcessFile(const QString& filePath);

private slots:
	void PositionChanged(qint64 position);

private:
	Ui::MainWindow* ui;
	QLabel* imageLabel;
	QMediaPlayer* player;
	QAudioOutput* audioOutput;
	QVideoWidget* videoOutput;
	QStackedWidget* stackedWidget;
};

#endif // MAINWINDOW_H
