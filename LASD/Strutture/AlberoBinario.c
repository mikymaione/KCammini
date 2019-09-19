#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../Headers/AlberoBinario.h"

struct alberoBinario *AlberoBinario_New(const char *formato_stampa, void *key_) //Crea un albero binario
{
    struct alberoBinario *foo = malloc(sizeof(struct alberoBinario)); //TO FREE

    foo->key = key_;
    foo->numero_nodi = 1;
    foo->h = 1;
    foo->formato_stampa = formato_stampa;
    foo->root = NULL; //TO FREE
    foo->left = NULL; //TO FREE
    foo->right = NULL; //TO FREE
    foo->dad = NULL; //TO FREE

    return foo;
}

struct alberoBinario *AlberoBinario_New2(const char *formato_stampa, void *key, struct alberoBinario *daddy) //Crea un albero binario
{
    struct alberoBinario *foo = AlberoBinario_New(formato_stampa, key);
    foo->dad = daddy;

    return foo;
}

struct alberoBinario *AlberoBinario_Clona(struct alberoBinario *original)
{
    if(original == NULL)
        return NULL;

    if(original->root && original->dad == NULL && original->right == NULL && original->left == NULL) //root
        original = original->root;

    struct alberoBinario *root = AlberoBinario_New2(original->formato_stampa, original->key, NULL);
    struct alberoBinario *clone = root;

    while(original)
        if(original->left != NULL && clone->left == NULL)
        {
            struct alberoBinario *l0 = original->left;

            clone->left = AlberoBinario_New2(original->formato_stampa, l0->key, clone);
            original = original->left;
            clone = clone->left;
        }
        else if(original->right != NULL && clone->right == NULL)
        {
            struct alberoBinario *r0 = original->right;
            clone->right = AlberoBinario_New2(original->formato_stampa, r0->key, clone);
            original = original->right;
            clone = clone->right;
        }
        else
        {
            original = original->dad;
            clone = clone->dad;
        }

    return root;
}

void AlberoBinario_Free(struct alberoBinario *c) //Dealloca un albero binario
{
    if(c)
    {
        if(c->root && c->dad == NULL && c->right == NULL && c->left == NULL) //root
        {
            AlberoBinario_Free(c->root);
        }
        else
        {
            AlberoBinario_Free(c->left);
            AlberoBinario_Free(c->right);
        }

        free(c);
        c = NULL;
    }
}

void AlberoBinario_Insert(struct alberoBinario *t, struct alberoBinario *z) //O(h) Inserisce nell'albero binario t l'albero z
{
    struct alberoBinario *y = NULL;
    struct alberoBinario *x = t->root;

    t->numero_nodi++;

    while(x)
    {
        y = x;

        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;

        t->h++;
    }

    z->dad = y;

    if(y == NULL)
        t->root = z; //t era vuoto
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

struct alberoBinario *AlberoBinario_Tree_Minimum(struct alberoBinario *x) //O(h) Minimo
{
    if(x->root)
    {
        return AlberoBinario_Tree_Minimum(x->root);
    }
    else
    {
        if(x->left)
            return AlberoBinario_Tree_Minimum(x->left);
        else
            return x;
    }
}

struct alberoBinario *AlberoBinario_Tree_Maximum(struct alberoBinario *x) //O(h) Massimo
{
    if(x->root)
    {
        return AlberoBinario_Tree_Maximum(x->root);
    }
    else
    {
        if(x->right)
            return AlberoBinario_Tree_Maximum(x->right);

        else
            return x;
    }
}

void *AlberoBinario_Tree_Maximum2(struct alberoBinario *x)//O(h) Massimo
{
    return AlberoBinario_Tree_Maximum(x)->key;
}

void *AlberoBinario_Tree_Minimum2(struct alberoBinario *x)//O(h) Minimo
{
    return AlberoBinario_Tree_Minimum(x)->key;
}

struct alberoBinario *AlberoBinario_Tree_Successor(struct alberoBinario *x)//O(h) Successore
{
    if(x->root)
    {
        return AlberoBinario_Tree_Successor(x->root);
    }
    else
    {
        if(x->right)
            return AlberoBinario_Tree_Minimum(x->right);

        struct alberoBinario *y = x->dad;

        while(y && x == y->right)
        {
            x = y;
            y = y->dad;
        }

        return y;
    }
}

struct alberoBinario *AlberoBinario_Tree_Predecessor(struct alberoBinario *x)//O(h) Predecessore
{
    if(x->root)
    {
        return AlberoBinario_Tree_Predecessor(x->root);
    }
    else
    {
        if(x->left)
            return AlberoBinario_Tree_Maximum(x->left);

        struct alberoBinario *y = x->dad;

        while(y && x == y->left)
        {
            x = y;
            y = y->dad;
        }

        return y;
    }
}

void *AlberoBinario_Tree_Successor2(struct alberoBinario *x)//O(h) Successore
{
    return AlberoBinario_Tree_Successor(x)->key;
}

void *AlberoBinario_Tree_Predecessor2(struct alberoBinario *x)//O(h) Predecessore
{
    return AlberoBinario_Tree_Predecessor(x)->key;
}

void AlberoBinario_Tree_Search3(struct alberoBinario *x, struct alberoBinario *trovati[], unsigned int *n_trovati, void *from, void *to) //Θ(n) Ricerca un valore compreso tra from & to
{
    if(x)
        if(x->root && x->dad == NULL && x->right == NULL && x->left == NULL) //root
        {
            AlberoBinario_Tree_Search3(x->root, trovati, n_trovati, from, to);
        }
        else
        {
            AlberoBinario_Tree_Search3(x->left, trovati, n_trovati, from, to);

            if(x->key >= from && x->key <= to)
            {
                //Trovato
                trovati[*n_trovati] = x;
                *n_trovati += 1;
            }

            AlberoBinario_Tree_Search3(x->right, trovati, n_trovati, from, to);
        }
}

struct alberoBinario **AlberoBinario_Tree_Search2(struct alberoBinario *x, unsigned int *n_trovati, void *from, void *to) //Θ(n) Ricerca un valore compreso tra from & to
{
    struct alberoBinario **trovati = calloc(x->numero_nodi, sizeof(struct alberoBinario)); //potrebbe restituire tutti i nodi

    *n_trovati = 0;
    AlberoBinario_Tree_Search3(x, trovati, n_trovati, from, to);

    return trovati;
}

struct alberoBinario *AlberoBinario_Tree_Search(struct alberoBinario *x, void *k) //O(h) Ricerca il valore esatto k
{
    if(x != NULL && x->root != NULL && x->dad == NULL && x->right == NULL && x->left == NULL)
        return AlberoBinario_Tree_Search(x->root, k);

    if(x == NULL || x->key == k)
        return x;

    if(k < x->key)
        return AlberoBinario_Tree_Search(x->left, k);
    else
        return AlberoBinario_Tree_Search(x->right, k);
}

unsigned long *AlberoBinario_Tree_Search4(struct alberoBinario *x, unsigned int *n_trovati, void *from, void *to) //Θ(n) Ricerca un valore compreso tra from & to
{
    struct alberoBinario **trovati = AlberoBinario_Tree_Search2(x, n_trovati, from, to);

    if(*n_trovati > 0)
    {
        unsigned int i;
        unsigned long *trovatil = calloc(*n_trovati, sizeof(unsigned long));

        for(i = 0; i < *n_trovati; i++)
            trovatil[i] = trovati[i]->key;

        return trovatil;
    }
    else
    {
        return NULL;
    }
}

void AlberoBinario_Transplant(struct alberoBinario *t, struct alberoBinario *u, struct alberoBinario *v) //O(1) Nell'albero t traspianta l'albero v nell'albero u
{
    if(u->dad == NULL)
        t->root = v;
    else if(u == ((struct alberoBinario *) u->dad)->left)
        ((struct alberoBinario *) u->dad)->left = v;
    else
        ((struct alberoBinario *) u->dad)->right = v;

    if(v != NULL)
        v->dad = u->dad;
}

void AlberoBinario_Tree_Delete(struct alberoBinario *t, struct alberoBinario *z) //O(h) Elimina dall'albero t l'albero z
{
    if(z->left == NULL)
        AlberoBinario_Transplant(t, z, z->right);
    else if(z->right == NULL)
        AlberoBinario_Transplant(t, z, z->left);
    else
    {
        struct alberoBinario *y = AlberoBinario_Tree_Minimum(z->right);

        if(y->dad != z)
        {
            AlberoBinario_Transplant(t, y, y->right);
            y->right = z->right;
            ((struct alberoBinario *) y->right)->dad = y;
        }

        AlberoBinario_Transplant(t, z, y);
        y->left = z->left;
        ((struct alberoBinario *) y->left)->dad = y;
    }
}

void AlberoBinario_Tree_Delete3(struct alberoBinario *t, void *val) //O(2h) Elimina dall'albero t il valore val
{
    struct alberoBinario *s = AlberoBinario_Tree_Search(t, val); //O(h)

    if(s)
        AlberoBinario_Tree_Delete(t, s); //O(h)
}

void AlberoBinario_Inorder_Tree_Walk2(struct alberoBinario *x, unsigned long indent) //Θ(n) Stampa l'albero x
{
    if(x)
        if(x->root)
        {
            AlberoBinario_Inorder_Tree_Walk2(x->root, indent);
        }
        else
        {
            AlberoBinario_Inorder_Tree_Walk2(x->left, indent + 1);

            unsigned long i;
            for(i = 0; i < indent; i++)
                printf("%c", '--');

            printf(x->formato_stampa, x->key);
            printf("%c", '\n');

            AlberoBinario_Inorder_Tree_Walk2(x->right, indent + 1);
        }
}

void AlberoBinario_Inorder_Tree_Walk(struct alberoBinario *x) //Θ(n) Stampa l'albero x
{
    printf("\n\n");
    AlberoBinario_Inorder_Tree_Walk2(x, 0); //Θ(n)
    printf("\n");
}

int AlberoBinario_Tree_Delete_20120126(struct alberoBinario *t, struct alberoBinario *p, int x, int i) //Θ(n) + [O(h)] elimina da t il nodo che contiene la chiave k che si trova in posizione x nell'ordinamento totale delle chiavi contenute in T, rispetto alla relazione d'ordine ≤
{
    if(t == NULL)
        return i;

    if(t->root && t->dad == NULL && t->right == NULL && t->left == NULL) //root
        t = t->root;

    if(t->left)
        i = AlberoBinario_Tree_Delete_20120126(t->left, t, x, i);

    int d = i + 1;

    if(t->right)
        d = AlberoBinario_Tree_Delete_20120126(t->right, t, x, i + 1);

    if(i + 1 == x)
        AlberoBinario_Tree_Delete(t, p);

    return d;
}

int AlberoBinario_Equals(struct alberoBinario *a, struct alberoBinario *b)
{
    if(a == b)
        return 1;

    if(a == NULL || b == NULL)
        return 0;

    if(a->root && a->dad == NULL && a->right == NULL && a->left == NULL) //root
        a = a->root;

    if(b->root && b->dad == NULL && b->right == NULL && b->left == NULL) //root
        b = b->root;

    return a->key == b->key && AlberoBinario_Equals(a->left, b->left) && AlberoBinario_Equals(a->right, b->right);
}

void Alg3(size_t size_Of_Generic, struct alberoBinario *T, unsigned long da, unsigned long a, unsigned long H, unsigned long H_DA, unsigned long H_A)
{
    if(T)
    {
        if(T->key >= da)
        {
            H++;
            Alg3(size_Of_Generic, T->left, da, a, H, H_DA, H_A);
            H--;
            if(T->key >= da && T->key <= a && H >= H_DA && H <= H_A)
                printf("%lu %lu\n", H, T->key);
        }

        if(T->key <= a)
        {
            H++;
            Alg3(size_Of_Generic, T->right, da, a, H, H_DA, H_A);
            H--;
            if(T->key >= da && T->key <= a && H >= H_DA && H <= H_A)
                printf("%lu %lu\n", H, T->key);
        }
    }
}

struct alberoBinario *Alg20150625_03_p(struct alberoBinario *T, unsigned long k)
{
    struct alberoBinario *Last2 = NULL;
    struct alberoBinario *Last = NULL;

    while(T)
    {
        Last2 = Last;
        Last = T;

        if(k == T->key)
            return T;

        if(k < T->key)
        {
            T = T->left;
        }
        else
        {
            if(T->right != NULL)
                Last2 = NULL;

            T = T->right;
        }

        if(T == NULL)
            if(Last2)
                return Last2;
            else
                return Last;
    }
}

struct alberoBinario *AlberoBinario_Tree_Successor3(struct alberoBinario *T, void *k) //O(h)
{
    struct alberoBinario *succ = NULL;
    struct alberoBinario *y = T;
    struct alberoBinario *x = T;

    while(y)
    {
        x = y;

        if(k == x->key)
            break;
        else if(k < y->key)
            y = y->left;
        else
            y = y->right;
    }

    if(x->right)
    {
        x = x->right;

        while(x->left)
            x = x->left;

        return x;
    }

    while(T)
    {
        if(x->key < T->key)
        {
            succ = T;
            T = T->left;
        }
        else if(x->key > T->key)
            T = T->right;
        else
            break;
    }

    if(succ == NULL && k < T->key)
        return T;
    else if(k < T->key)
        return x;
    else
        return succ;
}

void Alg2(size_t size_Of_Generic, struct alberoBinario *T, unsigned long da, unsigned long a, unsigned long H_DA, unsigned long H_A)
{
    if(T->root && T->dad == NULL && T->right == NULL && T->left == NULL) //root
        T = T->root;

    Alg3(size_Of_Generic, T, da, a, 1, H_DA, H_A);
}

void Alg(size_t size_Of_Generic, struct alberoBinario *T, unsigned long da, unsigned long a, unsigned long H_DA, unsigned long H_A)
{
    struct stack *S = Stack_New(size_Of_Generic, T->numero_nodi);
    struct alberoBinario *C = T;

    if(T->root && T->dad == NULL && T->right == NULL && T->left == NULL) //root
        C = T->root;

    unsigned long H = 1;

    while(!Stack_IsEmpty(S) || C)
        if(C)
        {
            Stack_Push(S, C);
            C = C->left;
            H++;
        }
        else
        {
            C = Stack_Pop(S);

            printf("%lu %lu\n", H, C->key);
            unsigned long Z = C->key;
            if(Z >= da && Z <= a && H >= H_DA && H <= H_A)
            {
                //printf("%lu\n", C->key);
                //printf("\n");
            }

            C = C->right;
            H++;
        }
}