/********************************************************************************
** Form generated from reading UI file 'nomaren.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOMAREN_H
#define UI_NOMAREN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nomaren
{
public:
    QAction *actionExit;
    QAction *actionZoomIn;
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
    QStackedWidget *stackedWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *toolBar;
    QToolBar *playbackToolBar;

    void setupUi(QMainWindow *Nomaren)
    {
        if (Nomaren->objectName().isEmpty())
            Nomaren->setObjectName("Nomaren");
        Nomaren->resize(960, 540);
        actionExit = new QAction(Nomaren);
        actionExit->setObjectName("actionExit");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionExit->setIcon(icon);
        actionZoomIn = new QAction(Nomaren);
        actionZoomIn->setObjectName("actionZoomIn");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ZoomIn));
        actionZoomIn->setIcon(icon1);
        actionOpenMediaFile = new QAction(Nomaren);
        actionOpenMediaFile->setObjectName("actionOpenMediaFile");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionOpenMediaFile->setIcon(icon2);
        actionZoomOut = new QAction(Nomaren);
        actionZoomOut->setObjectName("actionZoomOut");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ZoomOut));
        actionZoomOut->setIcon(icon3);
        actionMediaPlaybackPause = new QAction(Nomaren);
        actionMediaPlaybackPause->setObjectName("actionMediaPlaybackPause");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause));
        actionMediaPlaybackPause->setIcon(icon4);
        actionMediaPlaybackPause->setShortcutContext(Qt::ShortcutContext::WindowShortcut);
        actionMediaPlaybackStart = new QAction(Nomaren);
        actionMediaPlaybackStart->setObjectName("actionMediaPlaybackStart");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        actionMediaPlaybackStart->setIcon(icon5);
        actionMediaPlaybackStop = new QAction(Nomaren);
        actionMediaPlaybackStop->setObjectName("actionMediaPlaybackStop");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStop));
        actionMediaPlaybackStop->setIcon(icon6);
        actionDocumentProperties = new QAction(Nomaren);
        actionDocumentProperties->setObjectName("actionDocumentProperties");
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        actionDocumentProperties->setIcon(icon7);
        actionToggleVolume = new QAction(Nomaren);
        actionToggleVolume->setObjectName("actionToggleVolume");
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeHigh));
        actionToggleVolume->setIcon(icon8);
        actionAbout = new QAction(Nomaren);
        actionAbout->setObjectName("actionAbout");
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon9);
        centralwidget = new QWidget(Nomaren);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);

        Nomaren->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(Nomaren);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 960, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuFile->sizePolicy().hasHeightForWidth());
        menuFile->setSizePolicy(sizePolicy);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        Nomaren->setMenuBar(menuBar);
        toolBar = new QToolBar(Nomaren);
        toolBar->setObjectName("toolBar");
        Nomaren->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        playbackToolBar = new QToolBar(Nomaren);
        playbackToolBar->setObjectName("playbackToolBar");
        Nomaren->addToolBar(Qt::ToolBarArea::BottomToolBarArea, playbackToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionOpenMediaFile);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);
        toolBar->addSeparator();
        toolBar->addAction(actionMediaPlaybackPause);
        toolBar->addAction(actionMediaPlaybackStart);
        toolBar->addAction(actionMediaPlaybackStop);
        toolBar->addSeparator();
        toolBar->addAction(actionToggleVolume);
        toolBar->addSeparator();
        toolBar->addAction(actionZoomIn);
        toolBar->addAction(actionZoomOut);
        toolBar->addSeparator();
        toolBar->addAction(actionDocumentProperties);
        toolBar->addSeparator();

        retranslateUi(Nomaren);

        QMetaObject::connectSlotsByName(Nomaren);
    } // setupUi

    void retranslateUi(QMainWindow *Nomaren)
    {
        Nomaren->setWindowTitle(QCoreApplication::translate("Nomaren", "nomaren", nullptr));
        actionExit->setText(QCoreApplication::translate("Nomaren", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("Nomaren", "Exit", nullptr));
#endif // QT_CONFIG(tooltip)
        actionZoomIn->setText(QCoreApplication::translate("Nomaren", "Zoom In", nullptr));
        actionOpenMediaFile->setText(QCoreApplication::translate("Nomaren", "Open Media File", nullptr));
        actionZoomOut->setText(QCoreApplication::translate("Nomaren", "Zoom Out", nullptr));
        actionMediaPlaybackPause->setText(QCoreApplication::translate("Nomaren", "Media Playback Pause", nullptr));
#if QT_CONFIG(tooltip)
        actionMediaPlaybackPause->setToolTip(QCoreApplication::translate("Nomaren", "Media Playback Pause", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMediaPlaybackStart->setText(QCoreApplication::translate("Nomaren", "Media Playback Start", nullptr));
#if QT_CONFIG(tooltip)
        actionMediaPlaybackStart->setToolTip(QCoreApplication::translate("Nomaren", "Media Playback Start", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMediaPlaybackStop->setText(QCoreApplication::translate("Nomaren", "Media Playback Stop", nullptr));
#if QT_CONFIG(tooltip)
        actionMediaPlaybackStop->setToolTip(QCoreApplication::translate("Nomaren", "Media Playback Stop", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDocumentProperties->setText(QCoreApplication::translate("Nomaren", "Document Properties", nullptr));
#if QT_CONFIG(tooltip)
        actionDocumentProperties->setToolTip(QCoreApplication::translate("Nomaren", "Document Properties", nullptr));
#endif // QT_CONFIG(tooltip)
        actionToggleVolume->setText(QCoreApplication::translate("Nomaren", "Toggle Audio Volume", nullptr));
#if QT_CONFIG(tooltip)
        actionToggleVolume->setToolTip(QCoreApplication::translate("Nomaren", "Toggle Audio Volume", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAbout->setText(QCoreApplication::translate("Nomaren", "About", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Nomaren", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Nomaren", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Nomaren", "toolBar", nullptr));
        playbackToolBar->setWindowTitle(QCoreApplication::translate("Nomaren", "playbackToolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nomaren: public Ui_Nomaren {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOMAREN_H
