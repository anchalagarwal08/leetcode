#include <stdio.h>
#include<stdlib.h>
/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     struct TreeNode *left;
 *      *     struct TreeNode *right;
 *       * };
 *        */
typedef struct stack
{
  struct TreeNode **arr;
  int top;
  int size;
}Stack;

Stack *create_stack(int size)
{
  Stack *s =(Stack*)malloc(sizeof(Stack));
  s->arr = (struct TreeNode **)malloc(sizeof(struct TreeNode*)*size);
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
void push(Stack *s, struct TreeNode* root)
{
  if(s->top==s->size-1)
    return;
  s->top=s->top+1;
  s->arr[s->top]=root;
}

struct TreeNode* pop(Stack *s)
{
  if(!isEmpty(s))
  {
    struct TreeNode *root = s->arr[s->top];
    s->top=s->top-1;
    return root;
  }
  return NULL;
}
struct BSTIterator {
  Stack *s;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
  if(!root)
    return NULL;
  struct BSTIterator *iter = (struct BSTIterator*)malloc(sizeof(struct BSTIterator));
  iter->s = create_stack(100);
  struct TreeNode *tmp=root;
  while(tmp->left!=NULL)
  {
    push(iter->s, tmp);
    tmp=tmp->left;
  }
  return iter;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
  if(!iter)
    return false;
  if(!isEmpty(iter->s))
    return true;
  return false;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
  if(!iter)
    return 0;
  struct TreeNode *node = pop(iter->s);
  int val=node->val;
  if(node->right!=NULL)
  {
    node=node->right;
    while(node!=NULL)
    {
      push(iter->s, node);
      node=node->left;
    }
  }
  return val;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
  if(iter)
    free(iter);
}

int main()
{

  struct BSTIterator *i = bstIteratorCreate(root);
  while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
  bstIteratorFree(i);
  return 0;
}
