/*
 * File:   fKPercorsi.cpp
 * Author: Michele
 *
 * Created on 27 luglio 2015, 15.26
 */

#include "fKPercorsi.h"

fKPercorsi::fKPercorsi(const int NNodi)
{
    MaxNodi = NNodi;

    ui.setupUi(this);

    ui.eA->setMaximum(MaxNodi - 1);
    ui.eDa->setMaximum(MaxNodi - 1);

    Numeri = new bool[MaxNodi];
    SvuotaArray();
}

void fKPercorsi::SvuotaArray()
{
    for (int i = 0; i < MaxNodi; i++)
        Numeri[i] = false;

    ui.eA->setValue(0);
}

void fKPercorsi::bClearAll()
{
    ui.eLista->clear();
    ui.bAdd->setEnabled(true);
    SvuotaArray();
}

void fKPercorsi::bAddNewNode()
{
    bool CanContinue = false;
    int N = ui.eA->value();
    Numeri[N] = true;

    QString z = ui.eLista->toPlainText();
    z.append(QString::number(N));
    z.append("; ");

    ui.eLista->setPlainText(z);

    for (int i = 0; i < MaxNodi; i++)
        if (!Numeri[i])
        {
            CanContinue = true;
            ui.eA->setValue(i);
            break;
        }

    ui.bAdd->setEnabled(CanContinue);
}