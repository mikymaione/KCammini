/*
 * File:   fDatiGrafoCasuale.cpp
 * Author: Michele
 *
 * Created on 21 luglio 2015, 16.42
 */

#include "fDatiGrafoCasuale.h"

fDatiGrafoCasuale::fDatiGrafoCasuale()
{
    ui.setupUi(this);
}

int fDatiGrafoCasuale::ArchiCambiati()
{
    int n = ui.eNodiDa->value();

    if (ui.eNodiA->value() < n)
        ui.eNodiA->setValue(n);

    ui.eNodiA->setMinimum(n);
    int na = ui.eNodiA->value();

    if (ui.eArchiA->value() > na * na)
        ui.eArchiA->setValue(na * na);
    if (ui.eArchiA->value() < ui.eArchiDa->value())
        ui.eArchiA->setValue(ui.eArchiDa->value());

    ui.eArchiA->setMaximum(na * na);
    ui.eArchiDa->setMaximum(n * n);
    ui.eArchiA->setMinimum(ui.eArchiDa->value());

    ui.eArchiPerNodoDa->setMaximum(na);
    ui.eArchiPerNodoA->setMaximum(na);
    ui.eArchiPerNodoA->setMinimum(ui.eArchiPerNodoDa->value());
}