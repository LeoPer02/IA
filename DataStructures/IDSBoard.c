#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "../SearchAlgs/Movimentos.h"
#include "../Utils/BoardUtils.h"
#include "MovementStack.h"


typedef struct idsBoard {
    short int grid[4][4];
    short int zeroLocation[2];
    MovementElement* movementStack;
    short int depth;
    bool sonsVisited[4];
} IDSBoard;

IDSBoard* getNewBoardIDS(short int grid[][4]) {
    IDSBoard* newBoard = (IDSBoard*)malloc(sizeof(IDSBoard));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newBoard->grid[i][j] = grid[i][j];
        }
    }

    setZeroLocation(grid, newBoard->zeroLocation);
    newBoard->movementStack = (MovementElement*)malloc(sizeof(MovementElement));
    newBoard->movementStack->move = 'x';
    for (int i = 0; i < 4; i++)
        newBoard->sonsVisited[i] = false;
    
    return newBoard;
}

void doMovementIDS(IDSBoard* fatherBoard, char movement, short int newGrid[4][4]) {
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

IDSBoard* generateBoardIDS(IDSBoard* fatherBoard, char movement, short int newGrid[4][4]) {
    IDSBoard* newBoard = (IDSBoard*)malloc(sizeof(IDSBoard));

    memcpy(newBoard->grid, newGrid, sizeof(newBoard->grid));
    newBoard->depth = fatherBoard->depth - 1;

    copyMovementStack(&fatherBoard->movementStack, &newBoard->movementStack);
    pushMovement(movement, &newBoard->movementStack);

    setZeroLocation(newBoard->grid, newBoard->zeroLocation);

    for (int i = 0; i < 4; i++)
        newBoard->sonsVisited[i] = false;

    return newBoard; 
}

