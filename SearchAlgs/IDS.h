//
// Created by matheus on 18/03/2022.
//

#ifndef IA_IDS_H
#define IA_IDS_H

#include <stdbool.h>
#include "../DataStructures/Board.h"
#include "../movimentos.h"


Board* dls(Board* start, short int goal[][4]);

Board* ids(short int start[][4], short int goal[][4]);

#endif //IA_IDS_H
