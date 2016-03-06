#include <stdio.h>
#include <limits.h>
int reverse(int x)
{
        int digits,i=0,neg=0;
        long sum=0;
        while(x)
        {
            sum = sum *10 + x%10;
            if(sum > INT_MAX || sum < INT_MIN)
                return 0;
            x= x/10;
        }
        return sum;
}
int main()
{
	int x=0;
	printf("\n before=%d\n",x);
	 printf("The minimum value of INT = %ld\n", LONG_MAX);
   printf("The maximum value of INT = %d\n", INT_MAX);
	x = reverse(1000000003);
	printf("\n reverse=%d\n",x);
	return 0;
}
