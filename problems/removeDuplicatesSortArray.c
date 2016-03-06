#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int prev=1,i=0;
    if(numsSize<=0)
        return 0;
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            nums[prev]=nums[i];
            prev++;
        }
    }
    return prev;
}
