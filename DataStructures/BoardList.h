//
// Created by matheus on 21/03/2022.
//

#ifndef IA_BOARDLIST_H
#define IA_BOARDLIST_H

#include "../DataStructures/BFSBoard.h"

typedef struct boardListElement{
    BFSBoard* board;
    struct boardListElement* next;
} BoardListElement;

// Append the new boardStackElement to the start of the stack
void pushBoardToList(BFSBoard* board, struct boardListElement** stack);
// Remove boardStackElement from the topMovement of the stack
void popBoardFromList(struct boardListElement** stack);
// Display the boardStackElement at the topMovement of the stack
void topBoardFromList(struct boardListElement* stack);

void printBoardListSize(struct boardListElement* stack);

#endif //IA_BOARDLIST_H
