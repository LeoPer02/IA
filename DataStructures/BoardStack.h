
#ifndef IA_BOARDSTACK_H
#define IA_BOARDSTACK_H

#include "IDSBoard.h"

// Struct to hold the data and the pointer to the next boardStackElement.
typedef struct boardStackElement{
    IDSBoard* board;
    struct boardStackElement* next;
} BoardStackElement;

void pushBoardToStack(IDSBoard* board, struct boardStackElement** stack);
// Remove boardStackElement from the topMovement of the stack
void popBoardFromStack(struct boardStackElement** stack);
// Display the boardStackElement at the topMovement of the stack
void topBoardFromStack(struct boardStackElement* stack);

void printBoardStackSize(struct boardStackElement* stack);

#endif //IA_BOARDSTACK_H
