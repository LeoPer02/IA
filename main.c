#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Stack.c"
#include "Queue.c"
#include "heur.c"

// Eventualmente incluir flags para decidir qual Estrutura de Dados usar
// Carregar no Pre-Processador, exemplo, se BPI usar Stack
// gcc -DStack a.out 
// NOTA: Pode não ser necessaŕio pois o Linker é muito prob Dinamico





int inversions(short int grid[][4]);   // Calcular inversoes
bool possivel(short int grid1[][4], short int grid2[][4]);  // Ver se é possivel ir de 1 a outra
bool comparar(short int grid1[][4], short int grid2[][4]);  // Ver se sao iguais

   // Busca com custo    -> Heap
   // Busca em largura   -> Hash
   // Outras             -> Linked List, Double Linked List, Queue, Stack...

int main(){
    short int grid1[4][4], grid2[4][4];                                      // short int para minimizar espaço em memória
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%hd", &grid1[i][j]);
        }                                                                // Ler inteiros para dentro do array grid
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%hd", &grid2[i][j]);
        }
    } 


    #ifdef DEBBUG
    printf(" ---------------\nStack:\n ---------------\n");
    struct node* root = (struct node*)malloc(sizeof(struct node));
    copyArray(root->data, grid1);
    root -> next = NULL;
    printf("adicionado 1 elemento \n");
    top(&root);
    push(grid2,&root);
    printf("adicionado 1 elemento \n");
    top(&root);
    pop(&root);
    top(&root);
    printf("Vazia: %d\n", isEmpty(&root));
    pop(&root);
    top(&root);
    printf("Vazia: %d\n", isEmpty(&root));

    // Queue ainda não funciona
    printf(" ---------------\nLista:\n ---------------\n");
    Node* lista = (Node*)malloc(sizeof(Node));
    enqueue(&lista, grid1, 1);
    enqueue(&lista, grid2, 1);
    printQ(&lista);
    dequeue(&lista);
    printQ(&lista);
    printf("Vazia: %d\n", isEmptyQ(&lista));
    dequeue(&lista);
    printQ(&lista);
    printf("Vazia: %d\n", isEmptyQ(&lista));
    printf(" ---------------\n");

    printf("Sumatorio: %d\n", sum(grid1, grid2));
    printf("Manhattan: %d\n", manh(grid1, grid2));
    #endif
    

    return 0;
}

//Percorre a lista e verifica quantos elementos que estão depois de i são maiores que ele
//Foi testada e funcionou corretamente
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
// Foi testada e funcionou em ambos os casos
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
// Foi testada e funcionou em ambos os casos
bool comparar(short int grid1[][4], short int grid2[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(grid1[i][j] != grid2[i][j]){return false;}
        }
    }
    return true;
}