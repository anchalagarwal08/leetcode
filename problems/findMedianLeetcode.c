#include <stdio.h>
#include <stdlib.h>
typedef struct Heap
{
  double *arr;
  int size;
  int count; 
}Heap;

struct MedianFinder {
  Heap *minheap;
  Heap *maxheap;
  double median;
};

Heap *createHeap(int size)
{
  Heap *h = (Heap*)malloc(sizeof(Heap));
  h->arr = (double *)malloc(sizeof(double)*size);
  h->size=size;
  h->count=0;
  return h;
}
void swap(double *a, double *b)
{
  double c = *a;
  *a=*b;
  *b=c;
}
int parent(int i)
{
  return (i-1)/2;
}
void insertMinHeap(Heap *h, int val)
{
  if(!h || (h->size==h->count))
    return;
  h->arr[h->count]=(double)val;
  h->count=h->count+1;
  int i = h->count -1;
  while(i!=0 && h->arr[parent(i)]>h->arr[i])
  {
    swap(&h->arr[parent(i)], &h->arr[i]);
    i = parent(i);
  }
}
void insertMaxHeap(Heap *h, int val)
{
  if(!h || (h->size==h->count))
    return;
  h->arr[h->count]=(double)val;
  h->count=h->count+1;
  int i = h->count -1;
  while(i!=0 && h->arr[parent(i)]<h->arr[i])
  {
    swap(&h->arr[parent(i)], &h->arr[i]);
    i = parent(i);
  }

}
void maxHeapify(Heap *h, int idx)
{
  if(!h)
    return;
  int left = 2*idx+1;
  int right = 2*idx+2;
  int largest =idx;
  if(left<h->count && h->arr[idx]<h->arr[left])
    largest=left;
  if(right < h->count && h->arr[largest] < h->arr[right])
    largest=right;
  if(largest!=idx)
  {
    swap(&h->arr[largest], &h->arr[idx]);
    maxHeapify(h,largest);
  }

}
void minHeapify(Heap *h, int idx)
{
  if(!h)
    return;
  int left = 2*idx+1;
  int right = 2*idx+2;
  int smallest =idx;
  if(left<h->count && h->arr[idx]>h->arr[left])
    smallest=left;
  if(right < h->count && h->arr[smallest] > h->arr[right])
    smallest=right;
  if(smallest!=idx)
  {
    swap(&h->arr[smallest], &h->arr[idx]);
    minHeapify(h,smallest);
  }

}
/** Initialize your data structure here. */
struct MedianFinder* MedianFinderCreate() {
  struct MedianFinder *mf = ( struct MedianFinder *)malloc(sizeof( struct MedianFinder));
  mf->minheap = createHeap(100);
  mf->maxheap = createHeap(100);
  mf->median=0.0;
  return mf;
}

int compare(int a, int b)
{
  if(a==b)
    return 0;
  return a<b?-1:1;
}
/** Inserts a num into the data structure. left of median=maxheap right of median=minheap*/
void addNum(struct MedianFinder* mf, int num) {
  if(!mf)
    return;
  int i = compare(mf->maxheap->count, mf->minheap->count);
  printf("\n median=%lf, num=%d",mf->median,num);
  switch(i)
  {
    case -1:
      if(num<mf->median)
        insertMaxHeap(mf->maxheap, num);
      else{
        int e = mf->minheap->arr[0];
        insertMaxHeap(mf->maxheap,e);
        mf->minheap->arr[0]=num;
        minHeapify(mf->minheap, 0);
      }
      mf->median=(double)((mf->maxheap->arr[0]+mf->minheap->arr[0])/2);
      break;
    case 0:
      if(num<mf->median)
      {
        insertMaxHeap(mf->maxheap, num);
        mf->median= mf->maxheap->arr[0];
      }
      else{
        insertMinHeap(mf->minheap, num);
        mf->median= mf->minheap->arr[0];
      }
      break;
    case 1:
      if(num<mf->median){
        int e = mf->maxheap->arr[0];
        insertMinHeap(mf->minheap,e);
        mf->maxheap->arr[0]=num;
        maxHeapify(mf->maxheap, 0);
      }
      else{
        insertMinHeap(mf->minheap, num);
      }
      mf->median=(mf->maxheap->arr[0]+mf->minheap->arr[0])/2;
      break;
    default:
      break;
  }
}

/** find the median of current data stream */
double findMedian(struct MedianFinder* mf) {
  return mf->median;
}

/** Deallocates memory previously allocated for the data structure. */
void MedianFinderFree(struct MedianFinder* mf) {
  free(mf);
}
int main()
{
// Your MedianFinder object will be instantiated and called as such:
struct MedianFinder* mf = MedianFinderCreate();
addNum(mf, 2);
printf("\n median=%lf",findMedian(mf));
addNum(mf,3);
printf("\n median=%lf",findMedian(mf));
MedianFinderFree(mf);
}
