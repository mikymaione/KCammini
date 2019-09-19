#include <stddef.h>
#include "../Headers/Vector.h"

struct vector *Vector_New(size_t size_Of_Generic, unsigned long lunghezza_)
{
    struct vector *v = malloc(sizeof (struct vector));

    v->A = calloc(lunghezza_, size_Of_Generic);
    v->lunghezza = lunghezza_;
    v->indice = -1;
    v->size_Of_Generic = size_Of_Generic;

    return v;
}

unsigned long Vector_Total(struct vector *v)
{
    return v->indice + 1;
}

void Vector_Add(struct vector *v, void *k)
{
    v->A[v->indice += 1] = k;
}

void Vector_Set(struct vector *v, unsigned long i, void *k)
{
    v->A[i] = k;
}

void *Vector_Get(struct vector *v, unsigned long i)
{
    return v->A[i];
}

void *Vector_Back(struct vector *v)
{
    return Vector_Get(v, v->indice);
}

bool Vector_Contains(struct vector *v, void *k)
{
    unsigned long i;
    bool r = false;

    for (i = 0; i <= v->indice; i++)
        if (v->A[i] == k)
        {
            r = true;
            break;
        }

    return r;
}

void Vector_Delete(struct vector *v, unsigned long index)
{
    unsigned long i;
    for (i = index; i <= v->indice - 1; i++)
    {
        v->A[i] = v->A[i + 1];
        v->A[i + 1] = NULL;
    }

    v->indice -= 1;
}

void Vector_Free(struct vector *v)
{
    free(v->A);
}

void Vector_Print2(struct vector *v, FunzioneStampa FunzioneStampa_)
{
    unsigned long i;

    printf("\nVettore: ");
    for (i = 0; i <= v->indice; i++)
        if (v->A[i])
        {
            FunzioneStampa_(v->A[i]);
            printf(" ");
        }

    printf("\n");
}

void Vector_Print(struct vector *v, const char *formato_stampa)
{
    unsigned long i;

    printf("\nVettore: ");
    for (i = 0; i <= v->indice; i++)
    {
        printf(formato_stampa, v->A[i]);
        printf(" ");
    }

    printf("\n");
}