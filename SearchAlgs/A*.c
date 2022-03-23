#include <stdio.h>

#include "../SearchAlgs/Movimentos.h"
#include "../Utils/BoardUtils.h"
#include "../DataStructures/Heap.h"
#include "../SearchAlgs/Heur.h"
#include "../Utils/Timer.h"

//Algoritmo A*.c
// Este algoritmo usa 2 priority queues (PQ) para guardar os novos visitados (lista closed) e os que vão ser expandidos (lista open)

void A_star(short int inicial[][4], short int final[][4], short int Nheur){ 
    short int zero[2];                                                                                        // Array para guardar a posição do zero
    setZeroLocation(inicial, zero);                                                                                  // Encontrar o Zero e meter no array zero
    struct Hnode* open = newNode(inicial, heuristica(inicial, final, Nheur),'x', zero[0], zero[1], NULL, 0);  //Inicializar a lista Open inserindo o estado inicial
    struct Hnode* closed = newNode(inicial, heuristica(inicial, final, Nheur),'x', zero[0], zero[1], NULL, 0); // Inicializar a lista Closed inserindo o estado final 
    struct Hnode* temp;
    while(!isEmptyQ(&open)){
        
        temp = popQ(&open);                                                                            // Apontador para o elemento que foi retirado do topo da PQ
        if(comparar(temp->data, final)){                                                               // Caso seja o final:                            
            pushQ(&closed, temp->data, -1, temp->mov, temp->x, temp->y, temp->parent, temp->depth);    // Colocar o temp na lista closed com priority -1 (para ficar no topo)
            returnPathQ(&closed);                                                                      // Invocar funçao que retorna o caminho juntamente com a profundidade
            return;
        }

        //Cada 1 dos 4 if's seguintes faz exatamente o mesmo, mas para cada movimento

        if(isMovimentoPossivel(temp->x, temp->y, 'u', temp->mov)){                                     // Caso o movimento seja possivel de ser realizado:
            short int copy[4][4];                                                           // Criar um array(copy) para guardar o novo estado
            copyArray(copy, temp->data);                                                    // Colocalo igual ao pai
            move_up(copy, temp->x, temp->y);                                                // Aplicar o movimento, neste caso Up
            int heur = temp->depth+1 + heuristica(copy, final, Nheur);                      // Calcular o custo ((Depth do pai + 1) + Heuristic)
            if(!contemQ(&closed, copy)){                                                    // Caso este nó nunca tenha sido criado antes:
                pushQ(&open,copy, heur, 'u', temp->x -1, temp->y, temp, temp->depth+1);     // Enviálo para a lista open para poder eventualmente ser expandido
            }
        }
        if(isMovimentoPossivel(temp->x, temp->y, 'r', temp->mov)){
            short int copy[4][4];
            copyArray(copy, temp->data);
            move_right(copy, temp->x, temp->y);
            int heur = temp->depth+1 + heuristica(copy, final, Nheur);
            if(!contemQ(&closed, copy)){
                pushQ(&open,copy, heur, 'r', temp->x, temp->y+1, temp, temp->depth+1);
            }
        }
        if(isMovimentoPossivel(temp->x, temp->y, 'd', temp->mov)){
            short int copy[4][4];
            copyArray(copy, temp->data);
            move_down(copy, temp->x, temp->y);
            int heur = temp->depth+1 + heuristica(copy, final, Nheur);
            if(!contemQ(&closed, copy)){
                pushQ(&open,copy, heur, 'd', temp->x + 1, temp->y, temp, temp->depth+1);
            }
        }
        if(isMovimentoPossivel(temp->x, temp->y, 'l', temp->mov)){
            short int copy[4][4];
            copyArray(copy, temp->data);
            move_left(copy, temp->x, temp->y);
            int heur = temp->depth+1 + heuristica(copy, final, Nheur);
            if(!contemQ(&closed, copy)){
                pushQ(&open,copy, heur, 'l', temp->x, temp->y-1, temp, temp->depth+1);
            }
        }
        pushQ(&closed, temp->data, temp->priority, temp->mov, temp->x, temp->y, temp->parent, temp->depth);

    }
    printf("Resultado não encontrado!\n");
}
