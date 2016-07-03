#include <stdio.h>
#include <stdlib.h>
int findMinHelper(int *arr, int start, int end)
{
  if(start>end)
    return arr[0];
  if(start==end)
    return arr[start];
  int mid = (end+start)/2;
  if(mid>start && arr[mid]<arr[mid-1])
    return arr[mid];
  if(mid<end && arr[mid]>arr[mid+1])
    return arr[mid+1];
  if(arr[mid]>arr[end])
    return findMinHelper(arr, mid+1, end);
  return findMinHelper(arr, start, mid-1);

}

int findMin(int* nums, int numsSize) {
  if(!nums)
    return 0;
  return findMinHelper(nums, 0, numsSize-1);
}

int main()
{
  int arr[]={2, 3, 4, 5, 1};
  printf("val =%d\n", findMin(arr, 5));
}
