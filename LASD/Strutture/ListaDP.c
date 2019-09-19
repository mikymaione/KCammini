#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../Headers/ListaDP.h"

struct lista_dp *Lista_DP_New(void *key)
{
    struct lista_dp *foo = malloc(sizeof(struct lista_dp));

    foo->head = NULL;
    foo->prev = NULL;
    foo->next = NULL;
    foo->key = key;

    return foo;
}

struct lista_dp *Lista_DP_NewLista()
{
    return Lista_DP_New(0);
}

void Lista_DP_Free(struct lista_dp *L)
{
    if(L)
    {
        if(L->head == NULL) //figlio
            Lista_DP_Free(L->next);
        else
            Lista_DP_Free(L->head);

        free(L);
        L = NULL;
    }
}

void Lista_DP_Insert(struct lista_dp *L, struct lista_dp *x) //O(1)
{
    x->next = L->head;

    if(L->head)
        ((struct lista_dp *) L->head)->prev = x;

    L->head = x;
    x->prev = NULL;
}

void Lista_DP_Delete(struct lista_dp *L, struct lista_dp *x) //O(1) → Θ(n)
{
    if(x->prev)
        ((struct lista_dp *) x->prev)->next = x->next;
    else
        L->head = x->next;

    if(x->next)
        ((struct lista_dp *) x->next)->prev = x->prev;
}

struct lista_dp *Lista_DP_Search(struct lista_dp *L, void *key) //→ Θ(n)
{
    struct lista_dp *x = L->head;

    while(x && x->key != key)
        x = x->next;

    return x;
}

void Lista_DP_Stampa(struct lista_dp *L, const char *formato)
{
    if(L->head == NULL)
    {
        printf(formato, L->key);
        printf("|");

        if(L->next == NULL)
            printf("\n");
        else
            Lista_DP_Stampa(L->next, formato);
    }
    else
    {
        Lista_DP_Stampa(L->head, formato);
    }
}