#include <stdio.h>

#include "./DataStructures/Heap.h"
#include "./SearchAlgs/Heur.h"
#include "./SearchAlgs/Movimentos.h"
#include "./DataStructures/Stack.h"
#include "./SearchAlgs/A*.h"
#include "./SearchAlgs/BP.h"
#include "./SearchAlgs/Guloso.h"
#include "Utils/BoardUtils.h"


int main(){
    short int inicial[4][4], final[4][4];                                      // short int para minimizar espaço em memória
    printf("Por favor escolha o método de pesquisa que deseja utilizar:\n");
    printf("Busca em Profundidade Iterativa -> 1\n");
    printf("Algoritmo Guloso com Heuristica -> 2\n");
    printf("Pesquisa A*                     -> 3\n");
    short int resposta;
    scanf("%hd", &resposta);
    while(resposta != 1 && resposta != 2 && resposta != 3){
        printf("Resposta Inválida, por favor escolha uma das seguintes opções:\n");
        printf("Busca em Profundidade Iterativa -> 1\n");
        printf("Algoritmo Guloso com Heuristica -> 2\n");
        printf("Pesquisa A*                     -> 3\n");
        scanf("%hd", &resposta);
    }
    if(resposta == 1){
        // Executar Profundidade Iterativa
    }else{
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
        if(!possivel(inicial, final)){
            printf("Impossivel chegar ao estado final!\n");
        }else{
            if(resposta == 3) {
                printf("Calculando...\n\n");
                A_star(inicial, final, heur);
                return 0;
            }    
            printf("Calculando... \n\n");
            Guloso(inicial, final, heur);
        }
    }

    return 0;
}