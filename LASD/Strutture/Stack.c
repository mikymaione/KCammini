#include "sys/param.h"
#include "../Headers/Stack.h"

struct stack *Stack_New(size_t size_Of_Generic, unsigned long StackSize) // Inizializza lo Stack
{
    struct stack *S = malloc(sizeof(struct stack));
    S->A = calloc(StackSize, size_Of_Generic);
    S->size_Of_Generic = size_Of_Generic;
    S->lunghezza = StackSize;
    S->indice = -1;
    S->effettivamente_allocati = -1;

    return S;
}

void Stack_Free(struct stack *S)
{
    if(S)
        free(S);
}

int Stack_IsEmpty(struct stack *S) // Ritorna 1 se lo Stack e' vuoto, 0 altrimenti
{
    return S->indice == -1;
}

int Stack_IsFull(struct stack *S) // Ritorna 1 se lo Stack e' pieno, 0 altrimenti
{
    return S->indice == S->lunghezza - 1;
}

unsigned int Stack_Contain(struct stack *S, void *search) // Ritorna 1 se lo Stack e' pieno, 0 altrimenti
{
    unsigned int r = 0;
    unsigned long i;

    for(i = 0; i <= S->indice; i++)
        if(S->A[i] == search)
        {
            r = 1;
            break;
        }

    return r;
}

void Stack_Push(struct stack *S, void *n) // Inserisce il dato 'value' nello Stack, se non e' pieno
{
    if(!Stack_IsFull(S))
    {
        S->effettivamente_allocati += 1;
        S->indice += 1;
        S->A[S->indice] = n;
    }
}

void *Stack_Pop(struct stack *S) // Estrae dallo Stack un elemento e lo ritorna
{
    if(Stack_IsEmpty(S))
    {
        return NULL;
    }
    else
    {
        S->indice -= 1;
        return S->A[S->indice + 1];
    }
}

void *Stack_Top(struct stack *S) //Ritorna il primo elemento
{
    if(Stack_IsEmpty(S))
        return NULL;
    else
        return S->A[0];
}

void Stack_Printf(struct stack *S, const char *formato)
{
    unsigned long i;

    if(S->indice > -1)
        for(i = 0; i <= S->indice; i++)
        {
            printf(formato, S->A[i]);
            printf(", ");
        }
}