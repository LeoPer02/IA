
#include <malloc.h>
#include "../Utils/BoardUtils.h"

short int sizeHeap = 0;

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

bool isEmptyQ(struct Hnode** head)
{
    return (*head) == NULL;
}
 
// Function to Create A New Node
struct Hnode* newNode(short int a[][4] , int p, char mov1, int x1, int y1, struct Hnode* parent, int depth1)
{
    struct Hnode* temp = (struct Hnode*)malloc(sizeof(struct Hnode));
    copyArray(temp->data, a);
    temp->priority = p;
    temp->next = NULL;
    temp->parent = parent;
    temp->mov = mov1;
    temp->x = x1;
    temp->y = y1;
    temp->depth = depth1;
    
    return temp;
}

bool contemQ(struct Hnode** head, short int a[][4]){
    struct Hnode* temp = (*head);
        while(temp != NULL){
        if(comparar(temp->data, a)){
            return true;
        }
        temp = temp->next;
        }
    return false;
}

struct Hnode* peek(struct Hnode** head)
{
    return (*head);
}

// Removes the element with the
// highest priority form the list
struct Hnode* popQ(struct Hnode** head)
{
    struct Hnode* ptr = *head;
    (*head) = (*head)->next;
    sizeHeap--;
    return ptr;
}
 
// Function to push according to priority
void pushQ(struct Hnode** head, short int d[][4], int p, char mov, int x, int y, struct Hnode* parent, int depth)
{
    struct Hnode* start = (*head);
 
    // Create new Node
    struct Hnode* temp = newNode(d, p, mov, x, y, parent, depth);
    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if (*head == NULL || (*head)->priority > p) {
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
    sizeHeap++;
}


// Na função ReturnPathQ o elemento no topo será necessáriamente o final pois quando
// o encontramos colocamo-lo na lista closed com custo -1, logo, obrigatoriamente
// ficará no topo. Após criar um apontador para o final, vamos iterando pelos parents
// ou seja, guardamos o movimento que gerou o estado atual e vamos para o seu pai
// progressivamente fazendo o mesmo ate chegarmos em temp->parent == NULL aka estado inicial
void returnPathQ(struct Hnode** stack){
    int depth = 0;
    struct Hnode* tmp = *stack;
    char array[80];
    while(tmp->parent != NULL){
        array[depth] =  tmp->mov;
        tmp = tmp->parent;
        depth++;
    }
    printf("Movimentos: ");
    for(int i = depth-1; i >= 0; i--){
        printf("%c ", array[i]);
    }
    printf("\nDepth = %d\n", depth);
}
 