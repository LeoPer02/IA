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

DFSBoard* getNewBoardDFS(short int grid[][4]) {
    DFSBoard* newBoard = (DFSBoard*)malloc(sizeof(DFSBoard));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newBoard->grid[i][j] = grid[i][j];
        }
    }

    setZeroLocation(grid, newBoard->zeroLocation);
    newBoard->movementStack = (MovementElement*)malloc(sizeof(MovementElement));
    newBoard->movementStack->move = 'x';
    newBoard->depth = 0;
    newBoard->verified = false;
    for (int i = 0; i < 4; i++)
        newBoard->sonsVisited[i] = false;

    return newBoard;
}

void doMovementDFS(DFSBoard* fatherBoard, char movement, short int newGrid[4][4]) {
    memcpy(newGrid, fatherBoard->grid, sizeof(fatherBoard->grid));
    switch (movement) {
        case 'u':
            move_up(newGrid, fatherBoard->zeroLocation[0], fatherBoard->zeroLocation[1]);
            break;
        case 'r':
            move_right(newGrid, fatherBoard->zeroLocation[0], fatherBoard->zeroLocation[1]);
            break;
        case 'd':
            move_down(newGrid, fatherBoard->zeroLocation[0], fatherBoard->zeroLocation[1]);
            break;
        case 'l':
            move_left(newGrid, fatherBoard->zeroLocation[0], fatherBoard->zeroLocation[1]);
            break;
        default:
            printf("Movimento inválido");
            break;
    }
}

DFSBoard* generateBoardDFS(DFSBoard* fatherBoard, char movement, short int newGrid[4][4]) {
    DFSBoard* newBoard = (DFSBoard*)malloc(sizeof(DFSBoard));

    memcpy(newBoard->grid, newGrid, sizeof(newBoard->grid));
    newBoard->verified = false;

    copyMovementStack(&fatherBoard->movementStack, &newBoard->movementStack);
    pushMovement(movement, &newBoard->movementStack);

    newBoard->depth = fatherBoard->depth + 1;

    setZeroLocation(newBoard->grid, newBoard->zeroLocation);

    for (int i = 0; i < 4; i++)
        newBoard->sonsVisited[i] = false;

    return newBoard;
}

