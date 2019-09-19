/********************************************************************************
** Form generated from reading UI file 'fKPercorsi.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FKPERCORSI_H
#define UI_FKPERCORSI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_fKPercorsi
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *eK;
    QLabel *label_3;
    QSpinBox *eDa;
    QSpinBox *eA;
    QPushButton *bAdd;
    QPushButton *bClear;
    QPlainTextEdit *eLista;

    void setupUi(QDialog *fKPercorsi)
    {
        if (fKPercorsi->objectName().isEmpty())
            fKPercorsi->setObjectName(QStringLiteral("fKPercorsi"));
        fKPercorsi->resize(165, 376);
        QIcon icon;
        icon.addFile(QStringLiteral("images/molecule.png"), QSize(), QIcon::Normal, QIcon::Off);
        fKPercorsi->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(fKPercorsi);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 340, 141, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(fKPercorsi);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 46, 13));
        label_2 = new QLabel(fKPercorsi);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 46, 13));
        eK = new QSpinBox(fKPercorsi);
        eK->setObjectName(QStringLiteral("eK"));
        eK->setGeometry(QRect(10, 310, 141, 22));
        eK->setMinimum(1);
        eK->setMaximum(99999);
        eK->setValue(50);
        label_3 = new QLabel(fKPercorsi);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 290, 141, 16));
        eDa = new QSpinBox(fKPercorsi);
        eDa->setObjectName(QStringLiteral("eDa"));
        eDa->setGeometry(QRect(10, 30, 81, 22));
        eDa->setMaximum(99999999);
        eA = new QSpinBox(fKPercorsi);
        eA->setObjectName(QStringLiteral("eA"));
        eA->setGeometry(QRect(10, 80, 81, 22));
        eA->setMaximum(99999999);
        bAdd = new QPushButton(fKPercorsi);
        bAdd->setObjectName(QStringLiteral("bAdd"));
        bAdd->setGeometry(QRect(97, 79, 25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral("images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        bAdd->setIcon(icon1);
        bClear = new QPushButton(fKPercorsi);
        bClear->setObjectName(QStringLiteral("bClear"));
        bClear->setGeometry(QRect(127, 79, 25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/broom.png"), QSize(), QIcon::Normal, QIcon::Off);
        bClear->setIcon(icon2);
        eLista = new QPlainTextEdit(fKPercorsi);
        eLista->setObjectName(QStringLiteral("eLista"));
        eLista->setGeometry(QRect(10, 110, 141, 181));
        eLista->setReadOnly(true);
        QWidget::setTabOrder(eDa, eA);
        QWidget::setTabOrder(eA, bAdd);
        QWidget::setTabOrder(bAdd, bClear);
        QWidget::setTabOrder(bClear, eLista);
        QWidget::setTabOrder(eLista, eK);

        retranslateUi(fKPercorsi);
        QObject::connect(buttonBox, SIGNAL(accepted()), fKPercorsi, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fKPercorsi, SLOT(reject()));
        QObject::connect(bAdd, SIGNAL(clicked()), fKPercorsi, SLOT(bAddNewNode()));
        QObject::connect(bClear, SIGNAL(clicked()), fKPercorsi, SLOT(bClearAll()));

        QMetaObject::connectSlotsByName(fKPercorsi);
    } // setupUi

    void retranslateUi(QDialog *fKPercorsi)
    {
        fKPercorsi->setWindowTitle(QApplication::translate("fKPercorsi", "K paths", 0));
        label->setText(QApplication::translate("fKPercorsi", "From", 0));
        label_2->setText(QApplication::translate("fKPercorsi", "To", 0));
        label_3->setText(QApplication::translate("fKPercorsi", "Max K paths", 0));
#ifndef QT_NO_TOOLTIP
        bAdd->setToolTip(QApplication::translate("fKPercorsi", "Add", 0));
#endif // QT_NO_TOOLTIP
        bAdd->setText(QString());
#ifndef QT_NO_TOOLTIP
        bClear->setToolTip(QApplication::translate("fKPercorsi", "Remove all vertices", 0));
#endif // QT_NO_TOOLTIP
        bClear->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fKPercorsi: public Ui_fKPercorsi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FKPERCORSI_H
