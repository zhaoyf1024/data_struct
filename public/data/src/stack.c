#include "z_stack.h"

pStack stackCrearte()
{
    pStack newStack;
    newStack = (pStack)calloc(1, sizeof(Stack));
    if(!newStack)
        return NULL;
        
    return newStack;
}

int stackIsEmpty(pStack stack)
{
    return stack->top == NULL;
}

void stackPush(pStack stack, pNode node)
{
    if(stack == NULL || node == NULL)
        return;
        
    node->prev = stack->top;
    node->next = stack->bottom;
    if(node->prev) stack->top->prev = node; else stack->top = node;
    if(node->next) node->next = stack->top; else stack->bottom = node;
    stack->top = node;
    stack->slength++;
}

pNode stackPop(pStack stack)
{
    if(stack == NULL)
        return NULL;
        
    if(stackIsEmpty(stack))
        return NULL;
    
    pNode tnode;
    tnode = stack->top;
    stack->top = tnode->next;
    if(tnode->next) stack->top->prev = stack->top->next; else stack->bottom = NULL;
    tnode->prev = NULL;
    tnode->next = NULL;
    stack->slength--;
    
   return tnode;
}

pNode stackTop(pStack stack)
{
    if(stack == NULL)
        return NULL;
        
    if(stackIsEmpty(stack))
        return NULL;

    return stack->top;
}

void stackErgodic (pStack stack)
{
    if(stack == NULL)
        return;
        
    if(stackIsEmpty(stack))
        return;

    int index;
    pNode tnode = stack->top;
    for(index = 0; index < stack->slength && tnode; index++)
    {
         if(tnode){
            printf("hash:[%d] data:[%d]\n", tnode->hash, *(int *)(tnode->data));
         } else {
             printf("stack is Empty\n");
             break;
         }
        tnode = tnode->next;
    }
}

void stackFree(pStack stack)
{

}


