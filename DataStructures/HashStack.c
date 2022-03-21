#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Struct to hold the data and the pointer to the next boardStackElement.
typedef struct hashElement{
    unsigned long hash;
    struct hashElement* next;
} HashElement;

// Append the new boardStackElement to the start of the stack
void pushHash(unsigned long hash, struct hashElement** stack){
    struct hashElement* element = (struct hashElement*)malloc(sizeof(struct hashElement));
    element -> hash = hash;
    element -> next = *stack;
    (*stack) = element;
    printf("");
}
// Remove boardStackElement from the top of the stack
void popHash(struct hashElement** stack){
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
void topHash(struct hashElement* stack){
    if(stack != NULL){
        //printf("Element on top: %c\n", stack -> idsBoard);
    }
    else{
        printf("The stack is empty.\n");
    }
}

void deleteHashStack(struct hashElement** stack) {
    struct hashElement* tmp;
    while((*stack) != NULL) {
        tmp = (*stack);
        *stack = (*stack)->next;
        free(tmp);
    }
}

bool isHashInStack(struct hashElement** stack, unsigned long hash) {
    for (struct hashElement** s = stack; *s != NULL; s = &(*s)->next) {
        if ((*s)->hash == hash) {
            return true;
        }
    }
    return false;
}

unsigned long gridToHash(short int grid[4][4]) {
    unsigned long hash = 5381;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            hash = ((hash << 5) + hash) + grid[i][j];
        }
    }

    /*
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            hash = (31 * hash + grid[i][j]) % 256;
        }
    }
    return hash;
    */
}