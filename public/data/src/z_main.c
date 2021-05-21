#include "z_main.h"

Chunk g_chunk;

int main(int argc, char *argv[])
{ 
#if 0
    int index;
    pNode tnode0, tnode1, tnode2;
    pNode node[10];
    chunkInit(&g_chunk, sizeof(int), 1);

    for(index = 0; index < 10; index++)
    {
        node[index] = chunkAllocNode(&g_chunk);
        *(int *)(node[index]->data) = index;
        node[index]->hash = index;
    }

    //List
    pList list_t = listCreate();
    listInsert(list_t, LIST_HEAD, node[1]);
    listInsert(list_t, LIST_TAIL, node[0]);
    listInsert(list_t, LIST_TAIL, node[2]);
    listInsert(list_t, LIST_TAIL, node[4]);
    listErgodic(list_t);
    printf("-------\n");
    printf("\n");

    tnode0 = listDelNodeD(list_t, LIST_HEAD);
    if(tnode0) printf("del:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    listErgodic(list_t);
    printf("-------\n");
    printf("\n");

    tnode0 = listDelNodeD(list_t, LIST_TAIL);
    if(tnode0) printf("del:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    listErgodic(list_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = listDelNodeN(list_t, node[0]);
    if(tnode0) printf("del:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    listErgodic(list_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = listDelNodeD(list_t, LIST_HEAD);
    if(tnode0) printf("del:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    listErgodic(list_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = listDelNodeD(list_t, LIST_HEAD);
    if(tnode0) printf("del:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    listErgodic(list_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = listDelNodeD(list_t, LIST_TAIL);
    if(tnode0) printf("del:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    listErgodic(list_t);
    printf("-------\n");
    printf("\n");

    tnode0 = listDelNodeN(list_t, node[0]);
    if(tnode0) printf("del:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    listErgodic(list_t);
    printf("-------\n");
    printf("\n");
        
    //Stack
    pStack stack_t = stackCrearte();
    stackPush(stack_t, node[4]);
    stackPush(stack_t, node[2]);
    stackPush(stack_t, node[0]);
    stackPush(stack_t, node[1]);
    tnode0 = stackTop(stack_t);
    if(tnode0) printf("pop:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    if(tnode1) printf("top:[hash:%d data:%d]\n",tnode1->hash, *(int *)(tnode1->data));
    stackErgodic(stack_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = stackPop(stack_t);
    tnode1 = stackTop(stack_t);
    if(tnode0) printf("pop:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    if(tnode1) printf("top:[hash:%d data:%d]\n",tnode1->hash, *(int *)(tnode1->data));
    stackErgodic(stack_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = stackPop(stack_t);
    tnode1 = stackTop(stack_t);
    if(tnode0) printf("pop:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    if(tnode1) printf("top:[hash:%d data:%d]\n",tnode1->hash, *(int *)(tnode1->data));
    stackErgodic(stack_t);
    printf("-------\n");
    printf("\n");

    tnode0 = stackPop(stack_t);
    tnode1 = stackTop(stack_t);
    if(tnode0) printf("pop:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    if(tnode1) printf("top:[hash:%d data:%d]\n",tnode1->hash, *(int *)(tnode1->data));
    stackErgodic(stack_t);
    printf("-------\n");
    printf("\n");

    tnode0 = stackPop(stack_t);
    tnode1 = stackTop(stack_t);
    if(tnode0) printf("pop:[hash:%d data:%d]\n",tnode0->hash, *(int *)(tnode0->data));
    if(tnode1) printf("top:[hash:%d data:%d]\n",tnode1->hash, *(int *)(tnode1->data));
    stackErgodic(stack_t);
    printf("-------\n");
    printf("\n");

    //Queue
    pQueue queue_t = queueCrearte();
    EnQueue(queue_t, node[1]);
    EnQueue(queue_t, node[0]);   
    EnQueue(queue_t, node[2]);
    EnQueue(queue_t, node[4]);
    tnode1 = queueGetFront(queue_t);
    tnode2 = queueGetRear(queue_t);
    if(tnode0) printf("En:[hash:%d data:%d]\n", tnode0->hash, *(int *)(tnode0->data));
    if(tnode1 && tnode2)  printf("front:[hash:%d data:%d] rear:[hash:%d data:%d]\n", tnode1->hash, *(int *)(tnode1->data), tnode2->hash, *(int *)(tnode2->data));
    queueErgodic(queue_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = DeQueue(queue_t);
    tnode1 = queueGetFront(queue_t);
    tnode2 = queueGetRear(queue_t);
    if(tnode0) printf("En:[hash:%d data:%d]\n", tnode0->hash, *(int *)(tnode0->data));
    if(tnode1 && tnode2)  printf("front:[hash:%d data:%d] rear:[hash:%d data:%d]\n", tnode1->hash, *(int *)(tnode1->data), tnode2->hash, *(int *)(tnode2->data));
    queueErgodic(queue_t);
    printf("-------\n");
    printf("\n");

    tnode0 = DeQueue(queue_t);
    tnode1 = queueGetFront(queue_t);
    tnode2 = queueGetRear(queue_t);
    if(tnode0) printf("En:[hash:%d data:%d]\n", tnode0->hash, *(int *)(tnode0->data));
    if(tnode1 && tnode2)  printf("front:[hash:%d data:%d] rear:[hash:%d data:%d]\n", tnode1->hash, *(int *)(tnode1->data), tnode2->hash, *(int *)(tnode2->data));
    queueErgodic(queue_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = DeQueue(queue_t);
    tnode1 = queueGetFront(queue_t);
    tnode2 = queueGetRear(queue_t);
    if(tnode0) printf("En:[hash:%d data:%d]\n", tnode0->hash, *(int *)(tnode0->data));
    if(tnode1 && tnode2)  printf("front:[hash:%d data:%d] rear:[hash:%d data:%d]\n", tnode1->hash, *(int *)(tnode1->data), tnode2->hash, *(int *)(tnode2->data));
    queueErgodic(queue_t);
    printf("-------\n");
    printf("\n");
    
    tnode0 = DeQueue(queue_t);
    tnode1 = queueGetFront(queue_t);
    tnode2 = queueGetRear(queue_t);
    if(tnode0) printf("En:[hash:%d data:%d]\n", tnode0->hash, *(int *)(tnode0->data));
    if(tnode1 && tnode2)  printf("front:[hash:%d data:%d] rear:[hash:%d data:%d]\n", tnode1->hash, *(int *)(tnode1->data), tnode2->hash, *(int *)(tnode2->data));
    queueErgodic(queue_t);
    printf("-------\n");
    printf("\n");
  
#else
    int index;
    avpNode node[10];
    chunkInit(&g_chunk, sizeof(int), 1);

    for(index = 0; index < 10; index++)
    {
        node[index] = chunkAllocAvNode(&g_chunk);
        node[index]->hash = index;
    }

    //Tree
    pTree tree = treeCreate();
	
    treeInsertNode(tree, node[5]);
    treeInsertNode(tree, node[2]);
    treeInsertNode(tree, node[0]);
    treeInsertNode(tree, node[7]);
    treeInsertNode(tree, node[1]);
    treeInsertNode(tree, node[8]);
    treeInsertNode(tree, node[9]);
    treeInsertNode(tree, node[4]);
    treeInsertNode(tree, node[6]);
    treeInsertNode(tree, node[3]);
    
    PreOrder(tree->root);
    printf("\n");
    printf("-------\n");
    InOrder(tree->root);
    printf("\n");
    printf("-------\n");
    PostOrder(tree->root);
    printf("\n");
    printf("-------\n");
    treeDeleteNode(tree, node[1]);
    PreOrder(tree->root);
    printf("\n");
    printf("-------\n");
    InOrder(tree->root);
    printf("\n");
    printf("-------\n");
    PostOrder(tree->root);
    printf("\n");
    printf("-------\n");
    treeDeleteNode(tree, node[8]);
    PreOrder(tree->root);
    printf("\n");
    printf("-------\n");
    InOrder(tree->root);
    printf("\n");
    printf("-------\n");
    PostOrder(tree->root);
    printf("\n");
    printf("-------\n");
    treeDeleteNode(tree, node[2]);
    PreOrder(tree->root);
    printf("\n");
    printf("-------\n");
    InOrder(tree->root);
    printf("\n");
    printf("-------\n");
    PostOrder(tree->root);
    printf("\n");
    printf("-------\n");

#endif

    return 0;
}
