#include <stdio.h>
#include <stdlib.h>
#include "DFSBoard.h"
#include "MovementStack.h"


// Struct to hold the data and the pointer to the next boardStackElement.
typedef struct dfsBoardStackElement{
    DFSBoard* board;
    struct dfsBoardStackElement* next;
} DFSBoardStackElement;

// Append the new boardStackElement to the start of the stack
void pushDFSBoardToStack(DFSBoard* board, struct dfsBoardStackElement** stack){
    struct dfsBoardStackElement* Element = (struct dfsBoardStackElement*)malloc(sizeof(struct dfsBoardStackElement));
    Element -> board = board;
    Element -> next = *stack;
    (*stack) = Element;
}
// Remove boardStackElement from the topMovement of the stack
void popDFSBoardFromStack(struct dfsBoardStackElement** stack){
    if(*stack != NULL){
        //printf("Element popped: %c\n",(*stack) -> idsBoard);
        struct dfsBoardStackElement* tempPtr = *stack;
        *stack = (*stack) -> next;

        deleteMovementStack(&(tempPtr->board->movementStack));
        free(tempPtr->board);
        free(tempPtr);
    }
    else{
        printf("The stack is empty.\n");
    }
}

void printDFSBoardStackSize(struct dfsBoardStackElement* stack) {
    int count = 0;
    for (struct dfsBoardStackElement* s = stack; s != NULL; s = s->next) {
        count++;
    }
    printf("Stack size: %d\n", count);
}