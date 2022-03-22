#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Movimentos.h"
#include "../Utils/BoardUtils.h"
#include "../DataStructures/Stack.h"
#include "../DataStructures/Queue.h"
#include "../DataStructures/Heap.h"

void BL(short int inicial[][4], short int final[][4]){
    short int zero[2];
    setZeroLocation(inicial, zero);
    struct Hnode* open; 
    push(inicial, 0,'x',&open, NULL, zero[0], zero[1]);
    struct Hnode* used = newNode(inicial, 0,'x', zero[0], zero[1], NULL, 0); 
    struct Hnode* temp;
    while(!isEmpty(&open)){
       temp = pop(&open);
        if(comparar(temp->data, final)){
            printf("mov:%c  depth:%d\n", temp->mov, temp->depth);
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("%d ", temp->data[i][j]);
            }
            printf("\n");
        }
        printf("------------------\n");
            pushQ(&used,temp->data,-1,temp->mov,temp->x,temp->y,temp->parent, temp->depth);
            returnPathQ(&used);
            return;
        }
        printf("mov:%c  depth:%d\n", temp->mov, temp->depth);
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("%d ", temp->data[i][j]);
            }
            printf("\n");
        }
        printf("------------------\n");
        if(isMovimentoPossivel(temp->x,temp->y,'d',temp->mov)){
            short int copy[4][4];
            copyArray(copy, temp->data);
            move_down(copy, temp->x, temp->y);
            if(!contemQ(&used, copy)){
                push(copy,0,'d',&open, temp, temp->x+1, temp->y);
                pushQ(&used, copy, 0, 'd', temp->x+1, temp->y, temp, temp->depth+1);
            }
        } 
        if(isMovimentoPossivel(temp->x,temp->y,'r',temp->mov)){
            short int copy[4][4];
            copyArray(copy, temp->data);
            move_right(copy, temp->x, temp->y);
            if(!contemQ(&used, copy)){
                push(copy,0,'r',&open, temp, temp->x, temp->y+1);
                 pushQ(&used, copy, 0, 'r', temp->x, temp->y+1, temp, temp->depth+1);
            }
        }
        if(isMovimentoPossivel(temp->x,temp->y,'l',temp->mov)){
            short int copy[4][4];
            copyArray(copy, temp->data);
            move_left(copy, temp->x, temp->y);
            if(!contemQ(&used, copy)){
                push(copy,0,'l',&open, temp, temp->x, temp->y-1);
                 pushQ(&used, copy, 0, 'd', temp->x, temp->y-1, temp, temp->depth+1);
            }
        }
        if(isMovimentoPossivel(temp->x,temp->y,'u',temp->mov)){
            short int copy[4][4];
            copyArray(copy, temp->data);
            move_up(copy, temp->x, temp->y);
            if(!contemQ(&used, copy)){
                push(copy,0,'u',&open, temp, temp->x-1, temp->y);
                 pushQ(&used, copy, 0, 'u', temp->x-1, temp->y, temp, temp->depth+1);
            }
        }
    }
    printf("Não encontrou resultado\n");
}








