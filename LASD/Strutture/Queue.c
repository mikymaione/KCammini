#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../Headers/Queue.h"

struct queue *Queue_New(size_t size_Of_Generic, unsigned long lunghezza)
{
    struct queue *foo = malloc(sizeof(struct queue)); //TO FREE

    foo->head = 1;
    foo->tail = 1;
    foo->lunghezza = lunghezza;
    foo->size_Of_Generic = size_Of_Generic;
    foo->E = calloc(lunghezza, size_Of_Generic); //TO FREE

    return foo;
}

void Queue_Free(struct queue *c, bool LiberaPuntatori)
{
    if(c)
    {
        if(LiberaPuntatori)
        {
            unsigned long i;
            for(i = 0; i < c->lunghezza; i++)
            {
                free(c->E[i]);
                c->E[i] = NULL;
            }
        }

        free(c->E);
        free(c);
        c->E = NULL;
        c = NULL;
    }
}

int Queue_Vuota(struct queue *c)
{
    return(c->head == c->tail);
}

void Queue_Enqueue(struct queue *c, void *x)
{
    c->E[c->tail - 1] = x;

    if(c->tail == c->lunghezza)
        c->tail = 1;
    else
        c->tail += 1;
}

void *Queue_Dequeue(struct queue *c)
{
    struct nodo *x = c->E[c->head - 1];

    if(c->head == c->lunghezza)
        c->head = 1;
    else
        c->head += 1;

    return x;
}

void Queue_Stampa_Indice(struct queue *c, unsigned long indice, const char *formato)
{
    printf(formato, c->E[indice - 1]);
    printf("|");
}

void Queue_Stampa(struct queue *c, const char *formato)
{
    unsigned long i;

    if(c->head == c->tail)
    {
        for(i = 1; i < c->lunghezza; i++)
            Queue_Stampa_Indice(c, i, formato);
    }
    else if(c->head < c->tail)
    {
        for(i = c->head; i < c->tail; i++)
            Queue_Stampa_Indice(c, i, formato);
    }
    else
    {
        for(i = 1; i < c->tail; i++)
            Queue_Stampa_Indice(c, i, formato);

        for(i = c->head; i < c->lunghezza; i++)
            Queue_Stampa_Indice(c, i, formato);
    }

    printf("\n");
}

void Queue_Stampa_ConInfo(struct queue *c, const char *formato)
{
    printf("Vuota = %i\n", bool_ul_to_str(Queue_Vuota(c)));

    Queue_Stampa(c, formato);
}