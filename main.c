#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int inversions(short int grid[][4]);   // Calcular inversoes
bool possivel(short int grid1[][4], short int grid2[][4]);  // Ver se é possivel ir de 1 a outra
bool comparar(short int grid1[][4], short int grid2[][4]);  // Ver se sao iguais
void copyArray(short int a[][4], short int b[][4]);
void findZero(short int a[][4], short int b[]);
#include "./DataStructures/Heap.c"
#include "./SearchAlgs/Heur.c"
#include "./SearchAlgs/Movimentos.c"
#include "./DataStructures/Stack.c"
#include "./SearchAlgs/A*.c"
#include "./SearchAlgs/BP.c"
#include "./SearchAlgs/Guloso.c"




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

//Percorre a lista e verifica quantos elementos que estão depois de i são maiores que ele
int inversions(short int grid[][4]){
    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = i; k < 4; k++){
                if(i == k){
                    for(int l = j; l < 4; l++){
                        if(grid[i][j] > grid[k][l] && grid[i][j] != 0 && grid[k][l] != 0){count++;}
                    }
                }else{
                    for(int l = 0; l < 4; l++){
                        if(grid[i][j] > grid[k][l] && grid[i][j] != 0 && grid[k][l] != 0){count++;}
                    }
                }
            }
        }
    }
    return count;
}

// Verifica se é possivel chegar de um estado ao outro
bool possivel(short int grid1[][4], short int grid2[][4]){
    short int inv1 = inversions(grid1);
    short int inv2 = inversions(grid2);
    short int vazio1, vazio2;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
        if(grid1[i][j] == 0){
            vazio1 = i;
        }
        if(grid2[i][j] == 0){
            vazio2 = i;
            }
        }
    }
    if(((inv1 % 2 == 0) == (vazio1 % 2 == 0)) == ((inv2 % 2 == 0) == (vazio2 % 2 == 0))){
        return true;
    }else{
        return false;
    }
}

// Verifica se o estado atual é igual ao final, ou seja, se terminou

bool comparar(short int grid1[][4], short int grid2[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(grid1[i][j] != grid2[i][j]){return false;}
        }
    }
    return true;
}

void copyArray(short int a[][4], short int b[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = b[i][j];
        }
    }
}
void findZero(short int a[][4], short int b[]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(a[i][j] == 0){
                b[0] = i;
                b[1] = j;
                return;
            }
        }
    }
}
