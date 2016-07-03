#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*prog running fine for same input, but not getting submitted*/

#include <stdbool.h>
#include <string.h>
typedef struct HashNode{
  int key;
  int count;
  struct HashNode *next;
  bool insert;
}hashnode;

typedef struct MinHeap{
  hashnode **arr;
  int size;
  int capacity;
}minheap;

typedef struct HashMap{
  hashnode **arr;
  int size;
  int count;
}hashmap;

hashmap *create_map(int size)
{
  hashmap *h = (hashmap*)malloc(sizeof(hashmap));
  h->count=0;
  h->size=size;
  h->arr = (hashnode**)malloc(sizeof(hashnode*)*(size+1));
  int i=0;
  for(i=0;i<size;i++)
    h->arr[i]=NULL;
  return h;
}
hashnode* hash_get(hashmap *h, int key)
{
  int k=key;
  if(key<0)
    k=key*-1;
  int bucket = k % h->size;
  hashnode *tmp = h->arr[bucket];
//  hashnode *tmp=NULL;
  if(tmp!=NULL)
  {
  //  tmp=n;
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
  return tmp;
}
void hash_put(hashmap *h, int key, int value)
{
  int k=key;
  if(key<0)
    k=key*-1;
  int bucket=k%h->size;
  hashnode *node = NULL;
  node = (hashnode *)malloc(sizeof(hashnode));
  node->key=key;
  node->count=value;
  node->insert=false;
  node->next=NULL;
  if(h->arr[bucket]!=NULL){
    hashnode *tmp = h->arr[bucket];
   // hashnode *tmp=NULL;
    //tmp=n;
    while(tmp->next!=NULL)
    {
      tmp =tmp->next;
    }
    tmp->next=node;
  }
  else{
    h->arr[bucket]=node;
    h->count = h->count +1;
  }
}
minheap* createHeap(int capacity)
{
  minheap *h = (minheap*)malloc(sizeof(minheap));
  h->arr = (hashnode **)malloc(sizeof(hashnode*)*capacity);
  h->size=0;
  h->capacity= capacity;
  return h;
}
int parent(int i)
{
  return (i-1)/2;
}
void swap(hashnode **x, hashnode **y)
{
  hashnode *tmp = *x;
  *x=*y;
  *y=tmp;
}
void insertHeap(minheap *h, hashmap* map, int size)
{
  if(h->capacity==h->size)
    return;
  int j=0, count=0;
  while(h->size<size && j< map->size)
  {
    hashnode *n = map->arr[j];
    if(n){
      h->arr[h->size]= n;
      n->insert=true;
      (h->size)++;
      int i=(h->size)-1;
      while(i!=0 && h->arr[parent(i)]->count > h->arr[i]->count)
      {
        swap(&h->arr[parent(i)],&h->arr[i]);
        i=parent(i);
      }
    }
    j++;
  }
}
void minHeapify(minheap *h, int i)
{
  int l=2*i+1;
  int r=2*i+2;
  int smallest=i;
  if(l< h->size && h->arr[i]->count > h->arr[l]->count)
    smallest=l;
  if(r< h->size && h->arr[smallest]->count > h->arr[r]->count)
    smallest=r;
  if(smallest!=i)
  {
    swap(&h->arr[smallest], &h->arr[i]);
    minHeapify(h,smallest);
  }

}
int extractMin(minheap *h)
{
  hashnode *root = h->arr[0];
  h->arr[0]=h->arr[(h->size)-1];
  h->size = h->size - 1;
  minHeapify(h,0);
  return (int)(root->key);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
  if(!nums || numsSize==0)
    return NULL;
  int *out,i=0,j=0;
  if(numsSize==k)
  {
    out=(int *)malloc(sizeof(int)*k);
    for(i=0;i<k;i++)
      out[i]=nums[i];
    *returnSize=k;
    return out;
  }
  hashmap *map = create_map(numsSize);
  for(i=0;i<numsSize;i++)
  {
    hashnode *n=hash_get(map,nums[i]);
    if(n!=NULL)
    {
      n->count= n->count+1;
    }
    else
      hash_put(map,nums[i],1);
  }
  minheap *heap = createHeap(k);
  out = (int *)malloc(sizeof(int)*k);
  insertHeap(heap, map,k);
  for(j=0;j<numsSize;j++)
  {
    hashnode *n = hash_get(map, nums[j]);
    if(n->count > heap->arr[0]->count && !n->insert)
    {
      heap->arr[0]=n;
      minHeapify(heap,0);
    }
  }
  for(i=0;i<k;i++)
  {
    out[i]=extractMin(heap);
  }
  *returnSize=k;
  free(heap);
  free(map);
  return out;
}
int main()
{
  int arr[] = {4,1,-1,2,-1,2,3};
  int size=2, s=0;
  int *ret=topKFrequent(arr, 7, size, &s);
  int i=0;
  for(i=0;i<size;i++)
    printf("%d ,",ret[i]);

  return 0;
}
