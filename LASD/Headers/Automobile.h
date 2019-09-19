/*
 * File:   Automobile.h
 * Author: [MAIONE MIKY]
 *
 * Created on 10 giugno 2015, 15.56
 */

#ifndef AUTOMOBILE_H
#define	AUTOMOBILE_H

#define VA 150
#define VS 90
#define VC 50

struct automobile
{
    char *nome;
    unsigned int vel_A, vel_S, vel_C;
};

struct automobile *Automobile_New(char *nome, unsigned int vel_A, unsigned int vel_S, unsigned int vel_C);
void Automobile_Free(struct automobile *A);

unsigned long Automobile_CalcolaTempoDiPercorrenza(void *automobile_, void *proprieta_); //return secondi per percorrere la strada

#endif	/* AUTOMOBILE_H */