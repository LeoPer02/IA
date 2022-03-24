#include <stddef.h>
#include <malloc.h>
#include "../DataStructures/DFSBoardStack.h"
#include "Movimentos.h"

void dfs(short int start[][4], short int goal[][4]) {
    const char movementOptions[4] = {'u', 'r', 'd', 'l'};

    bool found;
    short int newGrid[4][4];
    int maxNodes = 0, stackSize = 0;

    DFSBoardStackElement *stack = (DFSBoardStackElement*)malloc(sizeof(DFSBoardStackElement));
    stack->board = getNewBoardDFS(start);
    stack->next = NULL;

    DFSBoard* newBoard;

    while (stack != NULL) {
        if (!stack->board->verified) {
            stack->board->verified = true;
            if (comparar(stack->board->grid, goal)) { // Checagem do topo da stack
                break;
            }
        }

        if (stack->board->depth < 19) {
            found = false; // Flag para interromper a iteração caso ache um movimento possível, necessário para o algoritmo funcionar como busca em profundidade
            for (int i = 0; i < 4 && !found; i++) {
                if (!stack->board->sonsVisited[i]) {
                    stack->board->sonsVisited[i] = true; // Junto com o if acima, impede a repetição de nós a serem explorados
                    if (isMovimentoPossivel(stack->board->zeroLocation[0], stack->board->zeroLocation[1],movementOptions[i], stack->board->movementStack->move)) {
                        doMovementDFS(stack->board, movementOptions[i], newGrid);
                        newBoard = generateBoardDFS(stack->board, movementOptions[i], newGrid);

                        pushDFSBoardToStack(newBoard, &stack);
                        stackSize++;
                        if (maxNodes < stackSize) {
                            maxNodes = stackSize;
                        }

                        found = true;
                    }
                }
            }
            if (!found) { // Sinal que este nó não possui mais filhos a serem explorados
                stackSize--;
                popDFSBoardFromStack(&stack);
            }
        } else {
            stackSize--;
            popDFSBoardFromStack(&stack);
        }
    }

    if (stack != NULL) {
        printf("Solution found!\n");
        printMovementStack(stack->board->movementStack);
        printf("Max number of nodes: %i\n", maxNodes);
    } else {
        printf("Something went wrong and the algorithm was unable to find a result.\n");
    }
}
