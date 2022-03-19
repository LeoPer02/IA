
#ifndef IA_BOARDSTACK_H
#define IA_BOARDSTACK_H

#include "Board.h"

// Struct to hold the data and the pointer to the next boardElement.
typedef struct boardElement{
    Board* board;
    struct boardElement* next;
} BoardElement;

void pushBoard(Board* board, struct boardElement** stack);
// Remove boardElement from the topMovement of the stack
void popBoard(struct boardElement** stack);
// Display the boardElement at the topMovement of the stack
void topBoard(struct boardElement* stack);

void printBoardStackSize(struct boardElement* stack);

#endif //IA_BOARDSTACK_H
