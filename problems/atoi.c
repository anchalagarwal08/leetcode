#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int myAtoi(char* str) {
    char *tmp = str;
    int l=0,i=0,n=0,j=0;
    unsigned long sum=0;
    int neg=0;
    while(*tmp!='\0')
    {
        l++;
        tmp++;
    }
    if(str[0]=='-'){
	neg=1;
	j++;
    }
    else if(str[0]=='+'){
	j++;
	neg=2;
    }
    for(i=j;i<l;i++)
    {
	    if(str[i]>=48 & str[i]<=57){
		  sum=sum*10 + (str[i]-'0');
	    	  printf("\n sum=%lld\n",sum);
	    }
	    else
		    continue;

    }
    printf("\n sum=%lld\n",sum);
    if(neg)
	sum=sum*-1;
    if(sum>INT_MAX || sum>LONG_MAX)
	sum=INT_MAX;
    else if(sum<INT_MIN || sum<LONG_MIN)
	sum=INT_MIN;
    return sum;
}

int main()
{
	int ret=0;
	char *str = malloc(sizeof(char)*100);
	str = "9223372036854775809\0";
	ret = myAtoi(str);
	printf("\n l=%d\n",ret);
}
