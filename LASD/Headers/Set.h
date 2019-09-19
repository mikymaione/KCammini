/*
 * File:   Set.h
 * Author: [MAIONE MIKY]
 *
 * Created on 10 giugno 2015, 17.17
 */

#ifndef SET_H
#define	SET_H

#include <stdbool.h>

typedef void (*setIterator)(void *);

struct set
{
    void **keys;
    unsigned long lunghezzaTotale, lunghezzaAttuale;
    size_t size_Of_Generic;
};

struct set *Set_New(size_t size_Of_Generic, unsigned long lunghezzaTotale);
void Set_Free(struct set *S);

void Set_Add(struct set *S, void *key);
void Set_Remove(struct set *S, void *key);

bool Set_IsEmpty(struct set *S);
bool Set_Contains(struct set *S, void *key);

void Set_Print(struct set *S, setIterator iterator);

#endif	/* SET_H */