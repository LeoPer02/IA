#include <stdbool.h>

/*
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
*/
// Exemplo de execução da Stack.

void copyArray(short int a[][4], short int b[][4]);

// Nós da linked list usada na stack
struct node
{
    short int data[4][4];
    struct node* next;

};
// Verificar se a Stack está vazia
bool isEmpty(struct node** stack){
    if(*stack == NULL){
        return 1;
    }else{
        return 0;
    }
}
// Fazer push de um elemento para a Stack
void push(short int grid[][4], struct node** stack){
    struct node* node1 = (struct node*)malloc(sizeof(struct node)); 
    copyArray(node1->data, grid); 
    node1->next = *stack;  
    *stack = node1;  
}
// Copiar um array para outro
// Criada para substituir "stack->data = grid" pois como se trata de
// matrizes não o é possivel fazer
void copyArray(short int a[][4], short int b[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = b[i][j];
        }
    }
}
// Dá pop/remove o elemento do topo da stack
void pop(struct node** stack){
    if(*stack != NULL && (*stack) -> data != NULL){
        printf("Element popped:\n");                             // Print apenas para debbuging
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("%d ", (*stack)->data[i][j]);
            }
            printf("\n");
        }   
        struct node* tempPtr = *stack;
        *stack = (*stack) -> next;
        free(tempPtr);
    }
    else{
        printf("The stack is empty.\n");
    }
}
// Mostra o elemento do topo sem o remover
void top(struct node** stack){
    if(*stack != NULL){
    printf("Element on top:\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", (*stack)->data[i][j]);
        }
        printf("\n");
    }
    }
    else{
        printf("The stack is empty.\n");
    }
}


