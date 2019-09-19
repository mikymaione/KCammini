/*
 * File:   Vector.h
 * Author: [MAIONE MIKY]
 *
 * Created on 18 luglio 2015, 11.56
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include <stdbool.h>

typedef void (*FunzioneStampa)(void *);

struct vector {
    void **A; //Elementi
    unsigned long lunghezza;
    unsigned long indice;
    size_t size_Of_Generic;
};

struct vector *Vector_New(size_t size_Of_Generic, unsigned long lunghezza_);
void Vector_Free(struct vector *v);

unsigned long Vector_Total(struct vector *v);
bool Vector_Contains(struct vector *v, void *k);

void Vector_Add(struct vector *v, void *k);
void Vector_Delete(struct vector *v, unsigned long index);
void Vector_Set(struct vector *v, unsigned long i, void *k);

void *Vector_Get(struct vector *v, unsigned long i);
void *Vector_Back(struct vector *v);

void Vector_Print(struct vector *v, const char *formato_stampa);

#endif	/* VECTOR_H */

