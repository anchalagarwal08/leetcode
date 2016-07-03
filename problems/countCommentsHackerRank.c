#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  char arr[300];
  printf("Enter any paragraph which can include spaces or new line.\n");
  printf("To exit press the tab key.\n");
  scanf("%[^\t]s",arr);
  printf("You had entered: \n");
  printf("%s",arr);
  printf("\n *************\n\n");
  int i=0;
  int len = strlen(arr);
  for(i=0;i<len;i++)
  {
    if(arr[i]=='/' && arr[i+1]=='/')
    {
      while(arr[i]!='\n')
      {
        printf("%c", arr[i]);
        i++;
      }
    }
    if(arr[i]=='/' && arr[i+1]=='*')
    {
      printf("%c %c", arr[i], arr[i+1]);
      i=i+2;
      while(arr[i]!='*' && arr[i+1]!='/')
      {
        printf("%c", arr[i]);
        i++;
      }
       printf("%c %c", arr[i], arr[i+1]);
       i=i+2;
    }
  }
return 0;
}
