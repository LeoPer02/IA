#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include "../DataStructures/BoardList.h"
#include "../DataStructures/BFSBoard.h"
#include "../DataStructures/HashStack.h"

BFSBoard* bfs(short int start[][4], short int goal[][4]) {
    const char movementOptions[4] = {'u', 'r', 'd', 'l'};

    BFSBoard* startBoard = getNewBoardBFS(start);
    BFSBoard* newBoard;

    unsigned long newBoardHash;
    short int newGrid[4][4];

    BoardListElement *list = (BoardListElement*)malloc(sizeof(BoardListElement));
    list->board = startBoard;
    list->next = NULL;

    HashElement *visitedStack = (HashElement*)malloc(sizeof(HashElement));
    pushHash(gridToHash(start), &visitedStack);

    while (list != NULL) {
        if (compararBFS(list->board->grid, goal)) { // Checagem do topo da list
            printBoardListSize(list);
            return list->board; // Se encontrado o objetivo, retorna o resultado
        }
        for (int i = 0; i < 4; i++) {
            if (isMovimentoPossivel(movementOptions[i], list->board->movementStack->move, list->board->zeroLocation)) {
                doMovementBFS(list->board, movementOptions[i], newGrid);
                newBoardHash = gridToHash(newGrid);
                if (!isHashInStack(&visitedStack, newBoardHash)) {
                    pushHash(newBoardHash, &visitedStack);

                    newBoard = generateBoardBFS(list->board, movementOptions[i], newGrid);
                    pushBoardToList(newBoard, &list);
                }
            }
        }
        popBoardFromList(&list);
    }
    deleteHashStack(&visitedStack);
    return NULL;
}
