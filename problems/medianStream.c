/*Median in a stream of integers (running integers)
 * Given that integers are read from a data stream. Find median of elements read so for in efficient way. For simplicity assume there are no duplicates. For example, let us consider the stream 5, 15, 1, 3 …
 *
 * After reading 1st element of stream - 5 -> median - 5
 * After reading 2nd element of stream - 5, 15 -> median - 10
 * After reading 3rd element of stream - 5, 15, 1 -> median - 5
 * After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
/*For median calculation*/
int getHeapRoot(maxheap *h)
{

}

int compareHeapCount(int a, int b)
{
  if(a==b)
    return 0;
  return (a<b ? -1 : 1);
}
int getMedian(int num, maxheap *l, maxheap *r)
{
  int median=0;
  int comp = compareHeapCount(l->size, r->size);
  if(!comp)
    median = (getHeapRoot(l)+getHeapRoot(r))/2;
  else if(comp==-1)
    median = getHeapRoot(r);
  else
    median = getHeapRoot(l);
  if(num > median)
  {
      if(comp==-1)
      {
        l->arr[size]=r->arr[0];
        l->size=l->size+1;
        r->arr[0]=r->arr[size-1];
        r->size=r->size-1;
        maxHeapify(l, 0);
      }
      insertMinHeap(r, num);
      minHeapify(r, 0);
  }
  else{
    if(comp==1)
    {
      r->arr[size]=l->arr[0];
      r->size=r->size+1;
      l->arr[0]=l->arr[size-1];
      l->size=l->size-1;
      minHeapify(r, 0);
    }
    insertHeap(l, num);
    maxHeapify(l, 0);
  }
}
