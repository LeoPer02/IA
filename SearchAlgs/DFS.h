//
// Created by matheus on 24/03/2022.
//

#ifndef IA_DFS_H
#define IA_DFS_H

#include <stddef.h>
#include <malloc.h>
#include "../DataStructures/DFSBoardStack.h"
#include "../DataStructures/DFSBoard.h"
#include "../DataStructures/HashStack.h"
#include "../Utils/BoardUtils.h"
#include "Movimentos.h"

void dfs(short int start[][4], short int goal[][4]);

#endif //IA_DFS_H
