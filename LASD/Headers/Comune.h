/*
 * File:   Comune.h
 * Author: [MAIONE MIKY]
 *
 * Created on 13 giugno 2015, 10.44
 */

#ifndef COMUNE_H
#define	COMUNE_H

struct comune
{
    char *nome;
    unsigned int x, y;
};

struct comune *Comune_New(char *nome, unsigned int x, unsigned int y);
void Comune_Free(struct comune *c);

void Comune_Stampa(void *comune);

#endif	/* COMUNE_H */