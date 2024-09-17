/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionZoomIn;
    QAction *actionPreferences;
    QAction *actionOpenMediaFile;
    QAction *actionZoomOut;
    QAction *actionMediaPlaybackPause;
    QAction *actionMediaPlaybackStart;
    QAction *actionMediaPlaybackStop;
    QAction *actionDocumentProperties;
    QAction *actionToggleVolume;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSlider *volumeSlider;
    QStackedWidget *stackedWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(960, 540);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionExit->setIcon(icon);
        actionExit->setMenuRole(QAction::MenuRole::NoRole);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName("actionZoomIn");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ZoomIn));
        actionZoomIn->setIcon(icon1);
        actionZoomIn->setMenuRole(QAction::MenuRole::NoRole);
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName("actionPreferences");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        actionPreferences->setIcon(icon2);
        actionPreferences->setMenuRole(QAction::MenuRole::NoRole);
        actionOpenMediaFile = new QAction(MainWindow);
        actionOpenMediaFile->setObjectName("actionOpenMediaFile");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionOpenMediaFile->setIcon(icon3);
        actionOpenMediaFile->setMenuRole(QAction::MenuRole::NoRole);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName("actionZoomOut");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::ZoomOut));
        actionZoomOut->setIcon(icon4);
        actionZoomOut->setMenuRole(QAction::MenuRole::NoRole);
        actionMediaPlaybackPause = new QAction(MainWindow);
        actionMediaPlaybackPause->setObjectName("actionMediaPlaybackPause");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause));
        actionMediaPlaybackPause->setIcon(icon5);
        actionMediaPlaybackPause->setShortcutContext(Qt::ShortcutContext::WindowShortcut);
        actionMediaPlaybackPause->setMenuRole(QAction::MenuRole::NoRole);
        actionMediaPlaybackStart = new QAction(MainWindow);
        actionMediaPlaybackStart->setObjectName("actionMediaPlaybackStart");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        actionMediaPlaybackStart->setIcon(icon6);
        actionMediaPlaybackStart->setMenuRole(QAction::MenuRole::NoRole);
        actionMediaPlaybackStop = new QAction(MainWindow);
        actionMediaPlaybackStop->setObjectName("actionMediaPlaybackStop");
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStop));
        actionMediaPlaybackStop->setIcon(icon7);
        actionMediaPlaybackStop->setMenuRole(QAction::MenuRole::NoRole);
        actionDocumentProperties = new QAction(MainWindow);
        actionDocumentProperties->setObjectName("actionDocumentProperties");
        actionDocumentProperties->setIcon(icon2);
        actionDocumentProperties->setMenuRole(QAction::MenuRole::NoRole);
        actionToggleVolume = new QAction(MainWindow);
        actionToggleVolume->setObjectName("actionToggleVolume");
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeHigh));
        actionToggleVolume->setIcon(icon8);
        actionToggleVolume->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon9);
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy);
        volumeSlider->setMaximumSize(QSize(75, 16777215));
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(volumeSlider);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 960, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menuFile->sizePolicy().hasHeightForWidth());
        menuFile->setSizePolicy(sizePolicy1);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionOpenMediaFile);
        toolBar->addAction(actionExit);
        toolBar->addAction(actionDocumentProperties);
        toolBar->addSeparator();
        toolBar->addAction(actionMediaPlaybackPause);
        toolBar->addAction(actionMediaPlaybackStart);
        toolBar->addAction(actionMediaPlaybackStop);
        toolBar->addSeparator();
        toolBar->addAction(actionToggleVolume);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "nomaren", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#endif // QT_CONFIG(tooltip)
        actionZoomIn->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        actionPreferences->setText(QCoreApplication::translate("MainWindow", "Preferences", nullptr));
        actionOpenMediaFile->setText(QCoreApplication::translate("MainWindow", "Open Media File", nullptr));
        actionZoomOut->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
        actionMediaPlaybackPause->setText(QCoreApplication::translate("MainWindow", "Media Playback Pause", nullptr));
#if QT_CONFIG(tooltip)
        actionMediaPlaybackPause->setToolTip(QCoreApplication::translate("MainWindow", "Media Playback Pause", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMediaPlaybackStart->setText(QCoreApplication::translate("MainWindow", "Media Playback Start", nullptr));
#if QT_CONFIG(tooltip)
        actionMediaPlaybackStart->setToolTip(QCoreApplication::translate("MainWindow", "Media Playback Start", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMediaPlaybackStop->setText(QCoreApplication::translate("MainWindow", "Media Playback Stop", nullptr));
#if QT_CONFIG(tooltip)
        actionMediaPlaybackStop->setToolTip(QCoreApplication::translate("MainWindow", "Media Playback Stop", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDocumentProperties->setText(QCoreApplication::translate("MainWindow", "Document Properties", nullptr));
#if QT_CONFIG(tooltip)
        actionDocumentProperties->setToolTip(QCoreApplication::translate("MainWindow", "Document Properties", nullptr));
#endif // QT_CONFIG(tooltip)
        actionToggleVolume->setText(QCoreApplication::translate("MainWindow", "Toggle Audio Volume", nullptr));
#if QT_CONFIG(tooltip)
        actionToggleVolume->setToolTip(QCoreApplication::translate("MainWindow", "Toggle Audio Volume", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
