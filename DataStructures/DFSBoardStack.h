//
// Created by matheus on 24/03/2022.
//

#ifndef IA_DFSBOARDSTACK_H
#define IA_DFSBOARDSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "DFSBoard.h"
#include "MovementStack.h"


// Struct to hold the data and the pointer to the next boardStackElement.
typedef struct dfsBoardStackElement{
    DFSBoard* board;
    struct boardStackElement* next;
} DFSBoardStackElement;

// Append the new boardStackElement to the start of the stack
void pushDFSBoardToStack(DFSBoard* board, struct dfsBoardStackElement** stack);
// Remove boardStackElement from the topMovement of the stack
void popDFSBoardFromStack(struct dfsBoardStackElement** stack);

void printDFSBoardStackSize(struct dfsBoardStackElement* stack);

#endif //IA_DFSBOARDSTACK_H
