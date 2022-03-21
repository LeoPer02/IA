//
// Created by matheus on 21/03/2022.
//

#ifndef IA_BFSBOARD_H
#define IA_BFSBOARD_H

#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "../SearchAlgs/Movimentos.h"
#include "MovementStack.h"


typedef struct BFSBoard {
    short int grid[4][4];
    short int zeroLocation[2];
    MovementElement* movementStack;
} BFSBoard;

//Percorre a lista e verifica quantos elementos que estão depois de i são maiores que ele
//Foi testada e funcionou corretamente
int inversionsBFS(short int grid[][4]);
// Verifica se é possivel chegar de um estado ao outro
// Foi testada e funcionou em ambos os casos
bool possivelBFS(short int grid1[][4], short int grid2[][4]);
// Verifica se o estado atual é igual ao final, ou seja, se terminou
// Foi testada e funcionou em ambos os casos
bool compararBFS(short int grid1[][4], short int grid2[][4]);

void setZeroLocationBFS(short int grid[4][4], short int zeroLocation[2]);

void copyMovementStackBFS(MovementElement** element, MovementElement** destination);

BFSBoard* getNewBoardBFS(short int grid[][4]);

void doMovementBFS(BFSBoard* fatherBoard, char movement, short int newGrid[4][4]);

BFSBoard* generateBoardBFS(BFSBoard* fatherBoard, char movement, short int newGrid[4][4]);



#endif //IA_BFSBOARD_H
