//
// Created by matheus on 18/03/2022.
//

#ifndef IA_MOVIMENTOS_H
#define IA_MOVIMENTOS_H

#include <stdbool.h>

void move_right(short int grid1[][4],short int x, short int y);

void move_left(short int grid1[][4],short int x, short int y);

void move_up(short int grid1[][4], short int x, short int y);

void move_down(short int grid1[][4],short int x, short int y);

bool isMovimentoPossivel(short int x, short int y, char move, char last);

#endif //IA_MOVIMENTOS_H
