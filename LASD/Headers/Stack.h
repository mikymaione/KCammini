/*
 * File:   Stack.h
 * Author: [MAIONE MIKY]
 *
 * Created on 28 maggio 2015, 11.37
 */

#ifndef STACK_H
#define	STACK_H

#include <stddef.h>

struct stack
{
    void **A; //TO FREE ARRAY
    size_t size_Of_Generic;

    long indice, effettivamente_allocati;
    unsigned long lunghezza;
};

struct stack *Stack_New(size_t size_Of_Generic, unsigned long StackSize); // Inizializza lo Stack
void Stack_Free(struct stack *S);

int Stack_IsEmpty(struct stack *S); // Ritorna 1 se lo Stack e' vuoto, 0 altrimenti
int Stack_IsFull(struct stack *S); // Ritorna 1 se lo Stack e' pieno, 0 altrimenti

void Stack_Push(struct stack *S, void *n); // Inserisce il dato 'value' nello Stack, se non e' pieno
void *Stack_Pop(struct stack *S); // Estrae dallo Stack un elemento e lo ritorna
void *Stack_Top(struct stack *S); //Ritorna il primo elemento

unsigned int Stack_Contain(struct stack *S, void *search); // Ritorna 1 se lo Stack e' pieno, 0 altrimenti

#endif	/* STACK_H */

