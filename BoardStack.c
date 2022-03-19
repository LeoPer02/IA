#include <stdio.h>
#include <stdlib.h>
#include "Board.h"


// Struct to hold the data and the pointer to the next boardElement.
typedef struct boardElement{
    Board* board;
    struct boardElement* next;
} BoardElement;

// Append the new boardElement to the start of the stack
void pushBoard(Board* board, struct boardElement** stack){
    struct boardElement* Element = (struct boardElement*)malloc(sizeof(struct boardElement));
    Element -> board = board;
    Element -> next = *stack;
    (*stack) = Element;  
}
// Remove boardElement from the topMovement of the stack
void popBoard(struct boardElement** stack){
    if(*stack != NULL){
        //printf("Element popped: %c\n",(*stack) -> board);
        struct boardElement* tempPtr = *stack;
        *stack = (*stack) -> next;
        free(tempPtr);
    }
    else{
        printf("The stack is empty.\n");
    }
}
// Display the boardElement at the topMovement of the stack
void topBoard(struct boardElement* stack){
    if(stack != NULL){
    //printf("Element on topMovement: %c\n", stack -> board);
    }
    else{
        printf("The stack is empty.\n");
    }
}

void printBoardStackSize(struct boardElement* stack) {
    int count = 0;
    for (struct boardElement* s = stack; s != NULL; s = s->next) {
        count++;
    }
    printf("Stack size: %d\n", count);
}