//
// Created by matheus on 22/03/2022.
//

#ifndef IA_BOARDUTILS_H
#define IA_BOARDUTILS_H

#include <stdbool.h>
#include <stddef.h>
#include "../DataStructures/MovementStack.h"

//Percorre a lista e verifica quantos elementos que estão depois de i são maiores que ele
//Foi testada e funcionou corretamente
int inversions(short int grid[][4]);

// Verifica se é possivel chegar de um estado ao outro
// Foi testada e funcionou em ambos os casos
bool possivel(short int grid1[][4], short int grid2[][4]);

// Verifica se o estado atual é igual ao final, ou seja, se terminou
// Foi testada e funcionou em ambos os casos
bool comparar(short int grid1[][4], short int grid2[][4]);

void setZeroLocation(short int grid[4][4], short int zeroLocation[2]);

void copyMovementStack(MovementElement** element, MovementElement** destination);

void copyArray(short int a[][4], short int b[][4]);


#endif //IA_BOARDUTILS_H
