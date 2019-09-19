/*
 * File:   fKPercorsi.h
 * Author: Michele
 *
 * Created on 27 luglio 2015, 15.26
 */

#ifndef _FKPERCORSI_H
#define	_FKPERCORSI_H

#include "ui_fKPercorsi.h"

class fKPercorsi : public QDialog {
    Q_OBJECT

public:    
    explicit fKPercorsi(const int NNodi);    
    Ui::fKPercorsi ui;
    
private:
    int MaxNodi;
    bool *Numeri;
    void SvuotaArray();
    
private slots:
    void bAddNewNode();    
    void bClearAll();
    
};

#endif	/* _FKPERCORSI_H */
