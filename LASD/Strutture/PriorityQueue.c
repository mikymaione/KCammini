#include "../Headers/PriorityQueue.h"

#define PriorityQueue_Purge(q) (q)->n = 1
#define PriorityQueue_Size(q) ((q)->n - 1)

/*first element in array not used to simplify indices */
struct priorityQueue *PriorityQueue_New(unsigned int size)
{
    struct priorityQueue *q = malloc(sizeof(struct priorityQueue));

    if(size < 4)
        size = 4;

    q->buf = calloc(size, sizeof(struct priorityQueue_element));
    q->alloc = size;
    q->n = 1;

    return q;
}

void PriorityQueue_DecreaseKey2(struct priorityQueue *q, void *data, int priority, bool AddIfNotExists)
{
    int i;
    bool finded = false;

    for(i = 1; i < q->n; i++)
        if(q->buf[i].data == data)
        {
            q->buf[i].pri = priority;
            finded = true;
            break;
        }

    if(AddIfNotExists == true && finded == false)
        PriorityQueue_Push(q, data, priority);
}

void PriorityQueue_DecreaseKey(struct priorityQueue *q, void *data, int priority)
{
    PriorityQueue_DecreaseKey2(q, data, priority, false);
}

void PriorityQueue_Push(struct priorityQueue *q, void *data, int priority)
{
    struct priorityQueue_element *b;
    int n, m;

    if(q->n >= q->alloc)
    {
        q->alloc *= 2;
        b = q->buf = realloc(q->buf, sizeof(struct priorityQueue_element) *q->alloc);
    }
    else
    {
        b = q->buf;
    }

    n = q->n++;

    /*append at end, then up heap */
    while((m = n / 2) && priority < b[m].pri)
    {
        b[n] = b[m];
        n = m;
    }

    b[n].data = data;
    b[n].pri = priority;
}

bool PriorityQueue_IsEmpty(struct priorityQueue *q)
{
    if(q->n == 1)
        return true;
    else
        return false;
}

bool PriorityQueue_Contains(struct priorityQueue *q, void *data)
{
    int i;
    bool r = false;

    for(i = 1; i < q->n; i++)
        if(q->buf[i].data == data)
        {
            r = true;
            break;
        }

    return r;
}

void *PriorityQueue_Pop(struct priorityQueue *q, int *priority) //remove top item. returns 0 if empty. *priority can be null.
{
    if(q->n == 1)
        return 0;

    void *out;
    struct priorityQueue_element *b = q->buf;

    out = b[1].data;

    if(priority)
        *priority = b[1].pri;

    /*pull last item to top, then down heap. */
    --q->n;

    int n = 1, m;
    while((m = n * 2) < q->n)
    {
        if(m + 1 < q->n && b[m].pri > b[m + 1].pri) m++;

        if(b[q->n].pri <= b[m].pri) break;
        b[n] = b[m];
        n = m;
    }

    b[n] = b[q->n];
    if(q->n < q->alloc / 2 && q->n >= 16)
        q->buf = realloc(q->buf, (q->alloc /= 2) * sizeof(b[0]));

    return out;
}

/*get the top element without removing it from queue */
void *PriorityQueue_Top(struct priorityQueue *q, int *priority)
{
    if(q->n == 1)
        return 0;

    if(priority)
        *priority = q->buf[1].pri;

    return q->buf[1].data;
}

// this is O(n log n), but probably not the best

void PriorityQueue_Combine(struct priorityQueue *q, struct priorityQueue *q2)
{
    int i;
    struct priorityQueue_element *e = q2->buf + 1;

    for(i = q2->n - 1; i >= 1; i--, e++)
        PriorityQueue_Push(q, e->data, e->pri);

    PriorityQueue_Purge(q2);
}