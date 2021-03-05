#ifndef _NODE_H_
#define _NODE_H_

#define DATA void

typedef enum{
    NODE_LIST = 0,
    NODE_TREE,
}NODE_TYPE;

typedef struct _node_t Node, *pNode; 
struct _node_t{  
    long hash;
    pNode prev;
    pNode next;
    DATA *data;
};

typedef struct _avnode_t avNode, *avpNode; 
struct _avnode_t{
    int hash;
    int balance;
    int depth;
    avpNode parent;
    avpNode rchild;
    avpNode lchild;
    avpNode next;
    DATA *data;
};

#define COMPARENODE(pNode1, pNode2) ((pNode1->hash == pNode2->hash) ? 0 : 1)
#define COMPAREAVNODE(avpNode1, avpNode2) ((avpNode1->hash) <= (avpNode2->hash))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#endif
