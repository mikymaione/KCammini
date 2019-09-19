/********************************************************************************
** Form generated from reading UI file 'fArco.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FARCO_H
#define UI_FARCO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_fArco
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *eDa;
    QSpinBox *eA;

    void setupUi(QDialog *fArco)
    {
        if (fArco->objectName().isEmpty())
            fArco->setObjectName(QStringLiteral("fArco"));
        fArco->resize(173, 155);
        QIcon icon;
        icon.addFile(QStringLiteral("images/molecule.png"), QSize(), QIcon::Normal, QIcon::Off);
        fArco->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(fArco);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 120, 151, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(fArco);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 46, 13));
        label_2 = new QLabel(fArco);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 46, 13));
        eDa = new QSpinBox(fArco);
        eDa->setObjectName(QStringLiteral("eDa"));
        eDa->setGeometry(QRect(10, 30, 151, 22));
        eDa->setMaximum(9999999);
        eA = new QSpinBox(fArco);
        eA->setObjectName(QStringLiteral("eA"));
        eA->setGeometry(QRect(10, 80, 151, 22));
        eA->setMaximum(9999999);
        eA->setValue(1);

        retranslateUi(fArco);
        QObject::connect(buttonBox, SIGNAL(accepted()), fArco, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fArco, SLOT(reject()));

        QMetaObject::connectSlotsByName(fArco);
    } // setupUi

    void retranslateUi(QDialog *fArco)
    {
        fArco->setWindowTitle(QApplication::translate("fArco", "Edge", 0));
        label->setText(QApplication::translate("fArco", "From", 0));
        label_2->setText(QApplication::translate("fArco", "To", 0));
    } // retranslateUi

};

namespace Ui {
    class fArco: public Ui_fArco {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FARCO_H
