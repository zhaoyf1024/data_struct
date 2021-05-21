#ifndef _TREE_H_
#define _TREE_H_
#include "z_main.h"

typedef struct _tree_t{
    avpNode root;
}Tree, *pTree;

extern pTree treeCreate();
extern void treeInsertNode(pTree tree, avpNode node);
extern void treeDeleteNode(pTree tree, avpNode node);
extern void PreOrder(avpNode root);
extern void InOrder(avpNode root);

#endif
