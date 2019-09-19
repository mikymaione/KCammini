#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../Headers/Heap.h"

struct heap * Heap_New(unsigned long lunghezza_)
{
    struct heap * foo = malloc(sizeof(struct heap)); //FREE
    foo->A = malloc(sizeof(unsigned long) * lunghezza_); //FREE
    foo->lunghezza = lunghezza_;
    foo->lunghezzaAlbero = 0;

    return foo;
}

struct heap * Heap_NewEx(unsigned long A[], unsigned long lunghezza_)
{
    if(A == NULL)
    {
        return Heap_New(lunghezza_);
    }
    else
    {
        struct heap * foo = malloc(sizeof(struct heap)); //FREE
        foo->lunghezza = lunghezza_;
        foo->lunghezzaAlbero = lunghezza_;
        foo->A = A;

        return foo;
    }
}

void Heap_Free(struct heap * c)
{
    if(c)
    {
        free(c);

        c->A = NULL;
        c = NULL;
    }
}

unsigned long Heap_Floor(double x)
{
    unsigned long truncate = (unsigned long) x;
    double remainder = x - truncate;

    if(remainder < 0 && x < 0)
        return truncate - 1;
    else
        return truncate;
}

unsigned long Heap_Parent(unsigned long i)
{
    return Heap_Floor(i / 2);
}

unsigned long Heap_Left(unsigned long i)
{
    return(2 * i);
}

unsigned long Heap_Right(unsigned long i)
{
    return((2 * i) + 1);
}

void Heap_Scambia(struct heap * H, unsigned long indice_partenza, unsigned long indice_destinazione)
{
    unsigned long temp = H->A[indice_partenza - 1];
    H->A[indice_partenza - 1] = H->A[indice_destinazione - 1];
    H->A[indice_destinazione - 1] = temp;
}

void Heap_MaxHeapify(struct heap * H, unsigned long i) //O(log n)
{
    unsigned long massimo = 0;
    unsigned long l = Heap_Left(i);
    unsigned long r = Heap_Right(i);

    if(l <= H->lunghezzaAlbero && H->A[l - 1] > H->A[i - 1])
        massimo = l;
    else
        massimo = i;

    if(r <= H->lunghezzaAlbero && H->A[r - 1] > H->A[massimo - 1])
        massimo = r;

    if(massimo != i)
    {
        Heap_Scambia(H, i, massimo);
        Heap_MaxHeapify(H, massimo);
    }
}

void Heap_BuildMaxHeap(struct heap * H) //O(n)
{
    unsigned long i;
    unsigned long l = Heap_Floor(H->lunghezza / 2);

    H->lunghezzaAlbero = H->lunghezza;

    for(i = l; i > 0; i--)
        Heap_MaxHeapify(H, i); //O(log n)
}

void Heap_Stampa_fino_a(struct heap * c, unsigned long max)
{
    unsigned long i;
    for(i = 1; i <= max; i++)
    {
        if(c->A[i - 1] < 10)
            printf("%lu", 0);

        printf("%lu", c->A[i - 1]);
        printf("|");
    }

    printf("\n");
}

void Heap_Stampa(struct heap * c)
{
    Heap_Stampa_fino_a(c, c->lunghezzaAlbero);
}

void Heap_StampaArray(struct heap * c)
{
    Heap_Stampa_fino_a(c, c->lunghezza);
}

void Heap_HeapSort(struct heap * H) //O(n log n)
{
    unsigned long i;
    unsigned long l = H->lunghezza;

    Heap_BuildMaxHeap(H); //O(n)
    printf("MaxHeap Builded\n");
    Heap_StampaArray(H);

    for(i = l; i > 0; i -= 2)
    {
        Heap_Scambia(H, 1, i);
        printf("struct heap * swap %lu\n", i);
        Heap_StampaArray(H);

        H->lunghezzaAlbero--;

        Heap_MaxHeapify(H, 1); //O(log n)
        printf("MaxHeapify %lu\n", i);
        Heap_StampaArray(H);
    }
}