#include <stddef.h>
#include <malloc.h>
#include "../DataStructures/BoardList.h"
#include "../DataStructures/HashStack.h"
#include "../Utils/BoardUtils.h"

void bfs(short int start[][4], short int goal[][4]) {
    const char movementOptions[4] = {'u', 'r', 'd', 'l'};

    BFSBoard* startBoard = getNewBoardBFS(start);
    BFSBoard* newBoard;

    short int newGrid[4][4];
    int listSize = 0, maxNodes = 0;

    BoardListElement *list = (BoardListElement*)malloc(sizeof(BoardListElement));
    list->board = startBoard;
    list->next = NULL;

    while (list != NULL) {
        if (comparar(list->board->grid, goal)) { // Checagem do topo da list
            break; // Se encontrado o objetivo, retorna o resultado
        }
        for (int i = 0; i < 4; i++) {
            if (isMovimentoPossivel(list->board->zeroLocation[0], list->board->zeroLocation[1], movementOptions[i], list->board->movementStack->move)) {
                doMovementBFS(list->board, movementOptions[i], newGrid);

                newBoard = generateBoardBFS(list->board, movementOptions[i], newGrid);
                pushBoardToList(newBoard, &list);
                listSize++;
                if (listSize > maxNodes) {
                    maxNodes = listSize;
                }
            }
        }
        popBoardFromList(&list);
        listSize--;
    }

    if (list != NULL) {
        printf("Solution found!\n");
        printMovementStack(list->board->movementStack);
        printf("Max number of nodes: %i\n", maxNodes);
    } else {
        printf("Something went wrong and the algorithm was unable to find a result.\n");
    }
}
