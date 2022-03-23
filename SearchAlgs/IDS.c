#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include <time.h>

#include "../DataStructures/BoardStack.h"
#include "../DataStructures/IDSBoard.h"
#include "../DataStructures/HashStack.h"
#include "../Utils/BoardUtils.h"
#include "../Utils/Timer.h"
#include "Movimentos.h"

IDSBoard* dls(IDSBoard* start, short int goal[][4]);

void ids(short int start[][4], short int goal[][4]) {
    IDSBoard* startBoard, *foundBoard;
    int depth = 0;
    bool flag = true;

    while(flag) {
        startBoard = getNewBoardIDS(start);
        startBoard->depth = depth;

        foundBoard = dls(startBoard, goal);
        if (foundBoard != NULL) {
            flag = false;
        }

        depth++;
    }

    printf("Solution found!\n");
    printMovementStack(foundBoard->movementStack);
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
            found = false; // Flag para interromper a iteração caso ache um movimento possível, necessário para o algoritmo funcionar como busca em profundidade
            for (int i = 0; i < 4 && !found; i++) {
                if (!stack->board->sonsVisited[i]) {
                    stack->board->sonsVisited[i] = true; // Junto com o if acima, impede a repetição de nós a serem explorados
                    if (isMovimentoPossivel(stack->board->zeroLocation[0], stack->board->zeroLocation[1], movementOptions[i], stack->board->movementStack->move)) {
                        doMovementIDS(stack->board, movementOptions[i], newGrid);
                        newBoard = generateBoardIDS(stack->board, movementOptions[i], newGrid);
                        pushBoardToStack(newBoard, &stack);

                        found = true;
                    }
                }
            }
            if (!found) { // Sinal que este nó não possui mais filhos a serem explorados
                popBoardFromStack(&stack);
            }
        } else {
            popBoardFromStack(&stack);
        }
    }

    return NULL;
}
