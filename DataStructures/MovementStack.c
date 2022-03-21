#include <stdio.h>
#include <stdlib.h>


// Struct to hold the data and the pointer to the next boardStackElement.
typedef struct movementElement{
    char move;
    struct movementElement* next;
} MovementElement;

// Append the new boardStackElement to the start of the stack
void pushMovement(char move, struct movementElement** stack){
    struct movementElement* element = (struct movementElement*)malloc(sizeof(struct movementElement));
    element -> move = move;
    element -> next = *stack;
    (*stack) = element;
    printf("");
}
// Remove boardStackElement from the top of the stack
void popMovement(struct movementElement** stack){
    if(*stack != NULL){
        //printf("Element popped: %c\n",(*stack) -> idsBoard);
        struct movementElement* tempPtr = *stack;
        *stack = (*stack) -> next;
        free(tempPtr);
    }
    else{
        printf("The stack is empty.\n");
    }
}
// Display the boardStackElement at the top of the stack
void topMovement(struct movementElement* stack){
    if(stack != NULL){
        //printf("Element on top: %c\n", stack -> idsBoard);
    }
    else{
        printf("The stack is empty.\n");
    }
}

int printMovementStackRec(struct movementElement* stack) {
    if (stack->move != 'x') {
        int depth = printMovementStackRec(stack->next);
        printf("%c ", stack->move);
        return depth + 1;
    }
    return 0;
}

void printMovementStack(struct movementElement* stack) {
    printf("Movements: ");
    int depth = printMovementStackRec(stack);
    printf("\nDepth: %i\n", depth);
}

void deleteMovementStack(struct movementElement** stack) {
    struct movementElement* tmp;
    while((*stack) != NULL) {
        tmp = (*stack);
        *stack = (*stack)->next;
        free(tmp);
    }
}