#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "z_main.h"

typedef struct _queue_t{  
    int qlength;
    pNode front, rear;
}Queue, *pQueue;

extern pQueue queueCrearte();
extern int queueIsEmpty(pQueue queue);
extern void EnQueue(pQueue queue, pNode node);
extern pNode DeQueue(pQueue queue);
extern pNode queueGetFront(pQueue queue);
extern pNode queueGetRear(pQueue queue);
extern void queueErgodic (pQueue queue);
extern void queueFree(pQueue queue);

#endif
