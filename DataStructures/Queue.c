
// A linked list (LL) node to store a queue entry
struct QNode {
    short int data[4][4];
    struct QNode* next;
    struct Qnode* parent;
    short int x;
    short int y;
    char mov;
};
 
 
// A utility function to create a new linked list node.
struct QNode* newNodeQ(short int k[][4], struct Qnode* parent, short int x, short int y, char mov)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    copyArray(temp->data, k);
    temp->next = NULL;
    temp->parent = parent;
    temp->x = x;
    temp->y = y;
    temp->mov = mov;
    return temp;
}
// The function to add a key k to q
bool QisEmpty(struct Queue* q){
    return q->front == NULL;
}

void enQueue(struct Queue* q, short int k[][4], struct Qnode* parent, short int x, short int y, char mov)
{
    // Create a new LL nodes
    struct QNode* temp = newNodeQ(k,parent, x, y, mov);
 
    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

bool Qcontem(struct Queue q, short int a[][4]){
    struct Qnode* temp = q.front;
    while(temp != NULL){
        if(comparar(temp->data, a)){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
 
// Function to remove a key from given queue q
struct Qnode* deQueue(struct Qnode* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return NULL;
 
    // Store previous front and move front one node ahead
    struct QNode* temp = q->front;
 
    q->front = q->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
 
    return temp;
}

void returnPathQ(struct Qnode** a){
    while(a->parent != NULL){
        printf("%c", a->mov);
    }
    printf("\n");
}