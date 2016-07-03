#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util.h>
/**
 *  * Definition for an interval.
 *   * struct Interval {
 *    *     int start;
 *     *     int end;
 *      * };
 *       */
/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
struct Interval {
  int start;
  int end;
};

typedef struct Stack{
  struct Interval **arr;
  int top;
  int size;
}Stack;

Stack *createStack(int size)
{
  Stack *s = (Stack*)malloc(sizeof(Stack));
  s->top=-1;
  s->size=size;
  s->arr=(struct Interval**)malloc(sizeof(struct Interval*)*size);
  return s;
}
void push(Stack *s, struct Interval *t)
{
  if(s->size-1==s->top)
    return;
  s->top=s->top+1;
  s->arr[s->top]=t;
}

struct Interval *pop(Stack *s)
{ 
  if(s->top==-1)
    return NULL;
  struct Interval *val = s->arr[s->top];
  s->top = (s->top)-1;
  return val;
}
struct Interval *peek(Stack *s)
{ 
  if(s->top==-1)
    return NULL;
  return s->arr[s->top];
}

int cmpfunc(const void *a, const void *b)
{
  struct Interval t1 = *(struct Interval*)a;
  struct Interval t2 = *(struct Interval*)b;
  return t1.start-t2.start;
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
  if(!intervals || intervalsSize==0)
    return NULL;
  struct Interval *arr=NULL;
  if(intervalsSize==1){
    arr=(struct Interval*)malloc(sizeof(struct Interval));
    arr[0]=intervals[0];
    *returnSize=1;
    return arr;
  }
  Stack *s = createStack(intervalsSize);
  int i=0;
  qsort(intervals,intervalsSize, sizeof(struct Interval),cmpfunc);
  push(s, &intervals[0]);
  for(i=1;i<intervalsSize;i++)
  {   struct Interval *t = peek(s);
    if(t->end < intervals[i].start)
      push(s,&intervals[i]);
    else
    { 
      if(t->end<intervals[i].end)
      {
        t = pop(s);
        t->end=intervals[i].end;
        push(s,t);
      }
    }
  }
  arr=(struct Interval*)malloc(sizeof(struct Interval)*((s->top)+1));
  i = 0;
  *returnSize=(s->top)+1;
  while(i<*returnSize){
    struct Interval t = *pop(s);
    arr[i]=t;
    i++;
  }
  if(s)
    free(s);
  return arr;
}

int main()
{
  struct Interval arr[] =  { {1,4}, {5,6}};//, {2,4}, {4,7} };
  int n = sizeof(arr)/sizeof(arr[0]);
  int size;
  struct Interval *arr1 = merge(arr, n, &size);
  int i=0;
  printf("\n size=%d",size);
  for(i=0;i<size;i++)
    printf("\n start=%d end=%d",arr1[i].start, arr1[i].end);
  return 0;
}
