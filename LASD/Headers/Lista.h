/*
 * File:   Lista.h
 * Author: [MAIONE MIKY]
 *
 * Created on 7 giugno 2015, 10.33
 */

#ifndef LISTA_H
#define	LISTA_H

struct lista {
    void *key; //Puntatore elemento TO FREE
    void *proprieta;
    struct lista *next; //TO FREE
};

struct lista *Lista_New(void *key);
struct lista *Lista_New2(void *key, void *proprieta);
void Lista_AggiungiSuccessivo(struct lista *L, void *key);
void Lista_AggiungiSuccessivo2(struct lista *L, void *key, void *proprieta);
void Lista_Free(struct lista *L);

#endif	/* LISTA_H */