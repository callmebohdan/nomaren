#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <qlabel.h>
#include <qmainwindow.h>
#include <qstring.h>
#include <qtconfigmacros.h>
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

	void displayImage(const QString& filePath);

private:
	Ui::MainWindow* ui;
	QLabel* imageLabel;
};

#endif // MAINWINDOW_H
