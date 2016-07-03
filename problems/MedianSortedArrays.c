#include<stdio.h>
#include<stdlib.h>
/*get Median of 2 sorted arrays each of size n in O(logn) time. Binary search. Find median of each array and compare them till you find a common median for both arrays*/

int getMedian(int *arr1, int *arr2, int s1, int e1, int s2, int e2)
{
  if(e1-s1 <=0 || e2-s2<=0)
    return -1;
  if(e1-s1==1 && e2-s2==1)
   return (arr1[0]+arr2[0])/2;
  if(e1-s1==2 && e2-s2==2)
    return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
  int m1=median(arr1, s1, e1);
  int m2=median(arr2, s2, e2);
  if(m1==m2)
    return m1;
  if(m1<m2)
  {
    if((e1-s1)%2==0)
      return getMedian(arr1, arr2, n/2-1, e1, s2, n-n/2+1);
    return getMedian(arr1, arr2, n-n/2, e2, s2, n-n/2);
  }
  if((e1-s1)%2==0) /*if(m1>m2*/
    return getMedian(arr1, arr2, s1, n-n/2+1, n/2-1, e2);
  return getMedian(arr1, arr2, s1, n-n/2, n/2, e2);
}
