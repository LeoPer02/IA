#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "movimentos.h"
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
int inversions(short int grid[][4]){
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
bool possivel(short int grid1[][4], short int grid2[][4]){
    short int inv1 = inversions(grid1);
    short int inv2 = inversions(grid2);
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
bool comparar(short int grid1[][4], short int grid2[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(grid1[i][j] != grid2[i][j]){return false;}
        }
    }
    return true;
}

void setZeroLocation(short int grid[4][4], short int zeroLocation[2]) {
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

void copyMovementStack(MovementElement** element, MovementElement** destination) {
    if ((*element) != NULL) {
        copyMovementStack(&(*element)->next, destination);
        pushMovement((*element)->move, destination);
    }
}

Board* getNewBoard(short int grid[][4]) {
    Board* newBoard = (Board*)malloc(sizeof(Board));

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

Board* getNewBoardByMovement(Board* fatherBoard, char movement) {
    Board* newBoard = (Board*)malloc(sizeof(Board));

    memcpy(newBoard->grid, fatherBoard->grid, sizeof(fatherBoard->grid));
    switch (movement) {
        case 'u':
            move_up(newBoard->grid, fatherBoard->zeroLocation[0], fatherBoard->zeroLocation[1]);
            break;
        case 'r':
            move_right(newBoard->grid, fatherBoard->zeroLocation[0], fatherBoard->zeroLocation[1]);
            break;
        case 'd':
            move_down(newBoard->grid, fatherBoard->zeroLocation[0], fatherBoard->zeroLocation[1]);
            break;
        case 'l':
            move_left(newBoard->grid, fatherBoard->zeroLocation[0], fatherBoard->zeroLocation[1]);
            break;
        default:
            printf("Movimento inválido");
            return NULL;
    }

    newBoard->depth = fatherBoard->depth;

    copyMovementStack(&fatherBoard->movementStack, &newBoard->movementStack);
    pushMovement(movement, &newBoard->movementStack);

    setZeroLocation(newBoard->grid, newBoard->zeroLocation);

    for (int i = 0; i < 4; i++)
        newBoard->sonsVisited[i] = false;

    return newBoard; 
}

