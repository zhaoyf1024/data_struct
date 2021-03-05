#ifndef _LIST_H_
#define _LIST_H_
#include "z_main.h"

typedef struct _list_t{  
    int list_length;
    pNode header, tail;
}List, *pList;

typedef enum{  
	LIST_NO = -1,
	LIST_HEAD,
	LIST_TAIL,
}LIST_OPERATION_DIRECTION;

extern pList listCreate();
extern int listIsEmpty(pList list);
extern void listInsert(pList list, u8 insertDir, pNode node);
extern pNode listFindNode(pList list, pNode node);
extern pNode listDelNodeN(pList list, pNode node);
extern pNode listDelNodeD(pList list, u8 insertDir);
extern void listFreeNode(pList list, u8 insertDir, pNode node, pChunk chunk);
extern void listErgodic(pList list);

#endif
