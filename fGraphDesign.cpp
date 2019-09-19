/*
 * File:   fGraphDesign.cpp
 * Author: Michele
 *
 * Created on 14 luglio 2015, 18.59
 */

#include "fGraphDesign.h"
#include "fDettaglioNodo.h"
#include "fDatiGrafoCasuale.h"
#include "fPercorso.h"
#include "fArco.h"
#include "fAbout.h"
#include "fDotLanguage.h"
#include "fKPercorsi.h"
#include "QGVNode.h"
#include "QGVEdge.h"
#include "QGVSubGraph.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QMenu"
#include "QTextStream"
#include "QFile"

extern "C"
{
#include "LASD/Headers/Grafo.h"
#include "LASD/Headers/Lista.h"
}

fGraphDesign::fGraphDesign()
{
    ui.setupUi(this);
    PulisciScena();
}

void fGraphDesign::CentraImmagine(int pulisci)
{
    ui.graphicsView->fitInView(scena->sceneRect(), Qt::KeepAspectRatio);

    if (pulisci < 1)
        ui.statusBar->clearMessage();
}

void fGraphDesign::EseguiBenchmark() { }

void fGraphDesign::PulisciScena()
{
    G = NULL;
    lastNodoIndex = 0;
    NomiNodiUsati.clear();

    scena = new QGVScene("LASD", this);
    scena->setNodeAttribute("style", "filled");
    scena->setNodeAttribute("fillcolor", "white");

    ui.graphicsView->setScene(scena);
    ui.statusBar->clearMessage();

    //connect(scena, SIGNAL(nodeContextMenu(QGVNode*)), SLOT(nodeContextMenu(QGVNode*)));
}

void fGraphDesign::bCentra()
{
    CentraImmagine(0);
}

void fGraphDesign::FromDot(const char * dot)
{
    PulisciScena();
    ui.statusBar->showMessage("Generating ...");

    scena->loadLayout2(dot);

    QList<QGVNode*> nodi = scena->getNodes();
    QList<QGVEdge*> archi = scena->getEdges();

    if (nodi.count() > 0)
    {
        long a, da;
        long difference = nodi[0]->label().toLong();
        long L;

        G = Grafo_New2(sizeof (long), nodi.count(), "%lu");

        for (int i = 0; i < nodi.count(); i++)
            if (nodi[i]->label().toLong() < difference)
                difference = nodi[i]->label().toLong();

        for (int i = 0; i < nodi.count(); i++)
        {
            L = nodi[i]->label().toLong();
            Grafo_CreateAndSetNode(G, (void*) L, L - difference);
        }

        if (archi.count() > 0)
            for (unsigned long i = 0; i < archi.count(); i++)
            {
                da = atoi(archi[i]->value_head());
                a = atoi(archi[i]->value_tail());

                Grafo_CollegaNodi(G, da, a);
            }
    }

    CentraImmagine(0);

    QString msg;
    msg += "Created a graph with ";
    msg += QString::number(nodi.count());
    msg += " nodes and ";
    msg += QString::number(archi.count());
    msg += " edges";
    ui.statusBar->showMessage(msg);
}

void fGraphDesign::bDot()
{
    fDotLanguage f;
    f.setWindowFlags(f.windowFlags() & ~Qt::WindowContextHelpButtonHint);

    if (f.exec() == QDialog::Accepted)
        FromDot(f.ui.eDot->toPlainText().toLocal8Bit().constData());
}

void fGraphDesign::bCarica()
{
    try
    {
        QString dest = QFileDialog::getOpenFileName(this, "Load a graph", "", tr("dot files (*.dot)"));

        if (dest.isNull() == false && dest.isEmpty() == false)
        {
            ui.statusBar->showMessage("Loading ...");
            QFile file(dest);

            if (file.open(QIODevice::ReadOnly))
            {
                QString line;
                QTextStream in(&file);

                while (!in.atEnd())
                    line += in.readLine();

                file.close();

                line = line.replace("%", "");
                FromDot(line.toLocal8Bit().constData());
            }
        }
    }
    catch (...)
    {
        ui.statusBar->showMessage("An error has occurred!");
    }
}

void fGraphDesign::bSalva()
{
    try
    {
        QString dest = QFileDialog::getSaveFileName(this, "Save the graph", "", tr("dot files (*.dot)"));

        if (dest.isNull() == false && dest.isEmpty() == false)
        {
            int r = scena->saveLayout2(dest.toLocal8Bit().constData());
            ui.statusBar->showMessage((r == 0) ? "Saved!" : "An error has occurred: " + QString::number(r) + " while saving to " + dest.toLocal8Bit().constData());
        }
    }
    catch (...)
    {
        ui.statusBar->showMessage("An error has occurred!");
    }
}

void fGraphDesign::bPulisci()
{
    PulisciScena();
}

void fGraphDesign::bAbout()
{
    fAbout f;
    f.setWindowFlags(f.windowFlags() & ~Qt::WindowContextHelpButtonHint);
    f.exec();
}

void fGraphDesign::bBenchmark()
{
    EseguiBenchmark();
}

void fGraphDesign::bCasualeClicked()
{
    fDatiGrafoCasuale f;
    f.setWindowFlags(f.windowFlags() & ~Qt::WindowContextHelpButtonHint);

    if (f.exec() == QDialog::Accepted)
    {
        struct lista *l;
        struct nodo *nl;
        double elapsed_secs = 0;

        int nda = f.ui.eNodiDa->value();
        int na = f.ui.eNodiA->value();
        int ada = f.ui.eArchiDa->value();
        int aa = f.ui.eArchiA->value();
        int apnda = f.ui.eArchiPerNodoDa->value();
        int apna = f.ui.eArchiPerNodoA->value();

        PulisciScena();
        ui.statusBar->showMessage("Generating ...");

        G = Grafo_Random(nda, na, apnda, apna, ada, aa, &elapsed_secs);

        QString msg;
        msg += "Graph created ";
        msg += " in ";
        msg += QString::number(elapsed_secs);
        msg += "s. Transposition in progress...";
        ui.statusBar->showMessage(msg);

        QGVNode * n[G->n_Nodi];

        for (unsigned long i = 0; i < G->n_Nodi; i++)
            n[i] = scena->addNode(QString::number(i));

        for (unsigned long i = 0; i < G->n_Nodi; i++)
        {
            l = G->Adj[i];
            while (l = l->next)
            {
                nl = (struct nodo *) l->key;
                scena->addEdge(n[i], n[nl->Index]);
            }
        }

        msg += " Completed! Rendering...";
        ui.statusBar->showMessage(msg);

        scena->applyLayout();
        CentraImmagine(1);

        msg += " Completed!";
        ui.statusBar->showMessage(msg);
    }
}

void fGraphDesign::bNodoClicked()
{
    bool is_in = true;
    int valore_scelto = -1;

    while (is_in)
    {
        fDettaglioNodo f;
        f.setWindowFlags(f.windowFlags() & ~Qt::WindowContextHelpButtonHint);
        f.ui.eValore->setValue(lastNodoIndex);

        if (f.exec() == QDialog::Accepted)
        {
            valore_scelto = f.ui.eValore->value();
            is_in = NomiNodiUsati.find(valore_scelto) != NomiNodiUsati.end();

            if (is_in)
                QMessageBox::information(this, tr("Error"), tr("The node already exists"));
        }
    }

    if (!is_in && valore_scelto > -1)
    {
        lastNodoIndex += 1;
        NomiNodiUsati.insert(valore_scelto);

        scena->addNode(QString::number(valore_scelto));
        scena->applyLayout();
        CentraImmagine(0);
    }
}

void fGraphDesign::bArcoClicked()
{
    fArco f;
    f.setWindowFlags(f.windowFlags() & ~Qt::WindowContextHelpButtonHint);

    if (f.exec() == QDialog::Accepted)
    {
        QList<QGVNode*> n = scena->getNodes();

        scena->addEdge(n.at(f.ui.eDa->value()), n.at(f.ui.eA->value()));
        scena->applyLayout();
        CentraImmagine(0);
    }
}

void fGraphDesign::bKPercorsi()
{
    if (G && G->n_Nodi > 0 && G->n_Archi > 0)
    {
        fKPercorsi f(G->n_Nodi);
        f.setWindowFlags(f.windowFlags() & ~Qt::WindowContextHelpButtonHint);

        if (f.exec() == QDialog::Accepted)
        {
            double elapsed_secs = 0;
            unsigned long z = 0;
            unsigned long k = f.ui.eK->value();
            unsigned long da = f.ui.eDa->value();
            struct lista **cammini = (struct lista **) calloc(k, sizeof (struct lista));
            QString destinazioni_S = f.ui.eLista->toPlainText();
            destinazioni_S = destinazioni_S.replace("; ", ";");
            QStringList destinazioni_L = destinazioni_S.split(";", QString::SkipEmptyParts);
            int n_destinazioni = destinazioni_L.length();

            if (n_destinazioni > 0)
            {
                unsigned long *ids_a = (unsigned long *) malloc(sizeof (unsigned long) * n_destinazioni);

                QList<QGVNode *> Nodi = scena->getNodes();

                for (int n = 0; n < Nodi.length(); n++)
                    if (Nodi.at(n)->label() == QString::number(da))
                    {
                        Nodi.at(n)->setAttribute("color", "blue");
                        Nodi.at(n)->updateLayout();
                    }
                    else
                    {
                        Nodi.at(n)->setAttribute("color", "black");
                        Nodi.at(n)->updateLayout();
                    }

                for (int i = 0; i < n_destinazioni; i++)
                {
                    QString d = destinazioni_L.at(i);
                    int di = d.toInt();
                    ids_a[i] = di;

                    for (int n = 0; n < Nodi.length(); n++)
                        if (Nodi.at(n)->label() == QString::number(di))
                        {
                            Nodi.at(n)->setAttribute("color", "brown");
                            Nodi.at(n)->updateLayout();
                        }
                }

                ui.statusBar->showMessage("Searching ...");

                unsigned long cur_k = Grafo_KPath3(G, cammini, da, n_destinazioni, ids_a, k, &elapsed_secs, LLONG_MAX);

                QString msg;
                msg += "Founded ";
                msg += QString::number(cur_k);
                msg += "/";
                msg += QString::number(k);
                msg += " paths from [";
                msg += QString::number(da);
                msg += "] to [";
                msg += destinazioni_L.join(", ");
                msg += "] in ";
                msg += QString::number(elapsed_secs);
                msg += "s. Creating list...";
                ui.statusBar->showMessage(msg);

                QStringList percorsi_string;
                QString c;
                struct lista *l;

                for (z = 0; z < cur_k; z++)
                {
                    c.clear();
                    l = cammini[z];

                    c += QString::number(z + 1);
                    c += "#: ";

                    while (l && l->next)
                    {
                        c += QString::number((long) l->key);
                        l = l->next;

                        if (l && l->next)
                            c += " → ";
                    }

                    percorsi_string.append(c);
                }

                msg += " Completed!. Form creation in progress...";
                ui.statusBar->showMessage(msg);

                fPercorso p;
                p.ui.eLista->addItems(percorsi_string);

                msg += " Completed!";
                ui.statusBar->showMessage(msg);

                p.setWindowFlags(Qt::Window);
                p.exec();
            }
            else
                QMessageBox::information(this, tr("Error"), tr("There are not enough destination!"));
        }
    }
    else
        QMessageBox::information(this, tr("Error"), tr("There are not enough edges!"));
}

void fGraphDesign::nodeContextMenu(QGVNode *node)
{
    QMenu menu(node->label());

    menu.addSeparator();
    menu.addAction(tr("Information"));
    menu.addAction(tr("Delete"));

    QAction *action = menu.exec(QCursor::pos());
    if (action == 0)
        return;
}
