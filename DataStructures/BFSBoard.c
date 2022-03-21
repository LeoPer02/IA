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
int inversionsBFS(short int grid[][4]){
    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = i; k < 4; k++){
                if(i == k){
                    for(int l = j; l < 4; l++){
                        if(grid[i][j] > grid[k][l] && grid[i][j] != 0 && grid[k][l] != 0){count++;}
                    }
                }else{
                    for(int l = 0; l < 4; l++){
                        if(grid[i][j] > grid[k][l] && grid[i][j] != 0 && grid[k][l] != 0){count++;}
                    }
                }
            }
        }
    }
    return count;
}

// Verifica se é possivel chegar de um estado ao outro
// Foi testada e funcionou em ambos os casos
bool possivelBFS(short int grid1[][4], short int grid2[][4]){
    short int inv1 = inversionsBFS(grid1);
    short int inv2 = inversionsBFS(grid2);
    short int vazio1, vazio2;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(grid1[i][j] == 0){
                vazio1 = i;
            }
            if(grid2[i][j] == 0){
                vazio2 = i;
            }
        }
    }
    if(((inv1 % 2 == 0) == (vazio1 % 2 == 0)) == ((inv2 % 2 == 0) == (vazio2 % 2 == 0))){
        return true;
    }else{
        return false;
    }
}

// Verifica se o estado atual é igual ao final, ou seja, se terminou
// Foi testada e funcionou em ambos os casos
bool compararBFS(short int grid1[][4], short int grid2[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(grid1[i][j] != grid2[i][j]){return false;}
        }
    }
    return true;
}

void setZeroLocationBFS(short int grid[4][4], short int zeroLocation[2]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                zeroLocation[0] = i;
                zeroLocation[1] = j;
                return;
            }
        }
    }
}

void copyMovementStackBFS(MovementElement** element, MovementElement** destination) {
    if ((*element) != NULL) {
        copyMovementStackBFS(&(*element)->next, destination);
        pushMovement((*element)->move, destination);
    }
}

BFSBoard* getNewBoardBFS(short int grid[][4]) {
    BFSBoard* newBoard = (BFSBoard*)malloc(sizeof(BFSBoard));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newBoard->grid[i][j] = grid[i][j];
        }
    }

    setZeroLocationBFS(grid, newBoard->zeroLocation);
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

    copyMovementStackBFS(&fatherBoard->movementStack, &newBoard->movementStack);
    pushMovement(movement, &newBoard->movementStack);

    setZeroLocationBFS(newBoard->grid, newBoard->zeroLocation);

    return newBoard;
}

