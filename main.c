#include <stdio.h>
#include <time.h>
#include "IDS.h"

// Eventualmente incluir flags para decidir qual Estrutura de Dados usar
// Carregar no Pre-Processador, exemplo, se BPI usar Stack
// gcc -DStack a.out 
// NOTA: Pode não ser necessaŕio pois o Linker é muito prob Dinamico

   // Busca com custo    -> Heap
   // Busca em largura   -> Hash
   // Outras             -> Linked List, Double Linked List, Queue, Stack...

// Configuracao inicial
typedef struct configuracao
{
    short int inicial[16];
    short int final[16];
} Configuracao;

Configuracao carregarConfiguracao(char filename[50])
{
    Configuracao config;

    FILE *file;
    file = fopen(filename, "r");
    if (file)
    {
        for (int i = 0; i < 16; i++)
            fscanf(file, "%hu", &config.inicial[i]);
        for (int i = 0; i < 16; i++)
            fscanf(file, "%hu", &config.final[i]);
    }

    return config;
}

void printBoard(short int grid[16]) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i*4 + j] < 10) {
                printf("%hu   ", grid[i*4 + j]);
            } else {
                printf("%hu  ", grid[i*4 + j]);
            }
        }
        printf("\n");
    }
}

void printConfiguracao(Configuracao config) {
    printf("Config inicial:\n");
    printBoard(config.inicial);

    printf("\nConfig final:\n");
    printBoard(config.final);

    printf("\n\n");
}

clock_t startTimer() {
    return clock();
}

void stopTimer(clock_t t) {
    t = clock() - t;
    printf("Time elapsed: %.4f\n", ((double)t)/CLOCKS_PER_SEC);
}

int main(){
    char filename[50] = "/home/matheus/UP/IA/trabalhos/IA/input2.txt";
    Configuracao config = carregarConfiguracao(filename);
    printConfiguracao(config);

    if (possivel(config.inicial, config.final)) {
        Board* resultBoard;
        clock_t t;

        t = startTimer();
        resultBoard = ids(config.inicial, config.final);
        stopTimer(t);

        printf("Achou!\n");
        printMovementStack(resultBoard->movementStack);
    } else {
        printf("Não é possível chegar ao objetivo final com estas configurações");
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
    move_down(grid1, 3, 3);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%d ", grid1[i][j]);
        }
        printf("\n");
    }
    #endif
    

    return 0;
}