/*345. Reverse Vowels of a String   */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
char* reverseVowels(char* s) {
    if(!s)
        return NULL;
    int len = strlen(s);
    if(len==1)
        return s;
    int i=0, j=len-1;
    while(i<j)
    {
        if((s[i]=='a' || s[i]=='e' ||s[i]=='i' || s[i]=='o'|| s[i]=='u'||s[i]=='A' || s[i]=='E' ||s[i]=='I' || s[i]=='O'|| s[i]=='U') && (s[j]=='a' || s[j]=='e' ||s[j]=='i' || s[j]=='o'|| s[j]=='u'|| s[j]=='A' || s[j]=='E' ||s[j]=='I' || s[j]=='O'|| s[j]=='U'))
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j]=tmp;
            i++;
            j--;
        }
        else if((s[i]=='a' || s[i]=='e' ||s[i]=='i' || s[i]=='o'|| s[i]=='u'||s[i]=='A' || s[i]=='E' ||s[i]=='I' || s[i]=='O'|| s[i]=='U'))
            j--;
        else
            i++;
    }
    return s;
}

void reverse(char *s, int start,int end)
{
  if(!s)
    return;
  while(start<end)
  {
    char c=s[end];
    s[end]=s[start];
    s[start] =c;
    end--;
    start++;
  }
}
void reverseWords(char *str) {
  if(!str)
    return;
  char *s=str;
  int len = strlen(s);
  bool rev=false;
  printf("len=%d\n",len);
  int j=0;
  while(*s==' ') { printf("here");s++;}
  if(*s == 0) 
    return;
  int start=0, i=0;
  while(s[start]==' '){
    printf("here\n");
    start++;
  }
  if(start==len)
  {
    //s='\0';
    str=s;
    return;
  }
  for(i=start;i<len;i++)
  {
    if(isspace(s[i]))
    {
      rev=true;
      reverse(s,start,i-1);
      while(isspace(s[i]))
        i++;
      start=i;
    }
    if(i==len-1 && rev)
    {
      reverse(s,start,i);
    }
  }
  if(rev)
    reverse(s,0,len-1);
  str=s;
}
typedef struct stack
{
  char **arr;
  int top;
  int size;
}Stack;

Stack *create_stack(int size)
{
  Stack *s =(Stack*)malloc(sizeof(Stack));
  s->arr = (char**)malloc(sizeof(char*)*size);
  s->top=-1;
  s->size=size;
  return s;
}
bool isEmpty(Stack *s)
{
  if(s->top==-1)
    return true;
  return false;
}
void push(Stack *s, char *c)
{
  if(s->top==s->size-1)
    return;
  s->top=s->top+1;
  s->arr[s->top]=c;
}

char *pop(Stack *s)
{
  if(!isEmpty(s))
  {
    char *c = s->arr[s->top];
    s->top=s->top-1;
    return c;
  }
  return NULL;
}
char* simplifyPath(char* path) {
  if(!path)
    return NULL;
  int len=strlen(path);
  char *simplePath;
  if(len==1)
    return "/";
  Stack *s = create_stack(len);
  int i=0,j=0;char *c;
  for(i=0;i<len;i++)
  {
    if(path[i]=='/' || (path[i]=='.' && path[i+1]!='.'))
      continue;
    else if(path[i]=='.' && path[i+1]=='.')
    {
      if(!isEmpty(s))
      {
        c= pop(s);
      }
    }
    else
    {
      char tmp[50]={0};
      while(path[i]!='/'&& path[i]!='.')
      {
        tmp[j]=path[i];
        i++;
        j++;
      }
      push(s, tmp);
      j=0;
    }
  }
  i=0;
  if(!isEmpty(s))
  {
    while(!isEmpty(s))
    {
      simplePath=(char*)malloc(sizeof(char)*len);
      strcat(simplePath,"/");
      strcat(simplePath,pop(s));
    }
    return simplePath;
  }
  return "/";
}
int main()
{
/*  char s[]={'h','e','l','l','o','\0'};
  char s1[]="hello world!\0";
  reverseWords(s1);
  printf("\nstring=%s, len=%d\n", s1, (int)strlen(s1));
*/
  char *path="/home/";
  printf("\n path=%s",simplifyPath(path));
}
