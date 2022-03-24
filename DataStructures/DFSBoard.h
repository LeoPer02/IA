//
// Created by matheus on 24/03/2022.
//

#ifndef IA_DFSBOARD_H
#define IA_DFSBOARD_H

#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "../SearchAlgs/Movimentos.h"
#include "../Utils/BoardUtils.h"
#include "MovementStack.h"

typedef struct dfsBoard {
    short int grid[4][4];
    short int zeroLocation[2];
    short int depth;
    MovementElement* movementStack;
    bool verified;
    bool sonsVisited[4];
} DFSBoard;

DFSBoard* getNewBoardDFS(short int grid[][4]);

void doMovementDFS(DFSBoard* fatherBoard, char movement, short int newGrid[4][4]);

DFSBoard* generateBoardDFS(DFSBoard* fatherBoard, char movement, short int newGrid[4][4]);

#endif //IA_DFSBOARD_H
