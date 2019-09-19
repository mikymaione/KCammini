/********************************************************************************
** Form generated from reading UI file 'fDotLanguage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDOTLANGUAGE_H
#define UI_FDOTLANGUAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_fDotLanguage
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *eDot;

    void setupUi(QDialog *fDotLanguage)
    {
        if (fDotLanguage->objectName().isEmpty())
            fDotLanguage->setObjectName(QStringLiteral("fDotLanguage"));
        fDotLanguage->resize(555, 499);
        QIcon icon;
        icon.addFile(QStringLiteral("images/molecule.png"), QSize(), QIcon::Normal, QIcon::Off);
        fDotLanguage->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(fDotLanguage);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonBox = new QDialogButtonBox(fDotLanguage);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        eDot = new QPlainTextEdit(fDotLanguage);
        eDot->setObjectName(QStringLiteral("eDot"));

        gridLayout_2->addWidget(eDot, 0, 0, 1, 1);


        retranslateUi(fDotLanguage);
        QObject::connect(buttonBox, SIGNAL(accepted()), fDotLanguage, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fDotLanguage, SLOT(reject()));

        QMetaObject::connectSlotsByName(fDotLanguage);
    } // setupUi

    void retranslateUi(QDialog *fDotLanguage)
    {
        fDotLanguage->setWindowTitle(QApplication::translate("fDotLanguage", "Dot language (only integer numbers)", 0));
        eDot->setPlainText(QApplication::translate("fDotLanguage", "digraph G {\n"
"0 -> {2}\n"
"1 -> {0}\n"
"2 -> {1,2}\n"
"}", 0));
    } // retranslateUi

};

namespace Ui {
    class fDotLanguage: public Ui_fDotLanguage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDOTLANGUAGE_H
