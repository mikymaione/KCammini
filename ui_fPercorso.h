/********************************************************************************
** Form generated from reading UI file 'fPercorso.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FPERCORSO_H
#define UI_FPERCORSO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_fPercorso
{
public:
    QGridLayout *gridLayout;
    QListWidget *eLista;

    void setupUi(QDialog *fPercorso)
    {
        if (fPercorso->objectName().isEmpty())
            fPercorso->setObjectName(QStringLiteral("fPercorso"));
        fPercorso->resize(519, 551);
        QIcon icon;
        icon.addFile(QStringLiteral("images/molecule.png"), QSize(), QIcon::Normal, QIcon::Off);
        fPercorso->setWindowIcon(icon);
        gridLayout = new QGridLayout(fPercorso);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        eLista = new QListWidget(fPercorso);
        eLista->setObjectName(QStringLiteral("eLista"));
        eLista->setAutoFillBackground(false);

        gridLayout->addWidget(eLista, 0, 0, 1, 1);


        retranslateUi(fPercorso);

        QMetaObject::connectSlotsByName(fPercorso);
    } // setupUi

    void retranslateUi(QDialog *fPercorso)
    {
        fPercorso->setWindowTitle(QApplication::translate("fPercorso", "Paths", 0));
    } // retranslateUi

};

namespace Ui {
    class fPercorso: public Ui_fPercorso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FPERCORSO_H
