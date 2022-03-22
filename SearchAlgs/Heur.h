//
// Created by matheus on 22/03/2022.
//

#ifndef IA_HEUR_H
#define IA_HEUR_H


#include <math.h>
#include <stdlib.h>

// Implementação das heuristicas
int heuristica(short int a[][4], short int goal[][4], short int heur);

// Sumatório dos numeros fora de lugar
int sum(short int a[][4], short int b[][4]);

// Manhattam Distance
int manh(short int a[][4], short int b[][4]);

#endif //IA_HEUR_H
