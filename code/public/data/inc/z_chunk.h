#ifndef _CHUNK_H_
#define _CHUNK_H_

#define CHUNKSIZE  1024
#define MAXCHUNKS  1024

typedef struct _chunk_t{
    int unit;
    int nodetype;
    int ncount; 
    int allnodes;
    int nchunk;
    int maxchunks;

    void *nodefree;
    void *chunks[MAXCHUNKS];
    char* data[MAXCHUNKS];                   
} Chunk, *pChunk;

extern void chunkInit(pChunk chunk, int unit, int maxchunks);
extern pNode chunkAllocNode(pChunk chunk);
extern avpNode chunkAllocAvNode(pChunk chunk);
extern void chunkFreeNode(pChunk chunk, pNode node);
extern void chunkFreeAvNode(pChunk chunk, avpNode avnode);
extern void chunkFree(pChunk chunk);
#endif

