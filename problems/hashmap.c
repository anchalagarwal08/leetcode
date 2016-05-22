#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hashmap.h"

/*1. Two Sum
 * no duplicates, can have negatives*/
void twoSum(int *arr, int size, int sum)
{
  if(size==0)
    return;
  int i=0, val=0;
  hashmap *map = create_map(size);
  for(i=0;i<size;i++)
  {
    map_put(map, arr[i], i); 
  }
  for(i=0;i<size;i++)
  {
    if(map_containsKey(map, sum-arr[i], &val))
    {
      printf("\npair found x1=%d, x2=%d \n", i, val);
      return;
    }
  }
  printf("\n num not found\n");
}

int main()
{
  int arr[] = {-2, 11, 8, -3, 7};
  twoSum(arr, 5, -5);
  return 0;
}
