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

//Percorre a lista e verifica quantos elementos que estão depois de i são maiores que ele
//Foi testada e funcionou corretamente
int inversionsIDS(short int grid[][4]);

// Verifica se é possivel chegar de um estado ao outro
// Foi testada e funcionou em ambos os casos
bool possivelIDS(short int grid1[][4], short int grid2[][4]);

// Verifica se o estado atual é igual ao final, ou seja, se terminou
// Foi testada e funcionou em ambos os casos
bool compararIDS(short int grid1[][4], short int grid2[][4]);

void setZeroLocationIDS(short int grid[4][4]);

IDSBoard* getNewBoardIDS(short int grid[][4]);

void doMovementIDS(IDSBoard* fatherBoard, char movement, short int newGrid[4][4]);

IDSBoard* generateBoardIDS(IDSBoard* fatherBoard, char movement, short int newGrid[4][4]) ;

#endif //IA_IDSBOARD_H
