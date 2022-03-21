#include <stdio.h>
#include <stdlib.h>
#include "IDSBoard.h"
#include "MovementStack.h"


// Struct to hold the data and the pointer to the next boardStackElement.
typedef struct boardStackElement{
    IDSBoard* board;
    struct boardStackElement* next;
} BoardStackElement;

// Append the new boardStackElement to the start of the stack
void pushBoardToStack(IDSBoard* board, struct boardStackElement** stack){
    struct boardStackElement* Element = (struct boardStackElement*)malloc(sizeof(struct boardStackElement));
    Element -> board = board;
    Element -> next = *stack;
    (*stack) = Element;  
}
// Remove boardStackElement from the topMovement of the stack
void popBoardFromStack(struct boardStackElement** stack){
    if(*stack != NULL){
        //printf("Element popped: %c\n",(*stack) -> idsBoard);
        struct boardStackElement* tempPtr = *stack;
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
void topBoardFromStack(struct boardStackElement* stack){
    if(stack != NULL){
    //printf("Element on topMovement: %c\n", stack -> idsBoard);
    }
    else{
        printf("The stack is empty.\n");
    }
}

void printBoardStackSize(struct boardStackElement* stack) {
    int count = 0;
    for (struct boardStackElement* s = stack; s != NULL; s = s->next) {
        count++;
    }
    printf("Stack size: %d\n", count);
}