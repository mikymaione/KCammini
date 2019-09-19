/*
 * File:   fDatiGrafoCasuale.h
 * Author: Michele
 *
 * Created on 21 luglio 2015, 16.42
 */

#ifndef _FDATIGRAFOCASUALE_H
#define	_FDATIGRAFOCASUALE_H

#include "ui_fDatiGrafoCasuale.h"

class fDatiGrafoCasuale : public QDialog {
    Q_OBJECT

public:
    fDatiGrafoCasuale();
    Ui::fDatiGrafoCasuale ui;
    
private slots:
    int ArchiCambiati();
    
};

#endif	/* _FDATIGRAFOCASUALE_H */