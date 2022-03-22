#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "../SearchAlgs/Movimentos.h"
#include "MovementStack.h"
#include "../Utils/BoardUtils.h"


typedef struct BFSBoard {
    short int grid[4][4];
    short int zeroLocation[2];
    MovementElement* movementStack;
} BFSBoard;

BFSBoard* getNewBoardBFS(short int grid[][4]) {
    BFSBoard* newBoard = (BFSBoard*)malloc(sizeof(BFSBoard));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newBoard->grid[i][j] = grid[i][j];
        }
    }

    setZeroLocation(grid, newBoard->zeroLocation);
    newBoard->movementStack = (MovementElement*)malloc(sizeof(MovementElement));
    newBoard->movementStack->move = 'x';

    return newBoard;
}

void doMovementBFS(BFSBoard* fatherBoard, char movement, short int newGrid[4][4]) {
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

BFSBoard* generateBoardBFS(BFSBoard* fatherBoard, char movement, short int newGrid[4][4]) {
    BFSBoard* newBoard = (BFSBoard*)malloc(sizeof(BFSBoard));

    memcpy(newBoard->grid, newGrid, sizeof(newBoard->grid));

    copyMovementStack(&fatherBoard->movementStack, &newBoard->movementStack);
    pushMovement(movement, &newBoard->movementStack);

    setZeroLocation(newBoard->grid, newBoard->zeroLocation);

    return newBoard;
}

