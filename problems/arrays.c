#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashmap.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


/*325 Maximum Size Subarray Sum Equals k
 * Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn’t one, return 0 instead.
 * Example 1:
 * Given nums = [1, -1, 5, -2, 3], k = 3, return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
 * Example 2:
 * Given nums = [-2, -1, 2, 1], k = 1, return 2. (because the subarray [-1, 2] sums to 1 and is the longest)*/

int maxLen(int *arr, int k, int size)
{
  if(arr==NULL)
    return 0;
  if(size==1 && arr[0]==k)
    return 1;
  hashmap *hm = create_map(size);
  int i =0, sum=0, maxlen=0, val=0;
  for(i=0;i<size;i++)
  {
    sum+=arr[i];
    if(arr[i]==k && maxlen==0)
      maxlen=1;
    if(sum==k)
      maxlen = i+1;
    if(!map_containsKey(hm, sum,NULL)) 
      map_put(hm, sum, i);
    if(map_containsKey(hm, sum-k, &val))
       maxlen = MAX(maxlen, i-val);
  }
  free(hm);
  return maxlen;
}
/*88. Merge Sorted Array   
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 * */
void merge(int* nums1, int m, int* nums2, int n) {
  int ptr1=m-1, ptr2=n-1,i=0;
  if(n==0)
    return;
  if(m==0 && n==1)
  {
    nums1[0]=nums2[0];
    return;
  }
  int j = m+n-1;
  while(ptr1>=0 && ptr2>=0)
  {
    if(nums2[ptr2] >nums1[ptr1]){
      nums1[j]=nums2[ptr2];
      ptr2--;j--;
    }
    else if(nums1[ptr1] > nums2[ptr2]){
      nums1[j]=nums1[ptr1];
      ptr1--; j--;
    }
    else if(nums1[ptr1]==nums2[ptr2])
    {
      nums1[j--]=nums1[ptr1];
      nums1[j--]=nums2[ptr2];
      ptr1--;
      ptr2--;
    }
  }
  while(ptr1>=0){
    nums1[j]=nums1[ptr1];
    j--;ptr1--;
  }
  while(ptr2>=0){
    nums1[j]= nums2[ptr2];
    j--;ptr2--;
  }
}


int findPeak(int *arr, int start, int end)
{
  if(start>end)
    return 0;
  int mid = end - (end-start)/2;
  if(arr[mid+1]<arr[mid] && arr[mid-1]<arr[mid])
    return arr[mid];
  else if(mid>0 && arr[mid-1]>arr[mid])
    return findPeak(arr, start, mid-1);
  else
    return findPeak(arr, mid+1, end);
}
int findPeakElement(int* nums, int numsSize) {
  if(!nums || numsSize==0)
    return -1;
  if(numsSize==1)
    return nums[0];
  return findPeak(nums, 0, numsSize);
}
int main()
{
  int arr[] = {100, 20, 15, 2, 1, 9, 67, 80};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k =0;
  //printf("Length of the longest sum subarray is %d \n", maxLen(arr, k, n));
  printf("\n peak elem=%d\n",findPeakElement(arr,n-1));
  return 0;
}
