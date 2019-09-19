/*
 * File:   fGraphDesign.h
 * Author: Michele
 *
 * Created on 14 luglio 2015, 18.59
 */

#ifndef _FGRAPHDESIGN_H
#define _FGRAPHDESIGN_H

#include "ui_fGraphDesign.h"
#include "QGVScene.h"
#include <set>

class fGraphDesign : public QMainWindow
{
    Q_OBJECT

public:
    fGraphDesign();

private slots:
    void nodeContextMenu(QGVNode* node);

    void bNodoClicked();
    void bArcoClicked();
    void bCasualeClicked();
    void bKPercorsi();
    void bPulisci();
    void bBenchmark();
    void bAbout();
    void bDot();
    void bCentra();
    void bSalva();
    void bCarica();

private:
    Ui::fGraphDesign ui;
    QGVScene *scena;
    unsigned long lastNodoIndex;
    std::set<int> NomiNodiUsati;
    struct grafo *G;

    void FromDot(const char * dot);
    void PulisciScena();
    void CentraImmagine(int pulisci);
    void EseguiBenchmark();
};

#endif /* _FGRAPHDESIGN_H */
