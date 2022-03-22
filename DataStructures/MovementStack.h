//
// Created by matheus on 18/03/2022.
//

#ifndef IA_MOVEMENTSTACK_H
#define IA_MOVEMENTSTACK_H

typedef struct movementElement{
    char move;
    struct movementElement* next;
} MovementElement;

// Append the new boardStackElement to the start of the stack
void pushMovement(char move, struct movementElement** stack);
// Remove boardStackElement from the topMovement of the stack
void popMovement(struct movementElement** stack);
// Display the boardStackElement at the topMovement of the stack
void topMovement(struct movementElement* stack);

void printMovementStack(struct movementElement* stack);

void deleteMovementStack(struct movementElement** stack);

#endif //IA_MOVEMENTSTACK_H
