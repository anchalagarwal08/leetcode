#include <stdio.h>
#include <stdlib.h>

typedef struct HashNode{
  struct HashNode *next;
  int key;
  int val;
}hashnode;

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
  h->arr = (hashnode**)malloc(sizeof(hashnode*)*size);
  int i=0;
  for(i=0;i<size;i++)
    h->arr[i]=NULL;
  return h;
}
unsigned int get_index(hashmap *h, int key)
{
  /* Robert Jenkins' 32 bit Mix Function */
  key += (key << 12);
  key ^= (key >> 22);
  key += (key << 4);
  key ^= (key >> 9);
  key += (key << 10);
  key ^= (key >> 2);
  key += (key << 7);
  key ^= (key >> 12);

  /* Knuth's Multiplicative Method */
  key = (key >> 3) * 2654435761;

  return key % h->size;
}
    
void hash_put(hashmap *h, int key, int value)
{
  int k=0;
  if(key<0)
    k=key*-1;
  int bucket=k%h->size;//get_index(h,key);
  hashnode *node = (hashnode *)malloc(sizeof(hashnode));
  node->key=key;
  node->val=value;
  if(h->arr[bucket]){
    hashnode *n = h->arr[bucket];
    hashnode *tmp=n;
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

hashnode* hash_get(hashmap *h, int key)
{
  int k=0;
  if(key<0)
    k=key*-1;
  int bucket = k%h->size;//get_index(h,key);
  hashnode *n = h->arr[bucket];
  hashnode *tmp=NULL;
  if(n)
  {
    tmp=n;
    while(tmp)
    {
      if(tmp->key==key)
        break;
      else
        tmp=tmp->next;
    }
  }
  else
    return NULL;
  return tmp;
}
int singleNumber(int* nums, int numsSize) {
  if(!nums || numsSize==0)
    return 0;
  if(numsSize==1)
    return nums[0];
  hashmap *h = create_map(numsSize);
  int i=0, val=0, flag=0;
  for(i=0;i<numsSize;i++)
  {
    hashnode *n=hash_get(h,nums[i]);
    if(n)
    {
      n->val=n->val+1;
    }
    else
      hash_put(h,nums[i],1);
  }
  for(i=0;i<=h->count;i++)
  {
    hashnode *n1 = h->arr[i];//hash_get(h,nums[i]);
    if(n1){
      while(n1){
        if(n1->val==1){
          val=n1->key;
          flag=1;
          break;
        }
        n1=n1->next;
      }
      if(flag)
        break;
    }
  }
  free(h);
  return val;
}

int main()
{
  int arr[]={43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43};
  printf("%d\n", singleNumber(arr, 24));
  return 0;
}
