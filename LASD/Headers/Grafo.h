/*
 *File:   Grafo.h
 *Author: [MAIONE MIKY]
 *
 *Created on 7 maggio 2015, 16.35
 */

#ifndef Grafo_H
#define Grafo_H

#define COLORE_BIANCO 0
#define COLORE_GRIGIO 1
#define COLORE_NERO 2

#include <stdbool.h>

typedef unsigned long (*FunzionePeso)(void *);
typedef int (*FunzioneEuristica)(void *, void *);
typedef void (*FunzioneStampa)(void *);

struct nodo {
    void *key;

    long d, f;
    unsigned int colore;

    //A*
    unsigned int Index;
    long cost_so_far;
    //A*

    struct nodo *p; //Puntatore al nodo precedente TO FREE
};

struct grafo {
    unsigned long n_Nodi, n_Archi;
    char *formato_stampa;
    size_t size_Of_Generic;
    struct nodo **V; //TO FREE ARRAY
    struct lista **Adj; //TO FREE ARRAY
};

struct nodo *Nodo_New(void *key);
struct nodo *Nodo_New2(void *key, unsigned int index);
void Nodo_Free(struct nodo *G);
struct nodo *ToNodo(void *e);

struct grafo *Grafo_New(size_t size_Of_Generic, unsigned long NumeroNodi, void **vertici, const char *formato_stampa);
struct grafo *Grafo_New2(size_t size_Of_Generic, unsigned long NumeroNodi, const char *formato_stampa);
void Grafo_Free(struct grafo *G);

struct grafo *Grafo_Random(unsigned long min_vertices, unsigned long max_vertices, unsigned long min_edges_for_vertex, unsigned long max_edges_for_vertex, unsigned long min_edges, unsigned long max_edges, double *elapsed_secs); //O(E)

void Grafo_CreateAndSetNode(struct grafo *G, void *key, unsigned long index_);

void Grafo_CollegaNodi(struct grafo *G, unsigned long index_nodo_da, unsigned long index_nodo_a);
void Grafo_CollegaNodi2(struct grafo *G, unsigned long index_nodo_da, unsigned long index_nodo_a, void *proprieta);
void Grafo_CollegaNodi_ByArray(struct grafo *G, unsigned long n_nodi, unsigned long *indici);
void Grafo_CollegaNodi_AR(struct grafo *G, unsigned long index_nodo_da, unsigned long index_nodo_a);
void Grafo_CollegaNodi_AR2(struct grafo *G, unsigned long index_nodo_da, unsigned long index_nodo_a, void *proprieta);

void Grafo_ResettaVertici(struct grafo *G, unsigned int colore, long d);

void Grafo_BFS(struct grafo *G, unsigned long indice_nodo); //O(NumVertici + NumArchi)
void Grafo_DFS(struct grafo *G);

struct grafo *Grafo_Trasposto(struct grafo *G); //O(|V| + |E|)

bool Grafo_AStar(struct grafo *G, FunzionePeso FunzionePeso_, FunzioneEuristica FunzioneEuristica_, unsigned long n_nodo_da, unsigned long n_nodo_a);
void Grafo_AStar_Print(struct grafo *G, FunzioneStampa FunzioneStampa_, FunzionePeso FunzionePeso_, FunzioneEuristica FunzioneEuristica_, unsigned long n_nodo_da, unsigned long n_nodo_a);

unsigned long Grafo_KPath(struct grafo *G, struct lista **cammini, unsigned long id_da, unsigned long id_a, unsigned long k, double *elapsed_secs, long long MaxRecursive); //Ω(V+E)
unsigned long Grafo_KPath3(struct grafo *G, struct lista **cammini, unsigned long id_da, unsigned long n_destinazioni, unsigned long *ids_a, unsigned long k, double *elapsed_secs, long long MaxRecursive); //Ω(V+E)

void Grafo_Tarjan(struct grafo *G); //O(|V| + |E|) Algoritmo per trovare le componenti fortemente connesse
void Grafo_Tarjan_Stampa(struct grafo *G); //O(|V| + |E|) Algoritmo per trovare le componenti fortemente connesse

void Grafo_StampaCammino(struct grafo *G, unsigned long n_nodo_da, unsigned long n_nodo_a);
void Grafo_StampaProprieta(struct grafo *G);

void Grafo_StampaListaAdj(struct grafo *G);
void Grafo_StampaVertici(struct grafo *G);
void Grafo_StampaVertici2(struct grafo *G, bool prolisso);

#endif /*Grafo_H */