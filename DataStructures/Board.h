#ifndef IA_BOARD_H
#define IA_BOARD_H

#include <stdbool.h>
#include "MovementStack.h"

typedef struct board {
    short int grid[4][4];
    short int zeroLocation[2];
    MovementElement* movementStack;
    short int depth;
    bool sonsVisited[4];
} Board;

//Percorre a lista e verifica quantos elementos que estão depois de i são maiores que ele
//Foi testada e funcionou corretamente
int inversions(short int grid[][4]);

// Verifica se é possivel chegar de um estado ao outro
// Foi testada e funcionou em ambos os casos
bool possivel(short int grid1[][4], short int grid2[][4]);

// Verifica se o estado atual é igual ao final, ou seja, se terminou
// Foi testada e funcionou em ambos os casos
bool comparar(short int grid1[][4], short int grid2[][4]);

void setZeroLocation(short int grid[4][4]);

Board* getNewBoard(short int grid[][4]);

Board* getNewBoardByMovement(Board* fatherBoard, char movement);

#endif //IA_BOARD_H
