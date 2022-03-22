#ifndef IA_IDSBOARD_H
#define IA_IDSBOARD_H

#include <stdbool.h>
#include "MovementStack.h"

typedef struct idsBoard {
    short int grid[4][4];
    short int zeroLocation[2];
    MovementElement* movementStack;
    short int depth;
    bool sonsVisited[4];
} IDSBoard;

IDSBoard* getNewBoardIDS(short int grid[][4]);

void doMovementIDS(IDSBoard* fatherBoard, char movement, short int newGrid[4][4]);

IDSBoard* generateBoardIDS(IDSBoard* fatherBoard, char movement, short int newGrid[4][4]) ;

#endif //IA_IDSBOARD_H
