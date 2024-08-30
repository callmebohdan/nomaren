#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <qlabel.h>
#include <qmainwindow.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
};

#endif // MAINWINDOW_H
