/*using arrays*/
typedef struct {
    int *arr;
    int start;
    int end;
    int size;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
   queue->arr = (int *)malloc(sizeof(int)*maxSize);
   queue->size=maxSize;
   queue->start=0;
   queue->end=0;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    if(queue->end==queue->size)
    {
        return;
    }
    else
        queue->arr[queue->end++]=element;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
   (queue->start)++;
}

/* Get the front element */
int queuePeek(Queue *queue) {
    return queue->arr[queue->start];
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    return queue->start==queue->end;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    free(queue->arr);
}



/*using linklist*/
typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
    int maxSize;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
   queue->size=0;
   queue->maxSize=maxSize;
   queue->head=NULL;
   queue->tail=NULL;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
     Node *n=(Node *)malloc(sizeof(Node));
     n->val=element;
     n->next=NULL;
    if(!queue->head)
    {
        queue->head=n;
    }
    else if(queue->head->next==NULL)
    {
        queue->head->next=n;
        queue->tail=queue->head->next;
    }
    else if(queue->size==queue->maxSize)
    {
        return;
    }
    else{
        queue->tail->next=n;
        queue->tail=queue->tail->next;
    }
    (queue->size)++;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    Node *curr;
    if(queue->size<=0)
        return;
    else{
        curr=queue->head;
        queue->head=curr->next;
        (queue->size)--;
        free(curr);
    }
}

/* Get the front element */
int queuePeek(Queue *queue) {
    return queue->head->val;
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    if(queue && queue->size<=0)
        return true;
    else
        return false;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    Node *tmp=queue->head;
    while(queue->head)
    {
        tmp = queue->head;
        queue->head=queue->head->next;
        free(tmp);
    }
    queue->size=0;
    queue->head=NULL;
    queue->tail=NULL;
}
