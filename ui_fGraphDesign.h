/********************************************************************************
** Form generated from reading UI file 'fGraphDesign.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FGRAPHDESIGN_H
#define UI_FGRAPHDESIGN_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QGraphicsViewEc.h"

QT_BEGIN_NAMESPACE

class Ui_fGraphDesign
{
public:
    QAction *actionNodo;
    QAction *actionArco;
    QAction *actionGrafoCasuale;
    QAction *actionK_percorsi;
    QAction *actionCancella;
    QAction *actionDot;
    QAction *actionCentra;
    QAction *actionSalva;
    QAction *actionCarica;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsViewEc *graphicsView;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *fGraphDesign)
    {
        if (fGraphDesign->objectName().isEmpty())
            fGraphDesign->setObjectName(QStringLiteral("fGraphDesign"));
        fGraphDesign->resize(800, 600);
        fGraphDesign->setMinimumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QStringLiteral("images/molecule.png"), QSize(), QIcon::Normal, QIcon::Off);
        fGraphDesign->setWindowIcon(icon);
        fGraphDesign->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionNodo = new QAction(fGraphDesign);
        actionNodo->setObjectName(QStringLiteral("actionNodo"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNodo->setIcon(icon1);
        actionArco = new QAction(fGraphDesign);
        actionArco->setObjectName(QStringLiteral("actionArco"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/arrow_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArco->setIcon(icon2);
        actionGrafoCasuale = new QAction(fGraphDesign);
        actionGrafoCasuale->setObjectName(QStringLiteral("actionGrafoCasuale"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("images/dice.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGrafoCasuale->setIcon(icon3);
        actionK_percorsi = new QAction(fGraphDesign);
        actionK_percorsi->setObjectName(QStringLiteral("actionK_percorsi"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("images/chart_stock.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionK_percorsi->setIcon(icon4);
        actionCancella = new QAction(fGraphDesign);
        actionCancella->setObjectName(QStringLiteral("actionCancella"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("images/broom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCancella->setIcon(icon5);
        actionDot = new QAction(fGraphDesign);
        actionDot->setObjectName(QStringLiteral("actionDot"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("images/page_white_code_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDot->setIcon(icon6);
        actionCentra = new QAction(fGraphDesign);
        actionCentra->setObjectName(QStringLiteral("actionCentra"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("images/zoom_fit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCentra->setIcon(icon7);
        actionSalva = new QAction(fGraphDesign);
        actionSalva->setObjectName(QStringLiteral("actionSalva"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("images/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalva->setIcon(icon8);
        actionCarica = new QAction(fGraphDesign);
        actionCarica->setObjectName(QStringLiteral("actionCarica"));
        QIcon icon9;
        icon9.addFile(QStringLiteral("images/folder_page.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCarica->setIcon(icon9);
        actionAbout = new QAction(fGraphDesign);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon10;
        icon10.addFile(QStringLiteral("images/info_rhombus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon10);
        centralwidget = new QWidget(fGraphDesign);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsViewEc(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        verticalLayout->addWidget(graphicsView);

        fGraphDesign->setCentralWidget(centralwidget);
        toolBar = new QToolBar(fGraphDesign);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar->setFloatable(false);
        fGraphDesign->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(fGraphDesign);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        fGraphDesign->setStatusBar(statusBar);

        toolBar->addAction(actionCarica);
        toolBar->addAction(actionSalva);
        toolBar->addSeparator();
        toolBar->addAction(actionDot);
        toolBar->addAction(actionGrafoCasuale);
        toolBar->addSeparator();
        toolBar->addAction(actionCentra);
        toolBar->addAction(actionCancella);
        toolBar->addSeparator();
        toolBar->addAction(actionK_percorsi);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout);

        retranslateUi(fGraphDesign);
        QObject::connect(actionArco, SIGNAL(triggered()), fGraphDesign, SLOT(bArcoClicked()));
        QObject::connect(actionNodo, SIGNAL(triggered()), fGraphDesign, SLOT(bNodoClicked()));
        QObject::connect(actionGrafoCasuale, SIGNAL(triggered()), fGraphDesign, SLOT(bCasualeClicked()));
        QObject::connect(actionK_percorsi, SIGNAL(triggered()), fGraphDesign, SLOT(bKPercorsi()));
        QObject::connect(actionCancella, SIGNAL(triggered()), fGraphDesign, SLOT(bPulisci()));
        QObject::connect(actionDot, SIGNAL(triggered()), fGraphDesign, SLOT(bDot()));
        QObject::connect(actionCentra, SIGNAL(triggered()), fGraphDesign, SLOT(bCentra()));
        QObject::connect(actionSalva, SIGNAL(triggered()), fGraphDesign, SLOT(bSalva()));
        QObject::connect(actionCarica, SIGNAL(triggered()), fGraphDesign, SLOT(bCarica()));
        QObject::connect(actionAbout, SIGNAL(triggered()), fGraphDesign, SLOT(bAbout()));

        QMetaObject::connectSlotsByName(fGraphDesign);
    } // setupUi

    void retranslateUi(QMainWindow *fGraphDesign)
    {
        fGraphDesign->setWindowTitle(QApplication::translate("fGraphDesign", "KPaths", 0));
        actionNodo->setText(QApplication::translate("fGraphDesign", "Vertex", 0));
#ifndef QT_NO_TOOLTIP
        actionNodo->setToolTip(QApplication::translate("fGraphDesign", "Create a new vertex", 0));
#endif // QT_NO_TOOLTIP
        actionNodo->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+N", 0));
        actionArco->setText(QApplication::translate("fGraphDesign", "Edge", 0));
#ifndef QT_NO_TOOLTIP
        actionArco->setToolTip(QApplication::translate("fGraphDesign", "Create a new edge", 0));
#endif // QT_NO_TOOLTIP
        actionArco->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+E", 0));
        actionGrafoCasuale->setText(QApplication::translate("fGraphDesign", "Random", 0));
#ifndef QT_NO_TOOLTIP
        actionGrafoCasuale->setToolTip(QApplication::translate("fGraphDesign", "Create a random graph", 0));
#endif // QT_NO_TOOLTIP
        actionGrafoCasuale->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+R", 0));
        actionK_percorsi->setText(QApplication::translate("fGraphDesign", "K paths", 0));
#ifndef QT_NO_TOOLTIP
        actionK_percorsi->setToolTip(QApplication::translate("fGraphDesign", "Find k paths", 0));
#endif // QT_NO_TOOLTIP
        actionK_percorsi->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+K", 0));
        actionCancella->setText(QApplication::translate("fGraphDesign", "Clean", 0));
#ifndef QT_NO_TOOLTIP
        actionCancella->setToolTip(QApplication::translate("fGraphDesign", "Clean the form", 0));
#endif // QT_NO_TOOLTIP
        actionCancella->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+C", 0));
        actionDot->setText(QApplication::translate("fGraphDesign", "Dot", 0));
#ifndef QT_NO_TOOLTIP
        actionDot->setToolTip(QApplication::translate("fGraphDesign", "Open dot language editor", 0));
#endif // QT_NO_TOOLTIP
        actionDot->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+D", 0));
        actionCentra->setText(QApplication::translate("fGraphDesign", "Center", 0));
        actionCentra->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+Z", 0));
        actionSalva->setText(QApplication::translate("fGraphDesign", "Save", 0));
        actionSalva->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+S", 0));
        actionCarica->setText(QApplication::translate("fGraphDesign", "Load", 0));
        actionCarica->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+L", 0));
        actionAbout->setText(QApplication::translate("fGraphDesign", "About", 0));
        actionAbout->setShortcut(QApplication::translate("fGraphDesign", "Ctrl+I", 0));
        toolBar->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class fGraphDesign: public Ui_fGraphDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FGRAPHDESIGN_H
