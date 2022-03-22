#include <stdio.h>
#include <stdlib.h>
#include "BFSBoard.h"
#include "MovementStack.h"


// Struct to hold the data and the pointer to the next boardStackElement.
typedef struct boardListElement{
    BFSBoard* board;
    struct boardListElement* next;
} BoardStackElement;

// Append the new boardStackElement to the start of the stack
void pushBoardToList(BFSBoard* board, struct boardListElement** stack){
    struct boardListElement* lastElement;
    for (lastElement = (*stack); lastElement->next != NULL; lastElement = lastElement->next);

    struct boardListElement* newElement = (struct boardListElement*)malloc(sizeof(struct boardListElement));
    newElement -> board = board;
    newElement -> next = NULL;

    lastElement->next = newElement;
}
// Remove boardStackElement from the topMovement of the stack
void popBoardFromList(struct boardListElement** stack){
    if(*stack != NULL){
        //printf("Element popped: %c\n",(*stack) -> idsBoard);
        struct boardListElement* tempPtr = *stack;
        *stack = (*stack) -> next;

        deleteMovementStack(&(tempPtr->board->movementStack));
        free(tempPtr->board);
        free(tempPtr);
    }
    else{
        printf("The stack is empty.\n");
    }
}
// Display the boardStackElement at the topMovement of the stack
void topBoardFromList(struct boardListElement* stack){
    if(stack != NULL){
        //printf("Element on topMovement: %c\n", stack -> idsBoard);
    }
    else{
        printf("The stack is empty.\n");
    }
}

void printBoardListSize(struct boardListElement* stack) {
    int count = 0;
    for (struct boardListElement* s = stack; s != NULL; s = s->next) {
        count++;
    }
    printf("List size: %d\n", count);
}