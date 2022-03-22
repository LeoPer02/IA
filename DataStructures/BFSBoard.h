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

BFSBoard* getNewBoardBFS(short int grid[][4]);

void doMovementBFS(BFSBoard* fatherBoard, char movement, short int newGrid[4][4]);

BFSBoard* generateBoardBFS(BFSBoard* fatherBoard, char movement, short int newGrid[4][4]);



#endif //IA_BFSBOARD_H
