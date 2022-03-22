//
// Created by matheus on 22/03/2022.
//

#ifndef IA_QUEUE_H
#define IA_QUEUE_H

struct QNode {
    short int data[4][4];
    struct QNode* next;
    struct Qnode* parent;
    short int x;
    short int y;
    char mov;
};


// A utility function to create a new linked list node.
struct QNode* newNodeQ(short int k[][4], struct Qnode* parent, short int x, short int y, char mov);

#endif //IA_QUEUE_H
