#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"


/*Merge K sorted arrays*/
#define n 4

void mergeKSortedArrays(int arr1[][n], int k)
{
    maxheap *h = createHeap(13);
    int *output = (int *)malloc(sizeof(int)*n*k);
    int i=0, j=0;
    for(i=0;i<n;i++)
    {
      for(j=0;j<k;j++)
      {
	  insertMinHeap(h,arr1[j][i]); 
      }
    }
    for(i=0;i<n*k;i++)
    {
      output[i]=extractMin(h);
      printf("%d ,", output[i]);
    }
}

int main()
{
  int arr[][n] =  {{2, 6, 12, 34},
                  {1, 9, 20, 1000},
                  {23, 34, 90, 2000}};
  int k = sizeof(arr)/sizeof(arr[0]);
  mergeKSortedArrays(arr, k);
  return 0;

}
