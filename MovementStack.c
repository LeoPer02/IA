#include <stdio.h>
#include <stdlib.h>


// Struct to hold the data and the pointer to the next boardElement.
typedef struct movementElement{
    char move;
    struct movementElement* next;
} MovementElement;

// Append the new boardElement to the start of the stack
void pushMovement(char move, struct movementElement** stack){
    struct movementElement* element = (struct movementElement*)malloc(sizeof(struct movementElement));
    element -> move = move;
    element -> next = *stack;
    (*stack) = element;
    printf("");
}
// Remove boardElement from the top of the stack
void popMovement(struct movementElement** stack){
    if(*stack != NULL){
        //printf("Element popped: %c\n",(*stack) -> board);
        struct movementElement* tempPtr = *stack;
        *stack = (*stack) -> next;
        free(tempPtr);
    }
    else{
        printf("The stack is empty.\n");
    }
}
// Display the boardElement at the top of the stack
void topMovement(struct movementElement* stack){
    if(stack != NULL){
        //printf("Element on top: %c\n", stack -> board);
    }
    else{
        printf("The stack is empty.\n");
    }
}

void printMovementStackRec(struct movementElement* stack) {
    if (stack->move != 'x') {
        printMovementStackRec(stack->next);
        printf("%c ", stack->move);
    }
}

void printMovementStack(struct movementElement* stack) {
    printf("Movements: ");
    printMovementStackRec(stack);
}