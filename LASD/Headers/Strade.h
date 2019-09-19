/*
 * File:   Strade.h
 * Author: [MAIONE MIKY]
 *
 * Created on 8 giugno 2015, 12.23
 */

#ifndef STRADE_H
#define	STRADE_H

struct prop_strada
{
    unsigned long lunghezza, tipo;
};

struct prop_strada *Prop_Strada_New(unsigned long tipo, unsigned long lunghezza);

#endif	/* STRADE_H */

