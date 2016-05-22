#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define R 6
#define C 5
/*Largest Sum Contiguous Subarray
 * Write an efficient C program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum. 
 * this will take care if there are all negative numbers too. If all negative return the max element*/
#define MAX(a,b) (a>b)?a:b
int maxSumSubArray(int *arr, int size)
{
  int i=0;
  int curr_max=arr[0];
  int max_sum=arr[0];
  for(i=1;i<size;i++)
  {
    curr_max = MAX(arr[i], curr_max+arr[i]);
    max_sum= MAX(curr_max, max_sum);
  }
  return max_sum;
}

/*Maximum size square sub-matrix with all 1s
 * Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
 *
 *    0  1  1  0  1 
 *    1  1  0  1  0 
 *    0  1  1  1  0
 *    1  1  1  1  0
 *    1  1  1  1  1
 *    0  0  0  0  0
 *
 *    The maximum square sub-matrix with all set bits is
 *    1  1  1
 *    1  1  1
 *    1  1  1*/
int min(int a, int b, int c)
{
  int min=0;
  if(a<b)
    min=a;
  else
    min=b;
  return (min<c ? min : c);
}

int max(int a, int b)
{
  return a>b ? a : b;
}
int maxSizesubMatrix(int m[R][C], int r, int c)
{
  int s[R][C]={0};
  int i=0, j=0;
  int max=0, max_i=0, max_j=0;
  /*copy the first row and column of matrix m to s*/
  for(i=0;i<c;i++)
    s[0][i]=m[0][i];
  for(i=0;i<r;i++)
    s[i][0]=m[i][0];
  for(i=1;i<r;i++)
  {
    for(j=1;j<c;j++)
    {
      if(m[i][j]==1)
        s[i][j]=min(s[i-1][j], s[i][j-1], s[i-1][j-1])+1;
      else
        s[i][j]=0;
    }
  }
  /*find max value in s[][]*/
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(s[i][j]>max)
      {
        max=s[i][j];
        max_i=i;
        max_j=j;
      }
    }
  }
  /*print the matrix m[][]*/
  for(i=max_i-max+1;i<=max_i;i++)
  {
    for(j=max_j-max+1; j<=max_j;j++)
    {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
return max;
}

int LongestCmnSubsqnc(char *x, char *y, int m, int n)
{
  if(!x || !y)
    return 0;
  int L[m+1][n+1];
  int i=0,j=0;
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      if(i==0||j==0)
        L[i][j]=0;
      else if(x[i-1]==y[j-1])
        L[i][j] = L[i-1][j-1]+1;
      else
        L[i][j]= max(L[i-1][j], L[i][j-1]);
    }
  }
  return L[m][n];
}

/*Edit Distance
 * Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.
 *
 * Insert
 * Remove
 * Replace
 * All of the above operations are of equal cost.*/

int minDistance(char* word1, char* word2) {
  if(word1=="" && word2=="")
    return 0;
  int len1 = strlen(word1);
  int len2= strlen(word2);
  int X[len1+1][len2+1];
  int i=0, j=0;
  for(i=0;i<=len1;i++)
  {
    for(j=0;j<=len2;j++)
    {
      if(i==0)
        X[i][j]=j;
      else if(j==0)
        X[i][j]=i;
      else 
        X[i][j]=min((X[i-1][j-1]+(word1[i-1]!=word2[j-1])), X[i-1][j]+1, X[i][j-1]+1);
    }
  }
  return X[len1][len2];
}
int main()
{
  int a[] =  {-2, -3, -4, -1, -7, -5, -3};
  int m[6][5] =  {{0, 1, 1, 0, 1}, 
    {1, 1, 0, 1, 0}, 
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}};
  int n = sizeof(a)/sizeof(a[0]);
 // int max_sum = maxSumSubArray(a, n);
 // printf("max_sum=%d\n", max_sum);
 // printf("\n max=%d \n", maxSizesubMatrix(m, 6, 5));
  char x[] = "AGGTAB";
  char y[] = "GXTXAYB";

  int m1 = strlen(x);
  int n1 = strlen(y);

  printf("Length of LCS is %d\n", LongestCmnSubsqnc( x, y, m1, n1 ) );
  return 0;
}
