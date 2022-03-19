#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include "BoardStack.h"
#include "Board.h"
#include "movimentos.h"


Board* dls(Board* start, short int goal[][4]);

Board* ids(short int start[][4], short int goal[][4]) {
    Board* startBoard, *foundBoard;

    int depth = 0;
    while(true) {
        startBoard = getNewBoard(start);
        startBoard->depth = depth;

        foundBoard = dls(startBoard, goal);
        if (foundBoard != NULL) {
            return foundBoard;
        }

        depth++;
    }
}

Board* dls(Board* start, short int goal[][4]) {
    char movementOptions[4] = {'u', 'r', 'd', 'l'};
    bool found;

    BoardElement *stack = (BoardElement*)malloc(sizeof(BoardElement));
    stack->board = start;
    stack->next = NULL;

    while (stack != NULL) {
        if (stack->board->depth == 0 && comparar(stack->board->grid, goal)) { // Checagem do topo da stack
            return stack->board; // Se encontrado o objetivo, retorna o resultado
        } else if (stack->board->depth != 0) { // Caso possa buscar mais a fundo, fazer isto
            found = false;
            for (int i = 0; i < 4 && !found; i++) {
                if (!stack->board->sonsVisited[i]) {
                    stack->board->sonsVisited[i] = true;
                    if (isMovimentoPossivel(movementOptions[i], stack->board->movementStack->move, stack->board->zeroLocation)) {
                        Board* newBoard = getNewBoardByMovement(stack->board, movementOptions[i]);
                        newBoard->depth = stack->board->depth - 1;
                        pushBoard(newBoard, &stack);
                        found = true;
                    }
                }
            }
            if (!found)
                popBoard(&stack);
        } else {
            popBoard(&stack);
        }
    }

    return NULL;
}
