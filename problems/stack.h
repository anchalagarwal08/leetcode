#ifndef _STACK_H
#define _STACK_H
#include "node.h"
typedef struct Stack{
  Node **arr;
  int size;
  int top;
}stack;

stack *createStack(int size);
void push(stack *s, Node *val);
Node* pop(stack *s);
bool isEmpty(stack *s);
Node* peek(stack *s);
stack *createStack(int size)
{
  stack *s = (stack*)malloc(sizeof(stack));
  s->arr = (Node **)malloc(sizeof(Node*)*size);
  s->size=size;
  s->top=-1;
  return s;
}

void push(stack *s, Node *val)
{
  if(s->size-1==s->top)
    return;
  s->top=s->top+1;
  s->arr[s->top]=val;
}

Node* pop(stack *s)
{
  if(s->top==-1)
    return NULL;
  Node *val = s->arr[s->top];
  s->top = (s->top)-1;
  return val;
}

bool isEmpty(stack *s)
{
  if(s->top==-1)
    return true;
  return false;
}

Node* peek(stack *s)
{
  return s->arr[s->top];
}

#endif
