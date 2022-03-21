//
// Created by matheus on 20/03/2022.
//

#ifndef IA_HASHSTACK_H
#define IA_HASHSTACK_H

typedef struct hashElement{
    unsigned long hash;
    struct hashElement* next;
} HashElement;

// Append the new boardStackElement to the start of the stack
void pushHash(unsigned long hash, struct hashElement** stack);
// Remove boardStackElement from the top of the stack
void popHash(struct hashElement** stack);
// Display the boardStackElement at the top of the stack
void topHash(struct hashElement* stack);

void printHashStackRec(struct hashElement* stack);

void printHashStack(struct hashElement* stack);

void deleteHashStack(struct hashElement** stack);

bool isHashInStack(struct hashElement** stack, unsigned long hash);

unsigned long gridToHash(short int grid[4][4]);

#endif //IA_HASHSTACK_H
