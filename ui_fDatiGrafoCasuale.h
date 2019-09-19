/********************************************************************************
** Form generated from reading UI file 'fDatiGrafoCasuale.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDATIGRAFOCASUALE_H
#define UI_FDATIGRAFOCASUALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_fDatiGrafoCasuale
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *eNodiDa;
    QSpinBox *eNodiA;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *eArchiDa;
    QSpinBox *eArchiA;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *eArchiPerNodoDa;
    QSpinBox *eArchiPerNodoA;

    void setupUi(QDialog *fDatiGrafoCasuale)
    {
        if (fDatiGrafoCasuale->objectName().isEmpty())
            fDatiGrafoCasuale->setObjectName(QStringLiteral("fDatiGrafoCasuale"));
        fDatiGrafoCasuale->resize(215, 274);
        QIcon icon;
        icon.addFile(QStringLiteral("images/molecule.png"), QSize(), QIcon::Normal, QIcon::Off);
        fDatiGrafoCasuale->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(fDatiGrafoCasuale);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 240, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(fDatiGrafoCasuale);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 191, 71));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 46, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 20, 46, 13));
        eNodiDa = new QSpinBox(groupBox);
        eNodiDa->setObjectName(QStringLiteral("eNodiDa"));
        eNodiDa->setGeometry(QRect(10, 40, 81, 22));
        eNodiDa->setMinimum(2);
        eNodiDa->setMaximum(9999);
        eNodiDa->setValue(20);
        eNodiA = new QSpinBox(groupBox);
        eNodiA->setObjectName(QStringLiteral("eNodiA"));
        eNodiA->setGeometry(QRect(100, 40, 81, 22));
        eNodiA->setMinimum(2);
        eNodiA->setMaximum(10000);
        eNodiA->setValue(100);
        groupBox_2 = new QGroupBox(fDatiGrafoCasuale);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 80, 191, 71));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 46, 13));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 20, 46, 13));
        eArchiDa = new QSpinBox(groupBox_2);
        eArchiDa->setObjectName(QStringLiteral("eArchiDa"));
        eArchiDa->setGeometry(QRect(10, 40, 81, 22));
        eArchiDa->setMinimum(0);
        eArchiDa->setMaximum(49999);
        eArchiDa->setValue(0);
        eArchiA = new QSpinBox(groupBox_2);
        eArchiA->setObjectName(QStringLiteral("eArchiA"));
        eArchiA->setGeometry(QRect(100, 40, 81, 22));
        eArchiA->setMinimum(1);
        eArchiA->setMaximum(50000);
        eArchiA->setValue(50);
        groupBox_3 = new QGroupBox(fDatiGrafoCasuale);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 160, 191, 71));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 46, 13));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 20, 46, 13));
        eArchiPerNodoDa = new QSpinBox(groupBox_3);
        eArchiPerNodoDa->setObjectName(QStringLiteral("eArchiPerNodoDa"));
        eArchiPerNodoDa->setGeometry(QRect(10, 40, 81, 22));
        eArchiPerNodoDa->setMinimum(0);
        eArchiPerNodoDa->setMaximum(199);
        eArchiPerNodoDa->setValue(0);
        eArchiPerNodoA = new QSpinBox(groupBox_3);
        eArchiPerNodoA->setObjectName(QStringLiteral("eArchiPerNodoA"));
        eArchiPerNodoA->setGeometry(QRect(100, 40, 81, 22));
        eArchiPerNodoA->setMinimum(1);
        eArchiPerNodoA->setMaximum(200);
        eArchiPerNodoA->setValue(15);

        retranslateUi(fDatiGrafoCasuale);
        QObject::connect(buttonBox, SIGNAL(accepted()), fDatiGrafoCasuale, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fDatiGrafoCasuale, SLOT(reject()));
        QObject::connect(eArchiA, SIGNAL(valueChanged(int)), fDatiGrafoCasuale, SLOT(ArchiCambiati()));
        QObject::connect(eArchiDa, SIGNAL(valueChanged(int)), fDatiGrafoCasuale, SLOT(ArchiCambiati()));
        QObject::connect(eNodiDa, SIGNAL(valueChanged(int)), fDatiGrafoCasuale, SLOT(ArchiCambiati()));
        QObject::connect(eNodiA, SIGNAL(valueChanged(int)), fDatiGrafoCasuale, SLOT(ArchiCambiati()));
        QObject::connect(eArchiPerNodoDa, SIGNAL(valueChanged(int)), fDatiGrafoCasuale, SLOT(ArchiCambiati()));

        QMetaObject::connectSlotsByName(fDatiGrafoCasuale);
    } // setupUi

    void retranslateUi(QDialog *fDatiGrafoCasuale)
    {
        fDatiGrafoCasuale->setWindowTitle(QApplication::translate("fDatiGrafoCasuale", "Random graph", 0));
        groupBox->setTitle(QApplication::translate("fDatiGrafoCasuale", "Vertices", 0));
        label->setText(QApplication::translate("fDatiGrafoCasuale", "From", 0));
        label_2->setText(QApplication::translate("fDatiGrafoCasuale", "to", 0));
        groupBox_2->setTitle(QApplication::translate("fDatiGrafoCasuale", "Edges", 0));
        label_3->setText(QApplication::translate("fDatiGrafoCasuale", "From", 0));
        label_4->setText(QApplication::translate("fDatiGrafoCasuale", "to", 0));
        groupBox_3->setTitle(QApplication::translate("fDatiGrafoCasuale", "Edges per vertex", 0));
        label_5->setText(QApplication::translate("fDatiGrafoCasuale", "From", 0));
        label_6->setText(QApplication::translate("fDatiGrafoCasuale", "to", 0));
    } // retranslateUi

};

namespace Ui {
    class fDatiGrafoCasuale: public Ui_fDatiGrafoCasuale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDATIGRAFOCASUALE_H
