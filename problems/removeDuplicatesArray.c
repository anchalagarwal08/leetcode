/*Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
217. Contains Duplicate
*/

int comparator (const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
bool containsDuplicate(int* nums, int numsSize) {
   int i=0;
   if(numsSize<=1)
     return false;
   qsort(nums, numsSize, sizeof(int), comparator);
   for(i=0; i<numsSize; i++)
   {
       if(nums[i]==nums[i+1])
            return true;
   }
    return false;
}

/*219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. We can use hashing too */


bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
 int i=0,j=1;
 if(k==0)
    return false;
 for(i=0;i<numsSize;i++)
 {
     while(j<=k && (i+j)<numsSize) /*This check will work even if k>numsSize so we don't neeed extra check for that*/
     {
         if(nums[i]==nums[i+j])
            return true;
        j++;
     }
     j=1;
 }
 return false;
}
