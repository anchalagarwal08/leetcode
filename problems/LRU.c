#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  int val;
  int key;
  struct Node *next;
  struct Node *prev;
}node;
typedef struct Queue{
  node *head;
  node *tail;
  int count;
}queue;

typedef struct Hashmap{
  node **arr;
  int capacity;
  int count;
}hashmap;

hashmap *map;
queue *qu;
queue *create_queue()
{
  queue *q = (queue*)malloc(sizeof(queue));
  q->head=NULL;
  q->tail=NULL;
  q->count=0;
  return q;
}
void enqueue(queue *q, node *n)
{
  if(q->head==NULL)
  {
    q->head=q->tail=n;
  }
  else{
    q->tail->next=n;
    n->prev = q->tail;
    q->tail=q->tail->next;
  }
  q->count=(q->count)+1;
}

node * dequeue(queue *q)
{
  if(q->count==0)
    return NULL;
  node *t=q->head;
  q->head=q->head->next;
  if(q->head!=NULL)
      q->head->prev=NULL;
  t->next=NULL;
  return t;
}
hashmap *create_map(int size)
{
  hashmap *h = (hashmap*)malloc(sizeof(hashmap));
  h->count=0;
  h->capacity=size;
  h->arr = (node**)malloc(sizeof(node*)*size);
  int i=0;
  for(i=0;i<size;i++)
    h->arr[i]=NULL;
  return h;
}

void move_queue(queue *q, node *tmp)
{
  if(!q || !tmp || q->count==1 || q->tail ==tmp)
    return;
  else 
  {
    q->tail->next=tmp;
    if(tmp->next!=NULL && tmp->prev!=NULL)/*middle element*/
    {
      tmp->next->prev=tmp->prev;
      tmp->prev->next=tmp->next;
    }
    else{
      q->head=q->head->next;
      q->tail->prev=NULL;
    }
    tmp->prev=q->tail;
    q->tail = q->tail->next;
    q->tail->next=NULL;
  }

}
void hash_remove(hashmap *h, int key)
{
  int k=key;
  if(key<0)
    k=key*-1;
  int bucket=k%h->capacity;
  node *n = h->arr[bucket];
  node *temp=NULL;
  if(n)
  {
    temp=n;
    while(temp)
    {
      int v = temp->key;
      if(v==key){
        h->arr[bucket]=NULL;
        free(n);
        break;
      }
      else
        temp=temp->next;
    }
  }
}

node* hash_get(hashmap *h, int key)
{
  if(h->count==0)
    return NULL;
  int k=key;
  if(key<0)
    k=key*-1;
  int bucket = k % h->capacity;
  node *n = h->arr[bucket];
  node *tmp=NULL;
  if(n!=NULL)
  {
    tmp=n;
    while(tmp!=NULL)
    {
      int v = tmp->key;
      if(v==key)
        break;
      else
        tmp=tmp->next;
    }
  }
  else
    return NULL;
  move_queue(qu, tmp);
  return tmp;
}
void hash_put(hashmap *h, int key, int value)
{
  int k=key;
  if(key<0)
    k=key*-1;
  if(h->count==h->capacity){
    node *tmp = dequeue(qu);
    if(tmp)
      hash_remove(h,tmp->key);
  }
  int bucket=k%h->capacity;
  node *n1 = (node *)malloc(sizeof(node));
  n1->key=key;
  n1->val=value;
  n1->next=NULL;
  n1->prev=NULL;
  if(h->arr[bucket]){
    node *n = h->arr[bucket];
    node *tmp=n;
    while(tmp->next!=NULL)
    {
      tmp =tmp->next;
    }
    tmp->next=n1;
  }
  else{
    h->arr[bucket]=n1;
    enqueue(qu, n1);
    h->count = h->count +1;
  }
}

void lruCacheInit(int capacity) {
  map=create_map(capacity);
  qu =create_queue();
}

void lruCacheFree() {
  if(map)
    free(map);
  if(qu)
    free(qu);
}

int lruCacheGet(int key) {
  node *n = hash_get(map,key);
  if(n)
    return n->val;
  return -1;
}

void lruCacheSet(int key, int value) {
  node *n = hash_get(map,key);
  if(n)
    n->val=value;
  else
    hash_put(map, key, value);
}


int main()
{
  lruCacheInit(1);
  lruCacheSet(2,1);
  printf("%d \n",lruCacheGet(2));
  lruCacheSet(3,2);
  printf("%d \n",lruCacheGet(2));
  printf("%d \n",lruCacheGet(3));
  lruCacheFree();
  
  return 0;
}
