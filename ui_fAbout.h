/********************************************************************************
** Form generated from reading UI file 'fAbout.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FABOUT_H
#define UI_FABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_fAbout
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_5;

    void setupUi(QDialog *fAbout)
    {
        if (fAbout->objectName().isEmpty())
            fAbout->setObjectName(QStringLiteral("fAbout"));
        fAbout->resize(349, 397);
        QIcon icon;
        icon.addFile(QStringLiteral("images/molecule.png"), QSize(), QIcon::Normal, QIcon::Off);
        fAbout->setWindowIcon(icon);
        label = new QLabel(fAbout);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 70, 34, 34));
        label->setPixmap(QPixmap(QString::fromUtf8("images/unina.png")));
        label_2 = new QLabel(fAbout);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 14, 34, 34));
        label_2->setPixmap(QPixmap(QString::fromUtf8("images/molecule.png")));
        label_3 = new QLabel(fAbout);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 10, 111, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_4 = new QLabel(fAbout);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 30, 271, 31));
        label_4->setWordWrap(true);
        groupBox = new QGroupBox(fAbout);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 120, 331, 271));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 20, 311, 241));
        plainTextEdit->setReadOnly(true);
        label_5 = new QLabel(fAbout);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 85, 281, 16));
        label_5->setWordWrap(true);

        retranslateUi(fAbout);

        QMetaObject::connectSlotsByName(fAbout);
    } // setupUi

    void retranslateUi(QDialog *fAbout)
    {
        fAbout->setWindowTitle(QApplication::translate("fAbout", "About KPaths", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("fAbout", "About KPaths", 0));
        label_4->setText(QApplication::translate("fAbout", "Search for K paths from a node to a group of nodes.\n"
"v. 20.16.0421", 0));
        groupBox->setTitle(QApplication::translate("fAbout", "GNU GPL", 0));
        plainTextEdit->setPlainText(QApplication::translate("fAbout", "This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.\n"
"\n"
"This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.\n"
"\n"
"You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.", 0));
        label_5->setText(QApplication::translate("fAbout", "Copyright \302\251 2016 UNINA. All rights reserved.", 0));
    } // retranslateUi

};

namespace Ui {
    class fAbout: public Ui_fAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FABOUT_H
