#include "z_queue.h"

pQueue queueCrearte()
{
    pQueue newQueue;
    newQueue = (pQueue)calloc(1, sizeof(Queue));
    if(!newQueue)
        return NULL;

    return newQueue;
}

int queueIsEmpty(pQueue queue)
{
    return queue->front == NULL;
}

void EnQueue(pQueue queue, pNode node)
{
    if(queue == NULL || node == NULL)
        return;

    node->prev = queue->rear;
    node->next = queue->front;
    if(node->prev) queue->rear->next = node; else queue->front = node;
    if(node->next) queue->front->prev = node; else queue->rear = node;
    queue->rear = node;
    queue->qlength++;
}

pNode DeQueue(pQueue queue)
{
    if(queue == NULL)
        return;
        
    if(queueIsEmpty(queue))
        return NULL;

    pNode tnode;
    tnode = queue->front;
    queue->front = tnode->next;
    if(tnode->prev && tnode != queue->rear) tnode->next->prev = tnode->prev; else queue->rear = NULL;
    if(tnode->next && tnode != queue->front) tnode->prev->next = tnode->next; else queue->front = NULL;
    tnode->prev = NULL;
    tnode->next = NULL;
    queue->qlength--;
    
    return tnode;
}

pNode queueGetFront(pQueue queue)
{
    if(queue == NULL)
        return NULL;
        
    if(queueIsEmpty(queue))
        return NULL;

    return queue->front;
}

pNode queueGetRear(pQueue queue)
{
    if(queue == NULL)
        return NULL;
        
    if(queueIsEmpty(queue))
        return NULL;

    return queue->rear;
}

void queueErgodic (pQueue queue)
{
    if(queue == NULL)
        return;
        
    if(queueIsEmpty(queue))
        return;

    pNode tnode = queue->front;
    do
    {  
        if(tnode) {
            printf("hash:[%d] data:[%d]\n",tnode->hash, *(int *)(tnode->data));
        } else {
            printf("queue is Empty\n");
            break;
        }
        tnode = tnode->next;	
    }while(tnode != queue->front);
}

void queueFree(pQueue queue)
{

}

