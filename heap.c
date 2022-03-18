#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heur.c"

void copyArray(short int a[][4], short int b[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = b[i][j];
        }
    }
}


// Node
struct Hnode {
    short int data[4][4];
 
    // Lower values indicate higher priority
    int priority;
 
    struct Hnode* next;
    char mov;
    int x;
    int y;
 
};
 
// Function to Create A New Node
struct Hnode* newNode(short int a[][4] , int p, char mov1, int x1, int y1)
{
    struct Hnode* temp = (struct Hnode*)malloc(sizeof(struct Hnode));
    copyArray(temp->data, a);
    temp->priority = p;
    temp->next = NULL;
    temp->mov = mov1;
    temp->x = x1;
    temp->y = y1;
 
    return temp;
}
 

struct Hnode* peek(struct Hnode** head)
{
    return (*head);
}

// Removes the element with the
// highest priority form the list
void popQ(struct Hnode** head)
{
    struct Hnode* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
 
// Function to push according to priority
void pushQ(struct Hnode** head, short int d[][4], int p, char mov, int x, int y)
{
    struct Hnode* start = (*head);
 
    // Create new Node
    struct Hnode* temp = newNode(d, p, mov, x, y);
 
    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority > p) {
 
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {
 
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
            start->next->priority < p) {
            start = start->next;
        }
 
        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}
 
// Verificar se está vazia
bool isEmptyQ(struct Hnode** head)
{
    return (*head) == NULL;
}
 
/*
int main()
{
  short int grid1[4][4], grid2[4][4], grid3[4][4], grid4[4][4];                                      // short int para minimizar espaço em memória
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%hd", &grid1[i][j]);
        }                                                                // Ler inteiros para dentro do array grid
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%hd", &grid2[i][j]);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%hd", &grid3[i][j]);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%hd", &grid4[i][j]);
        }
    } 
    // Create a Priority Queue
    // Adicionar as grids manualmente. Valores especificos de prioridade para efeitos de teste
    struct Hnode* pq = newNode(grid1, manh(grid1, grid2) + sum(grid1, grid2), 'x', 0, 0);
    pushQ(&pq, grid2, manh(grid2, grid2) + sum(grid2, grid2), 'x', 0, 0);
    pushQ(&pq, grid3, 0, 'x', 0, 0);
    pushQ(&pq, grid4, 1, 'x', 0, 0);
 
    while (!isEmptyQ(&pq)) {
        for(int i = 0; i < 4; i++){
          for(int j = 0; j < 4; j++){
            printf("%d ", pq->data[i][j]);
          }
          printf("\n");
        }
        popQ(&pq);
    }
 
    return 0;
}
*/