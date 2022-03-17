#include<stdio.h>
#include<stdlib.h>
#include "Game.c"

// Struct to hold the data and the pointer to the next element.
typedef struct element{ 
    Game* game; 
    struct element* next; 
} Element;
// Append the new element to the start of the stack
void push(Game* game, struct element** stack){
    struct element* Element = (struct element*)malloc(sizeof(struct element)); 
    Element -> game = game; 
    Element -> next = *stack;  
    (*stack) = Element;  
}
// Remove element from the top of the stack
void pop(struct element** stack){
    if(*stack != NULL){
        printf("Element popped: %c\n",(*stack) -> game);
        struct element* tempPtr = *stack;
        *stack = (*stack) -> next;
        free(tempPtr);
    }
    else{
        printf("The stack is empty.\n");
    }
}
// Display the element at the top of the stack
void top(struct element* stack){
    if(stack != NULL){
    printf("Element on top: %c\n", stack -> game);
    }
    else{
        printf("The stack is empty.\n");
    }
}