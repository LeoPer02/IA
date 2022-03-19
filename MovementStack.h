//
// Created by matheus on 18/03/2022.
//

#ifndef IA_MOVEMENTSTACK_H
#define IA_MOVEMENTSTACK_H

typedef struct movementElement{
    char move;
    struct movementElement* next;
} MovementElement;

// Append the new boardElement to the start of the stack
void pushMovement(char move, struct movementElement** stack);
// Remove boardElement from the topMovement of the stack
void popMovement(struct movementElement** stack);
// Display the boardElement at the topMovement of the stack
void topMovement(struct movementElement* stack);

void printMovementStack(struct movementElement* stack);

#endif //IA_MOVEMENTSTACK_H
