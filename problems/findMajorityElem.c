#include<stdio.h>
#include<stdlib.h>

/*Use moore's voting algorithm. cancel occurrence of max element for each of the other elem in the array. If a majority exists it will be the last to remain*/
int majorityElement(int* nums, int numsSize) {
   int i=0,maj=0,count=1;
   for(i=1; i<numsSize;i++)
   {
       if(nums[maj]==nums[i])
            count++;
        else
            count--;
        if(count==0)
        {
            maj=i;
            count=1;
        }
   }
   return nums[maj];
}

/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.*/
//there can be max 2 elements with more than n/3 
int* majorityElements(int* nums, int numsSize, int* returnSize) {
   int c1=0,c2=0,m1=0,m2=0,i=0;
   int *arr;
   for(i=0;i<numsSize;i++)
   {
       if(m1==nums[i])
            c1++;
       else if(m2==nums[i])
            c2++;
       else if(c1==0)
       {
           c1=1;
           m1=nums[i];
       }
       else if(c2==0)
       {
           c2=1;
           m2=nums[i];
       }
       else
       {
            c1--;c2--;
       }
   }
  printf("c1=%d, c2=%d",c1,c2);
  c1=0;c2=0;
  for(i=0;i<numsSize;i++)
  {
      if(nums[i]==m1)
        c1++;
      else if(nums[i]==m2)
        c2++;
  }
  printf("m1=%d, m2=%d",m1,m2);
  if(c1>numsSize/3)
    (*returnSize)++;
  else
    m1=m2;
  if(c2>numsSize/3)
    (*returnSize)++;
   printf("return=%d\n",*returnSize);
  if(*returnSize==0)
    return NULL;
 
  arr = (int *)malloc(sizeof(int)*(*returnSize));
  arr[0]=m1;
  if(*returnSize>1)
    arr[1]=m2;
  return arr;
}

int main()
{
	int nums[]={8,9,8,9,8};
	int returnSize=0;
	int *arr = majorityElements(nums, 5, &returnSize);
	return 0;

}
