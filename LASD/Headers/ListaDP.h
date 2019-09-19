/*
 * File:   Lista.h
 * Author: [MAIONE MIKY]
 *
 * Created on 7 maggio 2015, 16.35
 */

#ifndef Lista_DP_H
#define	Lista_DP_H

struct lista_dp
{
    void *key;

    struct lista_dp *head;
    struct lista_dp *prev;
    struct lista_dp *next;
};

struct lista_dp *Lista_DP_New(void *key);
struct lista_dp *Lista_DP_NewLista();
void Lista_DP_Free(struct lista_dp *L);

void Lista_DP_Insert(struct lista_dp *L, struct lista_dp *x); //O(1)
void Lista_DP_Delete(struct lista_dp *L, struct lista_dp *x); //O(1) → Θ(n)
struct lista_dp *Lista_DP_Search(struct lista_dp *L, void *key); //→ Θ(n)
void Lista_DP_Stampa(struct lista_dp *L, const char *formato);

#endif	/* Lista_DP_H */