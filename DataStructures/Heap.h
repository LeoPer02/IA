//
// Created by matheus on 22/03/2022.
//

#ifndef IA_HEAP_H
#define IA_HEAP_H

#include <stdbool.h>

// Node
struct Hnode {
    short int data[4][4];

    // Lower values indicate higher priority
    int priority;

    struct Hnode* next;
    struct Hnode* parent;
    char mov;
    short int x;
    short int y;
    int depth;
};

bool isEmptyQ(struct Hnode** head);

// Function to Create A New Node
struct Hnode* newNode(short int a[][4] , int p, char mov1, int x1, int y1, struct Hnode* parent, int depth1);

bool contemQ(struct Hnode** head, short int a[][4]);

struct Hnode* peek(struct Hnode** head);

// Removes the element with the
// highest priority form the list
struct Hnode* popQ(struct Hnode** head);

// Function to push according to priority
void pushQ(struct Hnode** head, short int d[][4], int p, char mov, int x, int y, struct Hnode* parent, int depth);

// Na função ReturnPathQ o elemento no topo será necessáriamente o final pois quando
// o encontramos colocamo-lo na lista closed com custo -1, logo, obrigatoriamente
// ficará no topo. Após criar um apontador para o final, vamos iterando pelos parents
// ou seja, guardamos o movimento que gerou o estado atual e vamos para o seu pai
// progressivamente fazendo o mesmo ate chegarmos em temp->parent == NULL aka estado inicial
void returnPathQ(struct Hnode** stack);

#endif //IA_HEAP_H
