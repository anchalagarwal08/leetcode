#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"


/*Merge K sorted arrays*/
#define n 4
void swapNodes(HeapNode **a, HeapNode **b)
{
  HeapNode *tmp = *a;
  *a = *b;
  *b = tmp;
}

void insertHeapObj(maxheap *h, int val, int nxt_idx, int arr_idx)
{
  if(h->capacity == h->size)
    return;
  h->nodes[h->size] = (HeapNode *)malloc(sizeof(HeapNode));
  h->nodes[h->size]->elem =val;
  h->nodes[h->size]->arr_idx=arr_idx;
  h->nodes[h->size]->nxt_idx=nxt_idx;
  h->size = h->size +1;
  int i =h->size -1;
  while(i!=0 && h->nodes[parent(i)]->elem > h->nodes[i]->elem)
  {
    swapNodes(&h->nodes[parent(i)], &h->nodes[i]);
    i = parent(i);
}
}
void minHeapifyObj(maxheap *h, int i)
{
  int l = 2*i+1;
  int r = 2*i+2;
  int smallest =i;
  if(l<h->size && h->nodes[l]->elem<h->nodes[i]->elem)
    smallest = l;
  if(r<h->size && h->nodes[r]->elem<h->nodes[smallest]->elem)
    smallest =r;
  if(smallest!=i)
  {
    swapNodes(&h->nodes[smallest], &h->nodes[i]);
    minHeapifyObj(h, smallest);
  }
}
HeapNode* extractMinObj(maxheap *h)
{
  HeapNode *root = h->nodes[0];
  h->nodes[0]=h->nodes[h->size-1];
  (h->size)--;
  minHeapifyObj(h, 0);
  return root;
}

void mergeKSortedArrays1(int arr1[][n], int k)
{
  maxheap *h = createHeap(k);
  h->nodes = (HeapNode**)malloc(sizeof(HeapNode*)*k);
  int i=0, j=0, m=0, idx=0;
  int *output = (int *)malloc(sizeof(int)*n*k);
  for(i=0;i<k;i++)
  {
    insertHeapObj(h,arr1[i][0],1,i);
  }
  for(j=0;j<n*k;j++)
  {
    HeapNode *tmp= extractMinObj(h);
    output[j] = tmp->elem;
    if(tmp->nxt_idx<n)
    {
      m=tmp->nxt_idx;
      idx= tmp->arr_idx;
      insertHeapObj(h, arr1[idx][m],m+1,idx);
    }
  }
  for(i=0;i<n*k;i++)
  {
    printf("%d ,", output[i]);
  }
  if(output)
    free(output);
  if(h)
    free(h);
}
int main()
{
  int arr[][n] =  {{2, 6, 12, 34},
                  {1, 9, 20, 1000},
                  {23, 34, 90, 2000}};
  int k = sizeof(arr)/sizeof(arr[0]);
  mergeKSortedArrays1(arr, k);
  return 0;

}
