#include <stdio.h>
#include <time.h>

#include "./SearchAlgs/A*.h"
#include "./SearchAlgs/Guloso.h"
#include "./SearchAlgs/IDS.h"
#include "./SearchAlgs/BFS.h"
#include "./SearchAlgs/BP.h"
#include "./Utils/BoardUtils.h"
#include "./Utils/Timer.h"


short int escolherHeuristica() {
    printf("Por favor escolha a heuristica:\n");
    printf("Manhattan (Recomendada) -> 1\n");
    printf("Sumatório               -> 2\n");
    short int heur;
    scanf("%hd", &heur);
    while(heur != 1 && heur != 2){
        printf("Resposta Inválida, por favor escolha uma das seguintes opções:\n");
        printf("Manhattan (Recomendada)-> 1\n");
        printf("Sumatório              -> 2\n");
        scanf("%hd", &heur);
    }
    return heur;
}

void readInput(short int inicial[4][4], short int final[4][4]) {
    printf("Introduza o estado inicial e final, respetivamente:\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%hd", &inicial[i][j]);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%hd", &final[i][j]);
        }
    }
}

short int readAlgOpcao() {
    // short int para minimizar espaço em memória
    printf("Por favor escolha o método de pesquisa que deseja utilizar:\n");
    printf("Busca em Profundidade Iterativa -> 1\n");
    printf("Algoritmo Guloso com Heuristica -> 2\n");
    printf("Pesquisa A*                     -> 3\n");
    printf("Busca em largura                -> 4\n");
    printf("Busca em profundidade           -> 5\n");
    short int resposta;
    scanf("%hd", &resposta);
    while(resposta < 1 || resposta > 5){
        printf("Resposta Inválida, por favor escolha uma das seguintes opções:\n");
        printf("Busca em Profundidade Iterativa -> 1\n");
        printf("Algoritmo Guloso com Heuristica -> 2\n");
        printf("Pesquisa A*                     -> 3\n");
        printf("Busca em largura                -> 4\n");
        printf("Busca em profundidade           -> 5\n");
        scanf("%hd", &resposta);
    }
    return resposta;
}

int main(){
    short int inicial[4][4], final[4][4];
    short int resposta, heur;
    clock_t t;

    readInput(inicial, final);

    if(!possivel(inicial, final)) {
        printf("Impossivel chegar ao estado final!\n");
        return 0;
    }

    resposta = readAlgOpcao();
    printf("Calculando...\n\n");
    t = startTimer();
    switch (resposta) {
        case 1:
            ids(inicial, final);
            break;
        case 2:
            heur = escolherHeuristica();
            Guloso(inicial, final, heur);
            break;
        case 3:
            heur = escolherHeuristica();
            A_star(inicial, final, heur);
            break;
        case 4:
            bfs(inicial, final);
            break;
        case 5:
            BP(inicial, final);
            break;
        default:
            printf("Ops, something went wrong.\nQuitting...\n");
            break;
    }
    stopTimer(t);

    return 0;
}