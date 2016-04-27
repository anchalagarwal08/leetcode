/*Print root to leaf paths for binary tree*/
#include<stdio.h>
#include <stdlib.h>
#include "node.h"
#include <limits.h>
#include <stdbool.h>
void printPath(int *arr, int length)
{
  int i=0;
  for(i=0;i<length;i++)
  {
    printf("%d,", arr[i]);
  }
  printf("\n");
}

void printPathBT(Node *root, int *arr, int pathlen)
{
  if(root==NULL)
    return;
  arr[pathlen++]=root->val;
  if(root->left==NULL && root->right==NULL)
    printPath(arr, pathlen);
  else{
    printPathBT(root->left, arr, pathlen);
    printPathBT(root->right, arr, pathlen);
  }
}
/*Print path ends*/

/*mirror binary tree. Change the tree to its mirror*/
/*Doing postorder traversal here. to swap left and right children of a node traverse left and right first and swap them when u r at node*/
void mirrorBT(Node *root)
{
  if(root==NULL)
    return;
  mirrorBT(root->left);
  mirrorBT(root->right);
  Node *tmp = root->left;
  root->left = root->right;
  root->right = tmp;
}

/*Find if Binary tree is a BST*/
bool isBSTUtil(Node *root, int min, int max)
{
  if(root==NULL)
    return true;
  if(root->val<min || root->val>max)
    return false;
  else
    return(isBSTUtil(root->left, min, root->val-1) && isBSTUtil(root->right, root->val+1, max));
}
int main()
{
  int *arr = (int *)malloc(sizeof(int)*100);
  Node *root = createBT();
//  printPathBT(root,arr, 0);
  mirrorBT(root);
  printTree(root);
  printf("\nisBST=%d", (int)isBSTUtil(root, INT_MIN, INT_MAX));
  return 0;
}
