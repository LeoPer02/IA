
#include <malloc.h>
#include <stdbool.h>
#include "../Utils/BoardUtils.h"

// A linked list (LL) node to store a queue entry
struct QNode {
    short int data[4][4];
    struct QNode* next;
    struct Qnode* parent;
    short int x;
    short int y;
    char mov;
};
 
 
// A utility function to create a new linked list node.
struct QNode* newNodeQ(short int k[][4], struct Qnode* parent, short int x, short int y, char mov)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    copyArray(temp->data, k);
    temp->next = NULL;
    temp->parent = parent;
    temp->x = x;
    temp->y = y;
    temp->mov = mov;
    return temp;
}