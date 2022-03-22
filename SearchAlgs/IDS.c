#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include "../DataStructures/BoardStack.h"
#include "../DataStructures/IDSBoard.h"
#include "../DataStructures/HashStack.h"
#include "../Utils/BoardUtils.h"
#include "Movimentos.h"

IDSBoard* dls(IDSBoard* start, short int goal[][4]);

IDSBoard* dls_with_repetition_checking(IDSBoard* start, short int goal[][4]);

IDSBoard* ids(short int start[][4], short int goal[][4]) {
    IDSBoard* startBoard, *foundBoard;

    int depth = 0;
    while(true) {
        startBoard = getNewBoardIDS(start);
        startBoard->depth = depth;

        foundBoard = dls(startBoard, goal);
        if (foundBoard != NULL) {
            return foundBoard;
        }

        depth++;
    }
}


IDSBoard* dls(IDSBoard* start, short int goal[][4]) {
    const char movementOptions[4] = {'u', 'r', 'd', 'l'};

    bool found;
    short int newGrid[4][4];

    BoardStackElement *stack = (BoardStackElement*)malloc(sizeof(BoardStackElement));
    stack->board = start;
    stack->next = NULL;

    IDSBoard* newBoard;

    while (stack != NULL) {
        if (stack->board->depth == 0 && comparar(stack->board->grid, goal)) { // Checagem do topo da stack
            return stack->board; // Se encontrado o objetivo, retorna o resultado
        } else if (stack->board->depth != 0) { // Caso possa buscar mais a fundo, fazer isto
            found = false;
            for (int i = 0; i < 4 && !found; i++) {
                if (!stack->board->sonsVisited[i]) {
                    stack->board->sonsVisited[i] = true;
                    if (isMovimentoPossivel(stack->board->zeroLocation[0], stack->board->zeroLocation[1], movementOptions[i], stack->board->movementStack->move)) {
                        doMovementIDS(stack->board, movementOptions[i], newGrid);
                        newBoard = generateBoardIDS(stack->board, movementOptions[i], newGrid);

                        pushBoardToStack(newBoard, &stack);

                        found = true;
                    }
                }
            }
            if (!found) {
                popBoardFromStack(&stack);
            }
        } else {
            popBoardFromStack(&stack);
        }
    }

    return NULL;
}

IDSBoard* dls_with_repetition_checking(IDSBoard* start, short int goal[][4]) {
    const char movementOptions[4] = {'u', 'r', 'd', 'l'};

    bool found;
    unsigned long newBoardHash;
    short int newGrid[4][4];

    BoardStackElement *stack = (BoardStackElement*)malloc(sizeof(BoardStackElement));
    stack->board = start;
    stack->next = NULL;

    HashElement *visitedStack = (HashElement*)malloc(sizeof(HashElement));
    IDSBoard* newBoard;

    while (stack != NULL) {
        if (stack->board->depth == 0 && comparar(stack->board->grid, goal)) { // Checagem do topo da stack
            return stack->board; // Se encontrado o objetivo, retorna o resultado
        } else if (stack->board->depth != 0) { // Caso possa buscar mais a fundo, fazer isto
            found = false;
            for (int i = 0; i < 4 && !found; i++) {
                if (!stack->board->sonsVisited[i]) {
                    stack->board->sonsVisited[i] = true;
                    if (isMovimentoPossivel(stack->board->zeroLocation[0], stack->board->zeroLocation[1], movementOptions[i], stack->board->movementStack->move)) {
                        doMovementIDS(stack->board, movementOptions[i], newGrid);
                        newBoardHash = gridToHash(newGrid);
                        if (!isHashInStack(&visitedStack, newBoardHash)) {
                            newBoard = generateBoardIDS(stack->board, movementOptions[i], newGrid);

                            pushHash(newBoardHash, &visitedStack);
                            pushBoardToStack(newBoard, &stack);

                            found = true;
                        }
                    }
                }
            }
            if (!found) {
                popBoardFromStack(&stack);
            }
        } else {
            popBoardFromStack(&stack);
        }
    }

    deleteHashStack(&visitedStack);
    return NULL;
}

