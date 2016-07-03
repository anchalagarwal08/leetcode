#include <stdio.h>
#include <stdlib.h>
#define COL 3
int* spiralOrder(int matrix[][COL], int matrixRowSize, int matrixColSize) {
  if(!matrix)
    return NULL;
  int k=0; /*start row*/
  int l=0; /*end row*/
  int m=matrixRowSize;/*end row*/
  int n =matrixColSize; /*end col*/
  int size = matrixRowSize*matrixColSize;
  printf("size=%d m=%d n=%d\n",size, m, n);
  int *arr = (int*)malloc(sizeof(int)*size);
  int count=0;
  int i=0;
  while(k<m && l<n)
  {
    for(i=l;i<n-1;i++){ /*1st row of remaining row*/
      printf("%d ", matrix[k][i]);
      arr[count++]=matrix[k][i];
    }
    k++;
    for(i=k;i<m-1;i++){/*last columns of remaining columns*/
      printf("%d ", matrix[n-1][i]);
      arr[count++]=matrix[n-1][i];
    }
    n--;
    if(k<m) /*last row of remaining row*/
    {
      for(i=n-1;i>=1;i--){
        printf("%d ", matrix[m-1][i]);
        arr[count++]=matrix[m-1][i];
      }
      m--;
    }
    if(l<n)/*print first column of remaining column*/
    {
      for(i=m-1;i>=1;i--){
        printf("%d ",matrix[i][l]);
        arr[count++]=matrix[i][l];
      }
      l++;
    }
  }
  return arr;
}

int main()
{
  int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  int *arr1 = spiralOrder(arr,3,3);
  return 0;
}
