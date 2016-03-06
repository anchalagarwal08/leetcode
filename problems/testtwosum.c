/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*Leetcode: Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
below prgram is when two arrays are of same size. 
*/
/*This problem is working. update main to run*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;
    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}

void quickSort(int A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}
int* twoSum(int* nums, int numsSize, int target) {
    int *arr = (int *)malloc(2 *sizeof(int));
    int sum=0,l=0, r=numsSize-1,first=0,second=0,i=0,temp=0;
    int *arr1 = (void *)malloc(numsSize *sizeof(int));
    memcpy(arr1,nums,numsSize *sizeof(int));
    quickSort(arr1,0,numsSize-1);
    while(l<r)
    {
        sum=arr1[l]+arr1[r];
        if(sum>target)
            r--;
        else if(sum<target)
            l++;
        else if(sum==target)
        {
            first=arr1[l];
            second=arr1[r];
            break;
        }
    }
    arr[0]=-1;
    arr[1] =-1;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==first & arr[0]==-1)
            arr[0]=i+1;
        if(nums[i]==second)
            arr[1]=i+1;
    }
    if(arr[0]>arr[1]){// this is to handle all negative numbers. if you do not swap you get opposite indexes
        temp=arr[0];
        arr[0]=arr[1];
        arr[1]=temp;
    }
    return arr;
}

int main()
{
	return 0;
}
