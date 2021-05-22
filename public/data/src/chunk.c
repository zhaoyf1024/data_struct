#include "main.h"

void chunkInit(pChunk chunk, int unit, int maxchunks)
{
    bzero(chunk, sizeof(Chunk));
    chunk->maxchunks = maxchunks > MAXCHUNKS ? MAXCHUNKS : maxchunks;
    chunk->unit = unit;
 }

pNode chunkAllocNode(pChunk chunk)
{
    pNode node;
    char *data;
    int index;

    if(chunk->nodefree) 
        goto l_alloc;
        
    if(chunk->nchunk == chunk->maxchunks)
        return NULL;

    node = (pNode)calloc(CHUNKSIZE,sizeof(Node));
    if(!node) return NULL;   
    
    if(chunk->unit)
    {
        data = (char *)calloc(CHUNKSIZE,chunk->unit);
        if(!data)
        {
            free(node); 
        }
        chunk->data[chunk->nchunk] = data;
        chunk->allnodes += CHUNKSIZE;
    }
    else
    {
        data = NULL;
    }
    
    chunk->chunks[chunk->nchunk++] = chunk->nodefree = node;
    for(index = 1; index < CHUNKSIZE; index++, node++, data+=chunk->unit)
    {
        node->data = data;
        node->next = node+1;
    }
    node->data = data;
    node->next = NULL;

l_alloc:
    node = chunk->nodefree;
    chunk->nodefree = node->next;
    node->next = NULL;
    chunk->ncount++;

    return node;
}

avpNode chunkAllocAvNode(pChunk chunk)
{
    avpNode node;
    char *data;
    int index;

    if(chunk->nodefree) 
        goto l_alloc;
        
    if(chunk->nchunk == chunk->maxchunks)
        return NULL;

    node = (avpNode)calloc(CHUNKSIZE,sizeof(avNode));
    if(!node) return NULL;   
    
    if(chunk->unit)
    {
        data = (char *)calloc(CHUNKSIZE,chunk->unit);
        if(!data)
        {
            free(node); 
        }
        chunk->data[chunk->nchunk] = data;
        chunk->allnodes += CHUNKSIZE;
    }
    else
    {
        data = NULL;
    }
    
    chunk->chunks[chunk->nchunk++] = chunk->nodefree = node;
    for(index = 1; index < CHUNKSIZE; index++, node++, data+=chunk->unit)
    {
        node->data = data;
        node->lchild = node+1;
    }
    node->data = data;
    node->lchild = NULL;

l_alloc:
    node = chunk->nodefree;
    chunk->nodefree = node->lchild;
    node->lchild = NULL;
    chunk->ncount++;

    return node;
}

void chunkFreeNode(pChunk chunk, pNode node)
{
    if (!chunk->ncount)
    {
        return;
    }

    node->next = chunk->nodefree;
    chunk->nodefree = node;
    chunk->ncount--;
}

void chunkFreeAvNode(pChunk chunk, avpNode node)
{
    if (!chunk->ncount)
    {
        return;
    }

    node->lchild = chunk->nodefree;
    chunk->nodefree = node;
    chunk->ncount--;
}

void chunkFree(pChunk chunk)
{
    int index;
    for(index = 0; index < chunk->nchunk; index++) {
        free(chunk->chunks[index]);
        if(chunk->unit) {
            free(chunk->data[index]);
        }
    }
    chunk->nchunk = 0;
    chunk->ncount = 0;
}
