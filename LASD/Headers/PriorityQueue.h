/*
 *File:   PriorityQueue.h
 *Author: [MAIONE MIKY]
 *
 *Created on 11 giugno 2015, 16.00
 */

#ifndef PRIORITYQUEUE_H
#define	PRIORITYQUEUE_H

#include <stdbool.h>

struct priorityQueue_element
{
    void *data;
    int pri;
};

struct priorityQueue
{
    struct priorityQueue_element *buf;
    int n, alloc;
};

struct priorityQueue *PriorityQueue_New(unsigned int size);

void PriorityQueue_Push(struct priorityQueue *q, void *data, int priority);
void *PriorityQueue_Pop(struct priorityQueue *q, int *priority);
void *PriorityQueue_Top(struct priorityQueue *q, int *priority);
void PriorityQueue_DecreaseKey(struct priorityQueue *q, void *data, int priority);
void PriorityQueue_DecreaseKey2(struct priorityQueue *q, void *data, int priority, bool AddIfNotExists);

bool PriorityQueue_IsEmpty(struct priorityQueue *q);
bool PriorityQueue_Contains(struct priorityQueue *q, void *data);

void PriorityQueue_Combine(struct priorityQueue *q, struct priorityQueue *q2);

#endif	/*PRIORITYQUEUE_H */