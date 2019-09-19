/*
 * File:   AlberoBinario.h
 * Author: [MAIONE MIKY]
 *
 * Created on 7 maggio 2015, 16.35
 */

#ifndef AlberoBinario_H
#define	AlberoBinario_H

struct alberoBinario
{
    void *key;

    unsigned long numero_nodi;
    unsigned long h;

    char *formato_stampa;

    struct alberoBinario * root;
    struct alberoBinario * left;
    struct alberoBinario * right;
    struct alberoBinario * dad;
};

struct alberoBinario *AlberoBinario_New(const char *formato_stampa, void *key_); //Crea un albero binario
struct alberoBinario *AlberoBinario_New2(const char *formato_stampa, void *key, struct alberoBinario *daddy); //Crea un albero binario
void AlberoBinario_Free(struct alberoBinario *c); //Dealloca un albero binario
struct alberoBinario *AlberoBinario_Clona(struct alberoBinario *original);

void AlberoBinario_Insert(struct alberoBinario *t, struct alberoBinario *z); //O(h) Inserisce nell'albero binario t l'albero z

struct alberoBinario *AlberoBinario_Tree_Minimum(struct alberoBinario *x); //O(h) Minimo
struct alberoBinario *AlberoBinario_Tree_Maximum(struct alberoBinario *x); //O(h) Massimo
void *AlberoBinario_Tree_Maximum2(struct alberoBinario *x); //O(h) Massimo
void *AlberoBinario_Tree_Minimum2(struct alberoBinario *x); //O(h) Minimo
struct alberoBinario *AlberoBinario_Tree_Successor(struct alberoBinario *x); //O(h) Successore
struct alberoBinario *AlberoBinario_Tree_Predecessor(struct alberoBinario *x); //O(h) Predecessore
void *AlberoBinario_Tree_Successor2(struct alberoBinario *x); //O(h) Successore
void *AlberoBinario_Tree_Predecessor2(struct alberoBinario *x); //O(h) Predecessore

void AlberoBinario_Tree_Search3(struct alberoBinario *x, struct alberoBinario *trovati[], unsigned int *n_trovati, void *from, void *to); //Θ(n) Ricerca un valore compreso tra from & to
struct alberoBinario **AlberoBinario_Tree_Search2(struct alberoBinario *x, unsigned int *n_trovati, void *from, void *to); //Θ(n) Ricerca un valore compreso tra from & to
struct alberoBinario *AlberoBinario_Tree_Search(struct alberoBinario *x, void *k); //O(h) Ricerca il valore esatto k
unsigned long *AlberoBinario_Tree_Search4(struct alberoBinario *x, unsigned int *n_trovati, void *from, void *to); //Θ(n) Ricerca un valore compreso tra from & to

void AlberoBinario_Transplant(struct alberoBinario *t, struct alberoBinario *u, struct alberoBinario *v); //O(1) Nell'albero t traspianta l'albero v nell'albero u

int AlberoBinario_Equals(struct alberoBinario *a, struct alberoBinario *b);

void AlberoBinario_Tree_Delete(struct alberoBinario *t, struct alberoBinario *z); //O(h) Elimina dall'albero t l'albero z
void AlberoBinario_Tree_Delete3(struct alberoBinario *t, void *val); //O(2h) Elimina dall'albero t il valore val
int AlberoBinario_Tree_Delete_20120126(struct alberoBinario *t, struct alberoBinario *p, int x, int i); //Θ(n) + [O(h)] elimina da t il nodo che contiene la chiave k che si trova in posizione x nell'ordinamento totale delle chiavi contenute in T, rispetto alla relazione d'ordine ≤

void AlberoBinario_Inorder_Tree_Walk2(struct alberoBinario *x, unsigned long indent); //Θ(n) Stampa l'albero x
void AlberoBinario_Inorder_Tree_Walk(struct alberoBinario *x); //Θ(n) Stampa l'albero x

#endif	/* AlberoBinario_H */