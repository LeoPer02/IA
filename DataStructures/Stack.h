//
// Created by matheus on 22/03/2022.
//

#ifndef IA_STACK_H
#define IA_STACK_H


#include <stdbool.h>

// Nós da linked list usada na stack
struct node
{
    short int data[4][4];
    struct Hnode* next;
    char mov;
    short int cost;
    struct Hnode* parent;
};

// Verificar se a Stack está vazia
bool isEmpty(struct Hnode** stack);
// Fazer push de um elemento para a Stack
void push(short int grid[][4], short int cost1, char mov1, struct Hnode** stack, struct Hnode* parent, short int x, short int y);
// Dá pop/remove o elemento do topo da stack
struct Hnode* pop(struct Hnode** stack);
// Mostra o elemento do topo sem o remover
struct Hnode* top(struct Hnode** stack);

bool contemS(struct Hnode** stack, short int a[][4]);

void returnPath(struct Hnode** stack);

#endif //IA_STACK_H
