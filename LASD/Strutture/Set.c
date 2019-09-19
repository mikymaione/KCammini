#include <stddef.h>
#include "../Headers/Set.h"

struct set *Set_New(size_t size_Of_Generic, unsigned long lunghezzaTotale)
{
    struct set *foo = malloc(sizeof (struct set));
    foo->lunghezzaAttuale = 0;
    foo->lunghezzaTotale = lunghezzaTotale;
    foo->size_Of_Generic = size_Of_Generic;
    foo->keys = calloc(lunghezzaTotale, size_Of_Generic);

    return foo;
}

void Set_Free(struct set *S)
{
    if (S)
        free(S);
}

void Set_Add(struct set *S, void *key)
{
    unsigned long i;
    for (i = 0; i < S->lunghezzaTotale; i++)
        if (S->keys[i] == NULL)
        {
            S->keys[i] = key;
            S->lunghezzaAttuale += 1;

            break;
        }
}

void Set_Remove(struct set *S, void *key)
{
    unsigned long i;
    for (i = 0; i < S->lunghezzaTotale; i++)
        if (S->keys[i] == key)
        {
            S->keys[i] = NULL;
            S->lunghezzaAttuale -= 1;

            break;
        }
}

bool Set_Contains(struct set *S, void *key)
{
    bool r = false;
    unsigned long i;
    for (i = 0; i < S->lunghezzaTotale; i++)
        if (S->keys[i] == key)
        {
            r = true;
            break;
        }

    return r;
}

void Set_Print(struct set *S, setIterator iterator)
{
    unsigned long i;
    for (i = 0; i < S->lunghezzaTotale; i++)
        if (S->keys[i])
            iterator(S->keys[i]);
}

bool Set_IsEmpty(struct set *S)
{
    bool r = false;
    unsigned long i;
    for (i = 0; i < S->lunghezzaTotale; i++)
        if (S->keys[i] != NULL)
        {
            r = true;
            break;
        }

    return r;
}