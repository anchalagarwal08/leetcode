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
void getMedian(int num, int *median, heap *l, heap *r)/*l=maxheap, r=minheap*/
{
  int median=0;
  int comp = compareHeapCount(l->size, r->size);
  switch(comp)
  {
    /*left heap has less elements than right one*/
    case -1:
      if(num<*median)
      {
        insertMaxheap(l,num); //insert in left heap
      }
      else
      {
        int e = extractMin(r);
        insertMaxHeap(l, e);
        insertMinheap(r,num);
      }
      *median = average(getTop(l), getTop(r));
      break;
    case 0:
      if(num<*median)
      {
        insertMaxHeap(l,num);
        *median=getTop(l);
      }
      else
      {
        insertMinHeap(r,num);
        *median=getTop(r);
      }
      break;
    case 1:/*right heap has less elements than left*/
      if(num<*median)
      {
        int e = extractMax(l);
        insertMinHeap(r,e);
        insertMaxHeap(l,num);

      }
      else
      {
        insertMinheap(r,num);
      }
      *median=average(getTop(l), getTop(r));
    break;
    default:
      break;
  }
}
}
