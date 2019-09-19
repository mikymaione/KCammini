#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Headers/Lista.h"

struct lista *Lista_New2(void *key, void *proprieta)
{
    struct lista *foo = malloc(sizeof (struct lista)); //TO FREE

    foo->next = NULL;
    foo->key = key;
    foo->proprieta = proprieta;

    return foo;
}

struct lista *Lista_New(void *key)
{
    return Lista_New2(key, NULL);
}

void Lista_AggiungiSuccessivo2(struct lista *L, void *key, void *proprieta)
{
    if (L)
        if (L->next == NULL)
            L->next = Lista_New2(key, proprieta);
        else
            Lista_AggiungiSuccessivo2(L->next, key, proprieta);
}

void Lista_AggiungiSuccessivo(struct lista *L, void *key)
{
    Lista_AggiungiSuccessivo2(L, key, NULL);
}

void Lista_Free(struct lista *L)
{
    if (L)
    {
        Lista_Free(L->next);

        free(L);
        L->next = NULL;
        L = NULL;
    }
}

void Lista_Print(struct lista *L, const char *formato_stampa)
{
    if (L)
    {
        printf(formato_stampa, L->key);
        printf(" ");

        Lista_Print(L->next, formato_stampa);
    }
}