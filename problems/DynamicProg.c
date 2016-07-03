#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define R 6
#define C 5

/*DP basics:
 * always allocate extra space for R+1, C+1
 * run loop from 1<i<=j and not 1<i<j
 * make a matrix
 * last element in tmp[R][C] is the result*/
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

int editDistance(char* word1, char* word2) {
 // if(word1=="" && word2=="")
   // return 0;
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

/*Longest Increasing Subsequence
 * This algo is O(n^2) complexity. best[] keeps length of longest subsequence at ith instance. The inner loop checks for all the elements from i-j everytime, hence O(n2). Space complexity is O(n). There is O(nlogn) algo too*/
int lengthOfLIS(int* nums, int numsSize) {
  if(!nums || numsSize==0)
    return 0;
  int best[numsSize];
  int i=0, j=0, max=1;
  for(i=0;i<numsSize;i++)
    best[i]=1;
  for(i=1;i<numsSize;i++)
  {
    for(j=0;j<i;j++)
    {
      if(nums[i]>nums[j] && best[i]<best[j]+1)
        best[i]=best[j]+1;
      if(max<best[i])
        max=best[i];
    }
  }
  return max;
}

/*geeks:Min Cost Path. 
 * Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
 *
 */

int mincostPath(int cost[R][C], int m, int n)
{
  int total[R][C];
  total[0][0]=cost[0][0];
  int i=0, j=0;
  for(i=1;i<m;i++)
    total[i][0]= total[i-1][0]+cost[i][0];
  for(i=1;i<n;i++)
    total[0][i]=total[0][i-1]+cost[0][i];
  for(i=1;i<=m;i++)
  {
    for(j=1;j<=m;j++)
    {
      total[i][j]=min(total[i-1][j], total[i][j-1], total[i-1][j-1])+cost[i][j];
    }
  }
  return total[m][n];
}

/*Length of Longest substring with non repeating chars
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7.
keep track of max len till now, curr_len of current longest substring, vis array for all chars with indexes as the values for each char visited in the string
*/

int longestUniqueSubsttr(char *c, int len)
{
  if(!c || len==0)
    return 0;
  if(len==1)
    return 1;
  int max_len=1, curr_len=1, prev_idx=0;
  int *vis = (int *)malloc(sizeof(int)*256);
  int i=0;
  for(i=0;i<256;i++)
    vis[i]=-1;
  vis[c[0]]=0;
  /*The cases considered:
   * 1. Char in current substring not seen before, cur_len++
   * 2. Char in current substring seen before but not a part of curr substring, cur_len++
   * 3. char in current substring seen before and is a part of curr substring, update max len, cur_len and tsrat from next char for new substring*/
  for(i=1;i<len;i++)
  {
    prev_idx = vis[c[i]];
    if(prev_idx==-1 || i-curr_len>prev_idx)
      curr_len++;
    else{
      if(curr_len>max_len)
        max_len=curr_len;
      curr_len=i-prev_idx;
    }
    vis[c[i]]=i;
  }
  if(curr_len>max_len)
    max_len=curr_len;
  free(vis);
  return max_len;
}

/*Longest common prefix. Solution without trie here. Complexity= O(nk), k=length of first string , n=number of strings*/
char* longestCommonPrefix(char** strs, int strsSize) {
  if(!strs || strsSize==0)
    return "";
  int i=0, j=0, common=0,k=0;
  int len=strlen(strs[0]);
  bool dobrk=false;
  char *c;
  for(i=0;i<len;i++)
  {
    for(j=0;j<strsSize;j++)
    {
      if(strs[0][i]!=strs[j][i]){
        dobrk=true;
        break;
      }
    }
    if(dobrk)
      break;
  }
  printf("%d",i);
  if(i==0)
    return "";
  else{
    c=(char *)malloc(sizeof(char)*i);
    strncpy(c, strs[0],i);
    c[i]='\0';
  }
  return c;
}

int robHelper(int *nums, int numsSize, bool val)
{
  int *m=NULL ;
  int k=0;
  /*include 1st house but not last*/
  if(val)
  {
    m = (int *)malloc(sizeof(int)*(numsSize-1));
    int i=0;
    k=numsSize-1;
    m[0]=0;
    m[1]=nums[0];
    for(i=2;i<numsSize; i++)
    {
      m[i]=MAX(m[i-1], m[i-2]+nums[i-1]);
    }
  }
  /*include last house but not first*/
  else{
    m = (int *)malloc(sizeof(int)*(numsSize+1));
    int i=0;
    m[0]=0;
    m[1]=0;
    m[2]=nums[1];
    k=numsSize;
    for(i=3;i<=numsSize; i++)
    { 
      m[i]=MAX(m[i-1], m[i-2]+nums[i-1]);
    }
  }
  printf("val =%d", m[k]);
  return m[k];
}

int rob(int* nums, int numsSize) {
  if(!nums || numsSize==0)
    return 0;
  int max1= robHelper(nums, numsSize, true);
  int max2 = robHelper(nums, numsSize, false);
  printf("max1 =%d, max2=%d", max1, max2);
  return max1>max2?max1:max2;
}

char* longestPalindrome(char* s) {
  if(!s)
    return NULL;
  int len=strlen(s);
  if(len==1)
    return s;
  char *s3=NULL;
  if(len==2){
    if(s[0]==s[1])
      return s;
    else{
      s3 = (char*)malloc(sizeof(char));
      s3[0]=s[0];
      return s3;
    }
  }
  int table[1000][1000]={{0}};
  int i=0,j=0, result=0,last_x=0,last_y=0, k=0;
  for(i=0;i<=len;i++)
  {
    for(j=0;j<=len;j++)
    {
      if(i==0||j==0)
        table[i][j]=0;
      if(s[i-1]==s[len-j-1])
      {
        table[i][j]=table[i-1][j-1]+1;
        if(result<table[i][j])
        {
          result=table[i][j];
          last_x=i;
          last_y=j;
        }
      }
      else{                    
        table[i][j]=0;
      }
    }
  }
  printf("\nlast_x=%d, last_y=%d , result=%d",last_x, last_y,result);
  last_x--;
  last_y--;
  while(table[last_x][last_y]!=0)
  {
    last_x--;
    last_y--;
  }
  printf("\n x=%d y=%d \n",last_x, last_y);
  s3=(char *)malloc(sizeof(char)*result);
  for(i=last_x;i<result+last_x;i++){
    s3[k]=s[i];
    k++;
  }
  s3[k]='\0';
  printf("\ns3=%s k=%d",s3,k);
  return s3;
}

/*Subset Sum problem: Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
 *
 * Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
 * Output:  True  //There is a subset (4, 5) with sum 9.
 * There is an NP complete solution for this, exclude last element recur for n-1 , include last element adn recur for n-1*/

bool isSubsetSum(int *arr, int n, int sum)
{
  if(sum==0)
    return 1;
  if(!arr || n==0)
    return 0;
  if(n==1)
  {
    if(arr[0]==sum)
      return 1;
    return 0;
  }
  bool subset[sum+1][n+1];
  int i=0, j=0;
  for(i=0;i<=n;i++)
    subset[0][i]=true;
  for(j=0;j<=sum;j++)
    subset[j][0]=false;

  for(i=1;i<=sum;i++)
  {
    for(j=1;j<=n;j++)
    {
        subset[i][j]=subset[i][j-1];
        if(i>=arr[j-1])
          subset[i][j] = subset[i][j] || subset[i-arr[j-1]][j-1];/*if part of sum had been found before*/
    }
  }
  return subset[sum][n];
}

/*Longest increasing zig zag subsequence
 * Input: arr[] = {10, 22, 9, 33, 49, 50, 31, 60}
 * Output: 6
 * The subsequences {10, 22, 9, 33, 31, 60} or
 * {10, 22, 9, 49, 31, 60} or {10, 22, 9, 50, 31, 60}
 * are longest Zig-Zag of length 6.
 *
 * The idea is: take double dimension array Z[n][2], z[n][0] will have elements where a[i]>a[j] , i>j, i.e last element is strictly greater than the previous element. Z[n][1] will have strictly smaller element than the last element i.e a[j]>a[i] where j>i*/
// complenixty is O(n^2) and space O(n)
int longestZigZagSeq(int *arr, int n)
{
  if(!arr || n==0)
    return 0;
  if(n==1)
    return 1;
   int i=0,j=0, res=1;
 // int **z = (int**)malloc(sizeof(int*)*2);
 // for(i=0;i<2;i++)
  //  z[i]= (int *)malloc(sizeof(int)*n);
  int z[n][2];
   for(i=0;i<n;i++)
  {
    z[i][0]=1;
    z[i][1]=1;// initialize all values to 1 max subseq length =1
  }
  for(i=1;i<n;i++)
  {
    for(j=i-1; j>=0;j--)
    {
      if(arr[i]>arr[j])
        z[i][0]=max(z[j][1]+1, z[i][0]);//counting previous smallest value which is at z[j][1]
      if(arr[j]>arr[i])
        z[i][1] =max(z[j][0]+1, z[i][1]);
    }
    res = max(z[i][0], z[i][1]);
  }
  //  free(z);
  return res;
}

int main()
{
#if 0
  int a[] =  {-2, -3, -4, -1, -7, -5, -3};
  int m[6][5] =  {{0, 1, 1, 0, 1}, 
    {1, 1, 0, 1, 0}, 
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}};
  int n = sizeof(a)/sizeof(a[0]);
  int max_sum = maxSumSubArray(a, n);
  printf("max_sum=%d\n", max_sum);
  printf("\n max=%d \n", maxSizesubMatrix(m, 6, 5));
  char x[] = "AGGTAB";
  char y[] = "GXTXAYB";

  int m1 = strlen(x);
  int n1 = strlen(y);

  printf("Length of LCS is %d\n", LongestCmnSubsqnc( x, y, m1, n1 ) );
  char str[] = "ABDEFGABEF";
  printf("The input string is %s \n", str);
  int len =  longestUniqueSubsttr(str, strlen(str));
  printf("The length of the longest non-repeating "
      "character substring is %d", len);
  int arr[]= {1,2,7,5,3,1};
//  printf("\n max=%d\n", rob(arr, 6));
  char *s = "anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgxkzdbcjsjjovnhpnbkurxqfupiprpbiwqdnwaqvjbqoaqzkqgdxkfczdkznqxvupdmnyiidqpnbvgjraszbvvztpapxmomnghfaywkzlrupvjpcvascgvstqmvuveiiixjmdofdwyvhgkydrnfuojhzulhobyhtsxmcovwmamjwljioevhafdlpjpmqstguqhrhvsdvinphejfbdvrvabthpyyphyqharjvzriosrdnwmaxtgriivdqlmugtagvsoylqfwhjpmjxcysfujdvcqovxabjdbvyvembfpahvyoybdhweikcgnzrdqlzusgoobysfmlzifwjzlazuepimhbgkrfimmemhayxeqxynewcnynmgyjcwrpqnayvxoebgyjusppfpsfeonfwnbsdonucaipoafavmlrrlplnnbsaghbawooabsjndqnvruuwvllpvvhuepmqtprgktnwxmflmmbifbbsfthbeafseqrgwnwjxkkcqgbucwusjdipxuekanzwimuizqynaxrvicyzjhulqjshtsqswehnozehmbsdmacciflcgsrlyhjukpvosptmsjfteoimtewkrivdllqiotvtrubgkfcacvgqzxjmhmmqlikrtfrurltgtcreafcgisjpvasiwmhcofqkcteudgjoqqmtucnwcocsoiqtfuoazxdayricnmwcg";
  printf("\n\n longest palind=%s\n", longestPalindrome(s));
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum))
    printf("Found a subset with given sum");
  else
    printf("No subset with given sum");
#endif
  int arr[] = { 10, 22, 9, 33, 49, 50, 31, 60 };
  printf("\n longest zig zag subseq=%d\n",longestZigZagSeq(arr, 8));
  return 0;
}
