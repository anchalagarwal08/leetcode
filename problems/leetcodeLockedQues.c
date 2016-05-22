#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#if 0
struct MapNode
{
  char c;
  int count;
}node;

struct HashMap
{
  node **arr;
  int size;
  int count;
}hashmap;
/*  346 Moving Average from Data Stream 
 *  Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 *
 *  For example,
 *  MovingAverage m = new MovingAverage(3);
 *  m.next(1) = 1
 *  m.next(10) = (1 + 10) / 2
 *  m.next(3) = (1 + 10 + 3) / 3
 *  m.next(5) = (10 + 3 + 5) / 3
 *  */
int movingAvg(int val, int windowsize)
{
 Queue *q = (Queue*)malloc(sizeof(struct Queue)); 
 queueCreate(q, windowsize);
 if(q->size == windowsize)
 {  
   q->sum = q->sum-queuePeek(q);
   queuePop(q); 
 }
 queuePush(q, val);
 q->sum = q->sum +val;
 return val/windowsize;
}

/*  266 Palindrome Permutation 
 *  Leetcode: Palindrome Permutation
 *  Given a string, determine if a permutation of the string could form a palindrome.
 *  For example,
 *  "code" -> False, "aab" -> True, "carerac" -> True.*/
bool isPermutePalindrome(char *str, int len)
{
  if(str==NULL)
    return false;
  if(len==1)
    return true;
  hashmap *h = (hashmap*)malloc(sizeof(hashmap));
  h->arr = (node**)malloc(sizeof(node*));
  h->count=0;
  h->size=100;
  int num_ones=1;
  int i=0;
  for(i=0;i<len;i++)
  { int val=0;
    if(containsKey(h, str[i]))
    {
        val = getValue(h, str[i]);
        map_put(h, str[i],val+1);
    }
    else
      map_put(h, str[i],1);
  }
  for(i=0;i<h->count;i++)
  {
    if((h->arr->node->val)%2!=0)
      num_ones+=1;
  }
  if(len%2==0)
    return num_ones==0;
  else
    return num_ones==1;
}
#endif
/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return false.
 */
typedef struct Interval{
  int start;
  int end;
}interval;
int cmpfunc(const void *a , const void *b)
{
  const interval t1 = *(const interval *)a;
  const interval t2 = *(const interval *)b;
  return (t1.start-t2.start);
}

bool meetingRooms(interval *arr, int size)
{
  if(size==0)
    return true;
  qsort(arr, size, sizeof(interval), cmpfunc);
  int i=0;
  for(i=1;i<size;i++)
  {
    if(arr[i-1].end>arr[i].start)
      return false;
  }
  return true;
}

int main()
{
  interval *arr = (interval *)malloc(sizeof(interval)*3);
  arr[0].start=3;
  arr[0].end=4;
  arr[1].start=1;
  arr[1].end=2;
  arr[2].start=5;
  arr[2].end=6;
  printf("%d", meetingRooms(arr,3));
  return 0;
}
