#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/** Encodes a list of strings to a single string */
char* encode(char** strs, int strsSize) {
  if (!strs || strsSize==0){
    char *str="";
    return str;
  }
  int i=0, len=0;
  for(i=0;i<strsSize;i++)
    len+=strlen(strs[i]);
  int size=len+strsSize*3+2;
  char *retStr = (char*)malloc(sizeof(char)*size);
  char num[2];
  sprintf(num, "%d",strsSize);
  strcat(retStr, num); //prepend number of strings
  strcat(retStr, "#");
  for(i=0;i<strsSize;i++)
  {
    memset(num,0,2);
    sprintf(num, "%d", strlen(strs[i]));
    strcat(retStr, num);
    strcat(retStr, "#");
    strcat(retStr, strs[i]);
    strcat(retStr, "#");
//    printf("\n retStr=%s",retStr);
  }
  retStr[size]='\0';
  return retStr; 
}

/**
 *  * Decodes a single string to a list of strings.
 *   *
 *    * Return an array of size *returnSize.
 *     * Note: The returned array must be malloced, assume caller calls free().
 *      */
char** decode(char* s, int* returnSize) {
  if(s==NULL || strlen(s)==0)
    return NULL;
  int size = s[0]-'0';
  int i=0,j=0,count=0;
  char **arr = (char**)malloc(sizeof(char*)*size);
  *returnSize=size;
  for(i=2;i<strlen(s);i++)
  {
    int len = s[i]-'0';i=i+2;
    char *str=(char*)malloc(sizeof(char)*len);
    while(s[i]!='#')
    {
      str[j++]=s[i++];
    }
    arr[count++]=str;
    j=0;
  }
  return arr;
}

int main()
{
  int returnSize=0;
  char *strs[]={"I"};
  char* s = encode(strs, 1);
  printf("\n \n ****string*** = %s\n", s);
  char **arr = decode(s, &returnSize);
  printf("returnsize=%d\n", returnSize);
  for(int i=0;i<returnSize;i++)
  {
    printf("\n s = %s", arr[i]);

  }
  return 0;
}
