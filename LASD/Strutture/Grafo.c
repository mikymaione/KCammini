#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <sys/param.h>
#include "../Headers/Grafo.h"
#include "../Headers/Stack.h"
#include "../Headers/Vector.h"
#include "../Headers/Lista.h"
#include "../Headers/Queue.h"
#include "../Headers/Set.h"
#include "../Headers/PriorityQueue.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

//FILE *TheLog;

void Nodo_Reset(struct nodo *foo, unsigned int colore, long d)
{
    foo->f = -1;
    foo->d = d;
    foo->colore = colore;
    foo->p = NULL; //TO FREE

    //A*
    foo->cost_so_far = LONG_MIN;

    //Yen
    //foo->unreachable = false;
}

struct nodo *Nodo_New2(void *key, unsigned int index)
{
    struct nodo *foo = malloc(sizeof (struct nodo));

    Nodo_Reset(foo, COLORE_BIANCO, 0);
    foo->key = key;
    foo->Index = index;

    //fprintf(TheLog, "New %lu\n", index);
    //fflush(TheLog);

    return foo;
}

struct nodo *Nodo_New(void *key)
{
    return Nodo_New2(key, 0);
}

void Nodo_Free(struct nodo *G)
{
    if (G)
    {
        Nodo_Free(G->p);

        free(G);
        G->p = NULL;
        G = NULL;
    }
}

void Nodo_Print(struct nodo *G)
{
    if (G)
        printf("%lu", G->key);
}

struct nodo *ToNodo(void *e)
{
    struct nodo *n = e;

    return n;
}

struct grafo *Grafo_New2(size_t size_Of_Generic, unsigned long NumeroNodi, const char *formato_stampa)
{
    //TheLog = fopen("C:\\Users\\mikym\\Desktop\\Malvone\\GraphDesigner\\dist\\Release\\QTMinGW-Windows\\log.txt", "a");
    struct grafo *foo = malloc(sizeof (struct grafo)); //TO FREE

    foo->size_Of_Generic = size_Of_Generic;
    foo->formato_stampa = formato_stampa;
    foo->n_Nodi = NumeroNodi;
    foo->n_Archi = 0;
    foo->Adj = calloc(NumeroNodi, sizeof (struct lista)); //TO FREE ARRAY
    foo->V = calloc(NumeroNodi, sizeof (struct nodo)); //TO FREE ARRAY

    return foo;
}

struct grafo *Grafo_New(size_t size_Of_Generic, unsigned long NumeroNodi, void **vertici, const char *formato_stampa)
{
    unsigned long i;
    struct grafo *foo = Grafo_New2(size_Of_Generic, NumeroNodi, formato_stampa);

    for (i = 0; i < NumeroNodi; i++)
        Grafo_CreateAndSetNode(foo, vertici[i], i);

    return foo;
}

void Grafo_CreateAndSetNode(struct grafo *G, void *key, unsigned long index_)
{
    struct nodo *n = Nodo_New2(key, index_);

    G->V[index_] = n;
    G->Adj[index_] = Lista_New(n);
}

void Grafo_Add(struct grafo *G, unsigned long index_)
{
    unsigned long NuovaDimensione = G->n_Nodi + 1;

    G->Adj = realloc(G->Adj, NuovaDimensione * sizeof (struct lista));
    G->V = realloc(G->V, NuovaDimensione * sizeof (struct nodo));
    G->n_Nodi = NuovaDimensione;

    Grafo_CreateAndSetNode(G, index_, index_);
}

void Grafo_Free(struct grafo *G)
{
    if (G)
    {
        unsigned int i;

        for (i = 0; i < G->n_Nodi; i++)
            Lista_Free(G->Adj[i]);

        for (i = 0; i < G->n_Nodi; i++)
        {
            free(G->V[i]);
            G->V[i] = NULL;
        }

        free(G);

        G->Adj = NULL;
        G->V = NULL;
        G = NULL;
    }
}

struct grafo *Grafo_Random(unsigned long min_vertices, unsigned long max_vertices, unsigned long min_edges_for_vertex, unsigned long max_edges_for_vertex, unsigned long min_edges, unsigned long max_edges, double *elapsed_secs) //O(E)
{
    time_t start, end;
    unsigned long da, a, y, x;
    unsigned long n_edges, cur_edges, possible_max_edges, used_edges;
    unsigned long n_vertices, tentativi_a, min_edge_to_protect;

    time(&start);

    if (min_vertices < 2)
        min_vertices = 2;

    if (min_vertices > max_vertices)
        max_vertices = min_vertices + 1;

    n_vertices = random_number(min_vertices, max_vertices);

    if (max_edges_for_vertex > n_vertices)
        max_edges_for_vertex = n_vertices;

    if (min_edges_for_vertex > max_edges_for_vertex)
        min_edges_for_vertex = max_edges_for_vertex;

    possible_max_edges = n_vertices * max_edges_for_vertex;

    if (max_edges > possible_max_edges)
        max_edges = possible_max_edges;

    if (min_edges < max_edges)
        n_edges = random_number(min_edges, max_edges);
    else
        n_edges = max_edges;

    min_edge_to_protect = min_edges_for_vertex * n_vertices;
    used_edges = 0;

    char nodi_usati[n_vertices];
    char **matrice_usati = calloc(n_vertices, 1 + sizeof (char*));
    struct grafo *foo = Grafo_New2(sizeof (unsigned long), n_vertices, "%lu");

    for (y = 0; y < n_vertices; y++)
    {
        struct nodo *n = Nodo_New2(y, y);
        foo->V[y] = n;
        foo->Adj[y] = Lista_New(n);

        matrice_usati[y] = calloc(n_vertices, sizeof (char));
    }

    cur_edges = min_edges_for_vertex;
    for (da = 0; da < n_vertices; da++) //O(E)
    {
        for (x = 0; x < cur_edges; x++)
        {
            tentativi_a = 0;

            do
            {
                a = random_number(0, n_vertices - 1);
                tentativi_a += 1;

                if (matrice_usati[da][a] == 1 && tentativi_a > 30)
                    for (y = 0; y < n_vertices; y++)
                        if (matrice_usati[da][y] == 0)
                        {
                            a = y;
                            break;
                        }
            }
            while (matrice_usati[da][a] == 1);

            used_edges += 1;
            matrice_usati[da][a] = 1;
            Grafo_CollegaNodi(foo, da, a);

            if (used_edges > max_edges)
            {
                time(&end);
                *elapsed_secs = difftime(end, start);

                return foo;
            }
        }
    }

    max_edges_for_vertex -= min_edges_for_vertex;

    while (used_edges < max_edges)
    {
        tentativi_a = 0;

        do
        {
            da = random_number(0, n_vertices - 1);
            tentativi_a += 1;

            if (nodi_usati[da] == 1 && tentativi_a > 30)
            {
                for (y = 0; y < n_vertices; y++)
                    if (nodi_usati[y] == 0)
                    {
                        da = y;
                        break;
                    }

                break; //già usati tutti, quindi usa da
            }
        }
        while (nodi_usati[da] == 1);

        nodi_usati[da] = 1;
        cur_edges = random_number(0, max_edges_for_vertex);

        if (used_edges + cur_edges > max_edges)
            cur_edges = max_edges - used_edges;

        for (x = 0; x < cur_edges; x++)
        {
            tentativi_a = 0;

            do
            {
                a = random_number(0, n_vertices - 1);
                tentativi_a += 1;

                if (matrice_usati[da][a] == 1 && tentativi_a > 30)
                {
                    for (y = 0; y < n_vertices; y++)
                        if (matrice_usati[da][y] == 0)
                        {
                            a = y;
                            break;
                        }

                    break; //già usati tutti, quindi usa a
                }
            }
            while (matrice_usati[da][a] == 1);

            used_edges += 1;
            matrice_usati[da][a] = 1;
            Grafo_CollegaNodi(foo, da, a);

            if (used_edges > max_edges)
            {
                time(&end);
                *elapsed_secs = difftime(end, start);

                return foo;
            }
        }
    }

    time(&end);
    *elapsed_secs = difftime(end, start);

    return foo;
}

void Grafo_CollegaNodi_AR(struct grafo *G, unsigned long index_nodo_da, unsigned long index_nodo_a)
{
    Grafo_CollegaNodi_AR2(G, index_nodo_da, index_nodo_a, NULL);
}

void Grafo_CollegaNodi_AR2(struct grafo *G, unsigned long index_nodo_da, unsigned long index_nodo_a, void *proprieta)
{
    Lista_AggiungiSuccessivo2(G->Adj[index_nodo_da], G->V[index_nodo_a], proprieta);
    Lista_AggiungiSuccessivo2(G->Adj[index_nodo_a], G->V[index_nodo_da], proprieta);
    G->n_Archi += 1;
}

void Grafo_CollegaNodi2(struct grafo *G, unsigned long index_nodo_da, unsigned long index_nodo_a, void *proprieta)
{
    //fprintf(TheLog, "Collega %lu --> %lu\n", index_nodo_da, index_nodo_a);
    //fflush(TheLog);

    Lista_AggiungiSuccessivo2(G->Adj[index_nodo_da], G->V[index_nodo_a], proprieta);
    G->n_Archi += 1;
}

void Grafo_CollegaNodi(struct grafo *G, unsigned long index_nodo_da, unsigned long index_nodo_a)
{
    Grafo_CollegaNodi2(G, index_nodo_da, index_nodo_a, NULL);
}

void Grafo_CollegaNodi_ByArray(struct grafo *G, unsigned long n_nodi, unsigned long *indici)
{
    unsigned int i;
    for (i = 1; i < n_nodi; i++)
    {
        Lista_AggiungiSuccessivo(G->Adj[indici[0] - 1], G->V[indici[i] - 1]);
        G->n_Archi += 1;
    }
}

void Grafo_ResettaVertici(struct grafo *G, unsigned int colore, long d)
{
    unsigned int i;
    for (i = 0; i < G->n_Nodi; i++)
    {
        struct nodo *n = G->Adj[i]->key;

        Nodo_Reset(n, colore, d);
    }
}

void Grafo_BFS2(struct grafo *G, struct nodo *s) //O(NumVertici + NumArchi)
{
    unsigned int i;

    Grafo_ResettaVertici(G, COLORE_BIANCO, LONG_MAX);
    Nodo_Reset(s, COLORE_GRIGIO, 0);

    struct queue *Q = Queue_New(sizeof (struct nodo), G->n_Nodi); //TO FREE
    Queue_Enqueue(Q, s);

    while (!Queue_Vuota(Q))
    {
        struct nodo *u = Queue_Dequeue(Q);

        for (i = 0; i < G->n_Nodi; i++)
            if (G->Adj[i]->key == u)
            {
                struct lista *v = G->Adj[i]->next;

                while (v)
                {
                    if (ToNodo(v->key)->colore == COLORE_BIANCO)
                    {
                        ToNodo(v->key)->colore = COLORE_GRIGIO;
                        ToNodo(v->key)->d = u->d + 1;
                        ToNodo(v->key)->p = u;

                        Queue_Enqueue(Q, v->key);
                    }

                    v = v->next;
                }

                u->colore = COLORE_NERO;

                break;
            }
    }

    Queue_Free(Q, false);
    Q = NULL;
}

void Grafo_BFS(struct grafo *G, unsigned long indice_nodo) //O(NumVertici + NumArchi)
{
    Grafo_BFS2(G, G->Adj[indice_nodo]->key);
}

void Grafo_DFS_Visita(struct grafo *G, struct nodo *u, long *tempo)
{
    *tempo += 1;
    u->colore = COLORE_GRIGIO;
    u->d = *tempo;

    unsigned long i;
    for (i = 0; i < G->n_Nodi; i++)
        if (ToNodo(G->Adj[i]->key) == u)
        {
            struct lista *v = G->Adj[i]->next;

            while (v)
            {
                if (ToNodo(v->key)->colore == COLORE_BIANCO)
                {
                    ToNodo(v->key)->p = u;
                    Grafo_DFS_Visita(G, v->key, tempo);
                }

                v = v->next;
            }

            break;
        }

    *tempo += 1;
    u->f = *tempo;
    u->colore = COLORE_NERO;
}

void Grafo_DFS(struct grafo *G)
{
    unsigned long i;
    long tempo = 0;

    Grafo_ResettaVertici(G, COLORE_BIANCO, 0);

    for (i = 0; i < G->n_Nodi; i++)
        if (G->V[i]->colore == COLORE_BIANCO)
            Grafo_DFS_Visita(G, G->V[i], &tempo);
}

struct grafo *Grafo_Trasposto(struct grafo *G) //O(|V| + |E|)
{
    unsigned long i, x;
    struct grafo *Gt = Grafo_New2(G->size_Of_Generic, G->n_Nodi, G->formato_stampa);

    for (i = 0; i < G->n_Nodi; i++)
    {
        struct nodo *n = Nodo_New(G->V[i]->key);

        Gt->V[i] = n;
        Gt->Adj[i] = Lista_New(n);
    }

    for (i = 0; i < G->n_Nodi; i++)
    {
        struct lista *v = G->Adj[i]->next;

        while (v)
        {
            for (x = 0; x < Gt->n_Nodi; x++)
                if (ToNodo(Gt->Adj[x]->key)->key == ToNodo(v->key)->key)
                {
                    Lista_AggiungiSuccessivo(Gt->Adj[x], Gt->V[i]);
                    break;
                }

            v = v->next;
        }
    }

    return Gt;
}

void Grafo_PrintPath2(struct grafo *G, struct nodo *s, struct nodo *v)
{
    if (s->key == v->key)
    {
        printf(G->formato_stampa, s->key);
    }
    else if (v->p == NULL)
    {
        printf("Non ci sono cammini da ");
        printf(G->formato_stampa, s->key);
        printf(" a ");
        printf(G->formato_stampa, v->key);
    }
    else
    {
        Grafo_PrintPath2(G, s, v->p);
        printf(" → ");
        printf(G->formato_stampa, v->key);
    }
}

void Grafo_StampaCammino(struct grafo *G, unsigned long n_nodo_da, unsigned long n_nodo_a)
{
    printf("Cammini da ");
    printf(G->formato_stampa, ToNodo(G->Adj[n_nodo_da]->key)->key);
    printf(" a ");
    printf(G->formato_stampa, ToNodo(G->Adj[n_nodo_a]->key)->key);
    printf(": ");

    Grafo_PrintPath2(G, G->Adj[n_nodo_da]->key, G->Adj[n_nodo_a]->key);
}

void Grafo_StampaProprieta(struct grafo *G)
{
    printf("Grafo - Proprieta':\n");
    printf(" N. nodi: %lu\n", G->n_Nodi);
    printf(" N. archi: %lu\n", G->n_Archi);
}

void Grafo_StampaListaAdj(struct grafo *G)
{
    printf("Lista Adj:\n");

    unsigned int i;
    for (i = 0; i < G->n_Nodi; i++)
    {
        struct lista *el = G->Adj[i];

        while (el)
        {
            printf(G->formato_stampa, ToNodo(el->key)->key);
            el = el->next;

            if (el)
                printf(" → ");
        }

        printf("\n");
    }
}

void Grafo_StampaVertici2(struct grafo *G, bool prolisso)
{
    printf("Vertici:\n");

    unsigned long i;
    for (i = 0; i < G->n_Nodi; i++)
    {
        printf(" #%lu:", i + 1);
        printf(G->formato_stampa, G->V[i]->key);
        printf("\n");

        if (prolisso)
        {
            printf("  d: %ld\n", G->V[i]->d);
            printf("  f: %ld\n", G->V[i]->f);
            printf("  c: ");

            if (G->V[i]->colore == COLORE_BIANCO)
                printf("bianco");
            else if (G->V[i]->colore == COLORE_GRIGIO)
                printf("grigio");
            else
                printf("nero");

            printf("\n");
        }
    }
}

void Grafo_StampaVertici(struct grafo *G)
{
    Grafo_StampaVertici2(G, true);
}

void Grafo_Tarjan(struct grafo *G) //O(|V| + |E|) Algoritmo per trovare le componenti fortemente connesse
{
    unsigned long i;
    long indice = 0;
    struct stack *node_stack = Stack_New(sizeof (struct nodo), G->n_Nodi);

    for (i = 0; i < G->n_Nodi; i++)
        if (G->V[i]->f < 0) //f = -1
            Grafo_Tarjan_StrongConnect(G, i, &indice, node_stack);
}

void Grafo_Tarjan_StrongConnect(struct grafo *G, unsigned long i, long *indice, struct stack *node_stack)
{
    ToNodo(G->Adj[i]->key)->f = *indice;
    ToNodo(G->Adj[i]->key)->d = *indice;
    *indice += 1;

    Stack_Push(node_stack, G->Adj[i]->key);

    struct lista *w = G->Adj[i];
    while (w = w->next)
        if (ToNodo(w->key)->f < 0) //f = -1
        {
            unsigned long z;
            for (z = 0; z < G->n_Nodi; z++)
                if (G->V[z] == ToNodo(w->key))
                    break;

            Grafo_Tarjan_StrongConnect(G, z, indice, node_stack);
            ToNodo(G->Adj[i]->key)->d = min(ToNodo(G->Adj[i]->key)->d, ToNodo(w->key)->d);
        }
        else if (Stack_Contain(node_stack, w->key))
        {
            ToNodo(G->Adj[i]->key)->d = min(ToNodo(G->Adj[i]->key)->d, ToNodo(w->key)->f);
        }
}

void Grafo_Tarjan_Stampa(struct grafo *G) //O(|V| + |E|) Algoritmo per trovare le componenti fortemente connesse
{
    Grafo_Tarjan(G);

    long cur_group = 0;
    long max_group = -1;
    unsigned long i = 0;

    for (i = 0; i < G->n_Nodi; i++)
        if (max_group < G->V[i]->d)
            max_group = G->V[i]->d;

    i = 0;
    while (max_group >= cur_group)
    {
        if (cur_group == G->V[i]->d)
        {
            printf(G->formato_stampa, G->V[i]->key);
            printf(" |");
        }

        i++;
        if (i + 1 > G->n_Nodi)
        {
            i = 0;
            cur_group++;
            printf("\n");
        }
    }
}

bool Grafo_AStar(struct grafo *G, FunzionePeso FunzionePeso_, FunzioneEuristica FunzioneEuristica_, unsigned long n_nodo_da, unsigned long n_nodo_a) //O(E)
{
    struct priorityQueue *frontier = PriorityQueue_New(G->n_Nodi);
    struct nodo *endNodeN = G->Adj[n_nodo_a]->key;
    struct nodo *startNodeN = G->Adj[n_nodo_da]->key;

    startNodeN->cost_so_far = 0;
    PriorityQueue_Push(frontier, n_nodo_da, 0);

    while (!PriorityQueue_IsEmpty(frontier))
    {
        unsigned long currentNodeINDEX = PriorityQueue_Pop(frontier, NULL);
        struct lista *currentNode = G->Adj[currentNodeINDEX];
        struct nodo *currentNodeN = currentNode->key;

        if (currentNodeN == endNodeN)
            return true;

        struct lista *next_ = currentNode;

        while (next_ = next_->next)
        {
            struct nodo *nextN = next_->key;

            long new_cost = currentNodeN->cost_so_far + FunzionePeso_(next_->proprieta);

            if (nextN->cost_so_far == LONG_MIN || new_cost < nextN->cost_so_far)
            {
                nextN->p = currentNodeN;
                nextN->cost_so_far = new_cost;

                long priority = new_cost + FunzioneEuristica_(nextN->key, endNodeN->key);

                PriorityQueue_DecreaseKey2(frontier, nextN->Index, priority, true);
            }
        }
    }

    return false;
}

void Grafo_AStar_Print(struct grafo *G, FunzioneStampa FunzioneStampa_, FunzionePeso FunzionePeso_, FunzioneEuristica FunzioneEuristica_, unsigned long n_nodo_da, unsigned long n_nodo_a)
{
    bool r = Grafo_AStar(G, FunzionePeso_, FunzioneEuristica_, n_nodo_da, n_nodo_a);

    if (r)
    {
        struct nodo *current = G->V[n_nodo_a];

        FunzioneStampa_(current->key);
        printf(" ← ");

        while (current = current->p)
        {
            FunzioneStampa_(current->key);
            printf(" ← ");
        }
    }
    else
    {
        printf("Il percorso non esiste!\n");
    }
}

void Grafo_KPath2(struct grafo *G, struct lista **cammini, struct vector *visitati, struct nodo *inizio, struct nodo *fine, unsigned long *cur_k, unsigned long k, unsigned long *n_iterazioni, long long MaxRecursive)
{
    bool Presente, SonoInizio;
    struct lista *n;
    struct nodo *var_nodo;
    struct nodo *ultimo = Vector_Back(visitati);
    unsigned long i;

    *n_iterazioni += 1;
    if (*n_iterazioni > MaxRecursive)
        return;

    n = G->Adj[ultimo->Index];
    while (n = n->next)
    {
        Presente = Vector_Contains(visitati, n->key);
        SonoInizio = (Presente && inizio == fine && n->key == inizio);

        if (Presente && !SonoInizio)
            continue;

        if (n->key == fine)
        {
            Vector_Add(visitati, n->key);
            //Vector_Print2(visitati, Nodo_Print);

            for (i = 0; i <= visitati->indice; i++)
                if (visitati->A[i])
                {
                    var_nodo = visitati->A[i];

                    if (cammini[*cur_k])
                        Lista_AggiungiSuccessivo(cammini[*cur_k ], var_nodo->key);
                    else
                        cammini[*cur_k] = Lista_New(var_nodo->key);

                    //printf("\nLista: ");
                    //Lista_Print(cammini[*cur_k ], G->formato_stampa);
                }

            *cur_k += 1;
            if (*cur_k >= k)
                return;

            var_nodo = visitati->A[0];
            Vector_Delete(visitati, var_nodo->Index + visitati->indice);
            //Vector_Print2(visitati, Nodo_Print);
            break;
        }
    }

    n = G->Adj[ultimo->Index];
    while (n = n->next)
    {
        if (n->key == fine || Vector_Contains(visitati, n->key))
            continue;

        Vector_Add(visitati, n->key);
        //Vector_Print2(visitati, Nodo_Print);

        Grafo_KPath2(G, cammini, visitati, inizio, fine, cur_k, k, n_iterazioni, MaxRecursive);

        if (*cur_k >= k)
            return;

        var_nodo = visitati->A[0];
        Vector_Delete(visitati, var_nodo->Index + visitati->indice);
        //Vector_Print2(visitati, Nodo_Print);
    }
}

unsigned long Grafo_KPath3(struct grafo *G, struct lista **cammini, unsigned long id_da, unsigned long n_destinazioni, unsigned long *ids_a, unsigned long k, double *elapsed_secs, long long MaxRecursive) //Ω(V+E)
{
    unsigned long i = 0;
    unsigned long j = G->n_Nodi;

    Grafo_Add(G, j);

    for (i = 0; i < n_destinazioni; i++)
        Grafo_CollegaNodi(G, ids_a[i], j);

    return Grafo_KPath(G, cammini, id_da, j, k, elapsed_secs, MaxRecursive);
}

unsigned long Grafo_KPath(struct grafo *G, struct lista **cammini, unsigned long id_da, unsigned long id_a, unsigned long k, double *elapsed_secs, long long MaxRecursive) //Ω(V+E)
{
    time_t start, end;
    unsigned long cur_k = 0;
    unsigned long n_iterazioni = 0;
    struct vector *visitati = Vector_New(sizeof (struct nodo), G->n_Nodi);

    time(&start);

    Vector_Add(visitati, G->V[id_da]);
    Grafo_KPath2(G, cammini, visitati, G->V[id_da], G->V[id_a], &cur_k, k, &n_iterazioni, MaxRecursive);

    time(&end);
    *elapsed_secs = difftime(end, start);

    return cur_k;
}