/********************************************************************************
** Form generated from reading UI file 'fDettaglioNodo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDETTAGLIONODO_H
#define UI_FDETTAGLIONODO_H

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

class Ui_fDettaglioNodo
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *eValore;
    QLabel *label;

    void setupUi(QDialog *fDettaglioNodo)
    {
        if (fDettaglioNodo->objectName().isEmpty())
            fDettaglioNodo->setObjectName(QStringLiteral("fDettaglioNodo"));
        fDettaglioNodo->resize(175, 110);
        QIcon icon;
        icon.addFile(QStringLiteral("images/molecule.png"), QSize(), QIcon::Normal, QIcon::Off);
        fDettaglioNodo->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(fDettaglioNodo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 70, 151, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        eValore = new QSpinBox(fDettaglioNodo);
        eValore->setObjectName(QStringLiteral("eValore"));
        eValore->setGeometry(QRect(10, 30, 101, 22));
        eValore->setMaximum(9999999);
        label = new QLabel(fDettaglioNodo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 46, 13));

        retranslateUi(fDettaglioNodo);
        QObject::connect(buttonBox, SIGNAL(accepted()), fDettaglioNodo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fDettaglioNodo, SLOT(reject()));

        QMetaObject::connectSlotsByName(fDettaglioNodo);
    } // setupUi

    void retranslateUi(QDialog *fDettaglioNodo)
    {
        fDettaglioNodo->setWindowTitle(QApplication::translate("fDettaglioNodo", "Vertex", 0));
        label->setText(QApplication::translate("fDettaglioNodo", "Value", 0));
    } // retranslateUi

};

namespace Ui {
    class fDettaglioNodo: public Ui_fDettaglioNodo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDETTAGLIONODO_H
