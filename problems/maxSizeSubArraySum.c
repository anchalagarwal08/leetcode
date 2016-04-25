/*325 Maximum Size Subarray Sum Equals k
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)
*/

#include <stdio.h>
#include <hashmap.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int findMaxLength(int *arr, int size, int k)
{
	if(arr==NULL)
	 return 0;
	hashmap *h = create_map(size);
	int sum=0, i=0, maxlength=0;
	for(i=0;i<size;i++)
	{
		sum+=arr[i];
		if(sum==k)
		  maxlength = MAX(maxlength, i+1);
		else if(map_contains(sum-k))
                  maxlength= MAX(maxlength, i-map_get(h,sum-k));
		if(!map_containsKey(h, sum))
		   map_put(h, sum, i);
	}
return maxlength;
}
