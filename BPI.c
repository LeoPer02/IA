#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

void printConfiguracao(Configuracao config) {
    printf("Config inicial:\n"); 
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (config.inicial[i*4 + j] < 10) {
                printf("%hu   ", config.inicial[i*4 + j]);
            } else {
                printf("%hu  ", config.inicial[i*4 + j]);
            }
        }
        printf("\n");
    }

    printf("\nConfig final:\n"); 
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (config.final[i*4 + j] < 10) {
                printf("%hu   ", config.final[i*4 + j]);
            } else {
                printf("%hu  ", config.final[i*4 + j]);
            }
        }
        printf("\n");
    }

    printf("\n\n");
}

//int BPI();
int inversions(short int *grid);
bool possivel(short int *grid1, short int *grid2);
bool comparar(short int *grid1, short int *grid2);

struct node
{ // Nós de uma linked list para criar uma queue
    short int *grid;
    struct node *next;
};
typedef struct node node;

typedef struct queue
{ // Implementação de uma queue usando Linked List
    int size;
    node *front;
    node *back;
} queue;

void inicializar(queue *q)
{ // Inicializar a queue
    q->size = 0;
    q->front = NULL;
    q->back = NULL;
}

bool isEmpty(queue *q)
{ // Verificar se a queue está vazia ou não
    return (q->size == 0);
}

void enqueue(queue *q, short int *grd)
{
    node *ptr;

    ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        ptr->grid = grd;
        if (q->front == NULL)
        {
            q->front = ptr;
            q->back = ptr;
            q->front->next = NULL;
            q->back->next = NULL;
        }
        else
        {
            q->back->next = ptr;
            q->back = ptr;
            q->back->next = NULL;
        }
    }
}
void dequeue(queue *q)
{
    node *ptr;
    if (q->front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = q->front;
        q->front = q->front->next;
        free(ptr);
    }
}
void printQ(queue *q)
{
    node *ptr;
    ptr = q->front;
    if (q->front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nprinting values .....\n");
        while (ptr != NULL)
        {
            for (int i = 0; i < 16; i++)
            {
                printf("%d ", *(ptr->grid + i));
            }
            printf("\n");
            ptr = ptr->next;
        }
    }
}

//int BPI(){

//Percorre a lista e verifica quantos elementos que estão depois de i são maiores que ele
//Foi testada e funcionou corretamente
int inversions(short int *grid)
{
    int count = 0;
    for (int i = 0; i < 16; i++)
    {
        for (int j = i + 1; j < 16; j++)
        {
            if (*(grid + i) > *(grid + j) && *(grid + j) != 0 && *(grid + i) != 0)
            {
                count++;
            }
        }
    }
    return count;
}

// Verifica se é possivel chegar de um estado ao outro
// Foi testada e funcionou em ambos os casos
bool possivel(short int *grid1, short int *grid2)
{
    int inv1 = inversions(grid1);
    int inv2 = inversions(grid2);
    int zero1, zero2;
    for (int i = 0; i < 16; i++)
    {
        if (*(grid1 + i) == 0)
        {
            zero1 = i;
        }
        if (*(grid2 + i) == 0)
        {
            zero2 = i;
        }
    }
    if (((inv1 % 2 == 0) == ((zero1 >= 0 && zero1 <= 3) || (zero1 >= 8 && zero1 <= 11))) == ((inv2 % 2 == 0) == ((zero2 >= 0 && zero2 <= 3) || (zero2 >= 8 && zero2 <= 11))))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Verifica se o estado atual é igual ao final, ou seja, se terminou
// Foi testada e funcionou em ambos os casos
bool comparar(short int *grid1, short int *grid2)
{
    for (int i = 0; i < 16; i++)
    {
        if (*(grid1 + i) != *(grid2 + i))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char filename[50] = "config.txt";
    Configuracao config = carregarConfiguracao(filename);

    printConfiguracao(config);

    short int grid1[16], grid2[16]; // short int para minimizar espaço em 
    memcpy(grid1, config.inicial, sizeof grid1);
    memcpy(grid2, config.final, sizeof grid2);

    printf("%d -- %d\n", inversions(grid1), inversions(grid2)); // Verificar numero inversoes
    printf("%d\n", possivel(grid1, grid2));                     // Verificar se é possivel chegar de uma á outra

    if (possivel(grid1, grid2) == 0)
    { // Mensagem de erro caso não seja possivel ir de Si -> Sf
        printf("Não é possivel chegar de um estado ao outro\n");
        return 0;
    }
    else
    { // Iniciar processo de busca
        printf("Iniciando processo de busca...\n");
        queue *q;
        q = malloc(sizeof(queue));
        inicializar(q);
        enqueue(q, grid1);
        enqueue(q, grid2);
        printQ(q);
        dequeue(q);
        printQ(q);
        printf("Sai 2 printq\n");
        dequeue(q);
        printf("Sai 2 dequeue\n");
        printQ(q);
    }

    return 0;
}