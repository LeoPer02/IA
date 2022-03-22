
short int sizeStack = 0;

// Nós da linked list usada na stack
struct node
{
    short int data[4][4];
    struct Hnode* next;
    char mov;
    short int cost;
    struct Hnode* parent;
    

};

// Verificar se a Stack está vazia
bool isEmpty(struct Hnode** stack){
    if(*stack == NULL || sizeStack == 0){
        return 1;
    }else{
        return 0;
    }
}


// Fazer push de um elemento para a Stack
void push(short int grid[][4], short int cost1, char mov1, struct Hnode** stack, struct Hnode* parent, short int x, short int y){
    struct Hnode* node1 = (struct Hnode*)malloc(sizeof(struct Hnode)); 
    copyArray(node1->data, grid); 
    node1->next = *stack;
    node1->parent = parent;
    node1->priority = cost1;  
    node1->mov = mov1;
    node1->x = x;
    node1->y = y;
    *stack = node1;  
    sizeStack++;
}
/*
bool contem(struct Hnode** stack, short int a[][4]){
    struct Hnode* tmpr = (*stack);
    while(tmpr != NULL){
        printf("while %p ->next = %p\n", &tmpr, &tmpr->next);
        if(comparar(tmpr->data, a)){
            return true;
        }        
        tmpr = tmpr->next;
    }
    printf("Sai com false\n");
    return false;
}*/
// Dá pop/remove o elemento do topo da stack
struct Hnode* pop(struct Hnode** stack){
    if(*stack != NULL && (*stack) -> data != NULL && sizeStack != 0){
        /*printf("Element popped:\n");                             // Print apenas para debbuging
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("%d ", (*stack)->data[i][j]);
            }
            printf("\n");
        }   
        */
        struct Hnode* tempPtr = *stack;
        *stack = (*stack) -> next;
        sizeStack--;
        return tempPtr;
    }
    return NULL;
}
// Mostra o elemento do topo sem o remover
struct Hnode* top(struct Hnode** stack){
    return (*stack);
}

bool contemS(struct Hnode** stack, short int a[][4]){
    struct Hnode* temp;
    if(isEmpty(stack)) return false;
    temp = (*stack);
    while(temp != NULL){
        printf("While\n");
        if(comparar(temp->data, a)){
            return true;
        }
        temp = temp->next;
    }
    return false;
}


void returnPath(struct Hnode** stack){
    int depth = 0;
    struct Hnode* tmp;
    tmp = top(stack);
    char array[80];
    while(tmp->parent != NULL){
        array[depth] =  tmp->mov;
        tmp = tmp->parent;
        depth++;
    }
    printf("Movimentos: ");
    for(int i = depth-1; i >= 0; i--){
        printf("%c", array[i]);
    }
    printf("   Depth = %d\n", depth);
}