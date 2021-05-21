#ifndef _STACK_H_
#define _STACK_H_

#include "z_main.h"

typedef struct _stack_t{  
    int slength;
    pNode top, bottom;
}Stack, *pStack;

extern pStack stackCrearte();
extern int stackIsEmpty(pStack stack);
extern void stackPush(pStack stack, pNode node);
extern pNode stackPop(pStack stack);
extern pNode stackTop(pStack stack);
extern void stackErgodic (pStack stack);
extern void stackFree(pStack stack);

#endif
