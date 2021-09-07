#include "list.h"

pList listCreate()
{
    pList newList;
    newList = (pList)calloc(1, sizeof(pList));
    if(!newList)
        return NULL;

    return newList;
}

int listIsEmpty(pList list)
{
    return list->header == NULL;
}

void listInsert(pList list, u8 insertDir, pNode node)
{
    node->prev = list->tail;
    node->next = list->header; 
    if(node->prev) list->tail->next = node; else list->tail = node;
    if(node->next) list->header->prev = node; else list->header = node;
    if(insertDir) list->tail = node; else list->header = node;
    list->list_length++;
}

pNode listFindNode(pList list, pNode node)
{
    pNode tnode = list->header;
    do{
        if(!COMPARENODE(tnode, node)) 
        {
            return tnode;
        }
        tnode = tnode->next;
    }while(tnode != list->header);
    return NULL;
}

void listDelNode(pList list, pNode node)
{
    if(node->prev && list->tail != node) node->next->prev = node->prev; else list->tail = NULL;
    if(node->next && list->header != node) node->prev->next = node->next; else list->header = NULL;
}

pNode listDelNodeN(pList list, pNode node)
{
    if(list == NULL)
        return NULL;
        
    if(listIsEmpty(list))
        return NULL;

    pNode tnode;
    tnode = listFindNode(list, node);
    if(tnode)
    {
        if(tnode == list->header) list->header = tnode->next; 
        else if(tnode == list->tail) list->tail = tnode->prev;
        listDelNode(list, tnode);
        list->list_length--;
        
        return tnode;
    }
    return NULL;
}

pNode listDelNodeD(pList list, u8 insertDir)
{
    if(list == NULL)
        return NULL;
        
    if(listIsEmpty(list))
        return NULL;

    pNode tnode;
    tnode = insertDir ? list->tail : list->header;
    if(insertDir) list->tail = tnode->prev; else list->header = tnode->next;
    listDelNode(list, tnode);
    list->list_length--;

    return tnode;
}

void listFreeNode(pList list, u8 insertDir, pNode node, pChunk chunk)
{

    if(list == NULL)
        return;
        
    if(listIsEmpty(list))
        return;
       
    pNode tnode;
    tnode = node ? listDelNodeN(list, node) : listDelNodeD(list, insertDir);
    chunkFreeNode(chunk, tnode);
}

void listErgodic(pList list)
{  
    if(list == NULL || list->header == NULL ||list->tail == NULL)
        return;

    pNode tnode = list->header;
    do
    {  
        if(tnode) {
            printf("hash:[%d] data:[%d]\n",tnode->hash, *(int *)(tnode->data));
        } else {
            printf("list is Empty\n");
            break;
        }
        tnode = tnode->next;	
    }while(tnode != list->header);
}

