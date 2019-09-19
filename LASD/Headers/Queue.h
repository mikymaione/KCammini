/*
 * File:   Queue.h
 * Author: [MAIONE MIKY]
 *
 * Created on 7 maggio 2015, 16.35
 */

#ifndef Queue_H
#define	Queue_H

#include <stdbool.h>

struct queue
{
    void **E; //Array of generic elements void *
    size_t size_Of_Generic;
    unsigned long lunghezza, head, tail;
};


struct queue *Queue_New(size_t size_Of_Generic, unsigned long lunghezza);
void Queue_Free(struct queue *c, bool LiberaPuntatori);
int Queue_Vuota(struct queue *c);
void Queue_Enqueue(struct queue *c, void *x);
void *Queue_Dequeue(struct queue *c);

void Queue_Stampa(struct queue *c, const char *formato);
void Queue_Stampa_ConInfo(struct queue *c, const char *formato);
void Queue_Stampa_Indice(struct queue *c, unsigned long indice, const char *formato);

#endif