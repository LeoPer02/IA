//Ainda não funciona

typedef struct node2 {
   short int data[4][4];
   int priority;
   struct node2* next;
} Node;
Node* newNode(short int d[][4], int p) {
   Node* temp = (Node*)malloc(sizeof(Node));
   copyArray(temp->data, d);
   temp->priority = p;
   temp->next = NULL;
   return temp;
}
void topQ(Node** head) {
    Node* temp = *head;
   for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", temp->data[i][j]);
        }
        printf("\n");
    }
}
void dequeue(Node** head) {
   Node* temp = *head;
   (*head) = (*head)->next;
   free(temp);
}
void enqueue(Node** head, short int d[][4], int p) {
   Node* start = (*head);
   Node* temp = newNode(d, p);
   if ((*head)->priority > p) {
      temp->next = *head;
      (*head) = temp;
   } else {
      while (start->next != NULL &&
      start->next->priority < p) {
         start = start->next;
      }
      // Either at the ends of the list
      // or at required position
      temp->next = start->next;
      start->next = temp;
   }
}
// Function to check the queue is empty
int isEmptyQ(Node** head) {
   return (*head) == NULL;
}

void printQ(Node** head){
    Node* temp = *head;
    while(temp->next != NULL && temp->next->priority < temp->priority){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                printf("%d ", temp->data[i][j]);
            }
            printf("\n");
        }
    }
}