/**
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"
#include <limits.h>
int max(int a,int b){
    return (a>=b)?a:b;
}
int height(Node *node)
{
    if(node==NULL)
        return 0;
    return 1+max(height(node->left), height(node->right));
}
bool isBalanced(Node* root) {
    int lh, rh;
    if(root==NULL)
        return true;
    lh = height(root->left);
    rh = height(root->right);
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}


/**
101. Symmetric Tree 
 */
bool isSymmetricHelper(Node *root1, Node *root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1 && root2 && root1->val==root2->val)
        return isSymmetricHelper(root1->left, root2->right) && isSymmetricHelper(root1->right, root2->left);
    return false;
}
bool isSymmetric(Node* root) {
    if(root==NULL)
        return true;
    return isSymmetricHelper(root, root);
}



/**
112. Path Sum 
 */
bool hasPathSumHelper(Node *root, int sum)
{
    if(root==NULL)
        return (sum==0);
    else
    {   bool ans=false;
        int subsum = sum - root->val;
        if(root->left==NULL && root->right==NULL && subsum==0)
            return true;
        if(root->left)
            ans = ans || hasPathSumHelper(root->left,subsum);
        if(root->right)
            ans = ans || hasPathSumHelper(root->right,subsum);
        return ans;
    }
}
bool hasPathSum(Node* root, int sum) {
    if(root==NULL)
        return false;
   int curr=0;
    return hasPathSumHelper(root, sum);
}

/*Print root to leaf paths for binary tree*/
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
/*189. Rotate Array */
void reverseArray(int *arr, int start, int end)
{
  int i=0;
  for(i=0;i<=(end-start)/2;i++)
  {
    int tmp = arr[start+i];
    arr[start+i] = arr[end-i];
    arr[end-i] = tmp;
  }
}
void rotate(int* nums, int numsSize, int k) {
  if(numsSize==1 || k==0 || k==numsSize)
    return;
  if(k>numsSize)
    k=k%numsSize;
  reverseArray(nums,0,numsSize-k-1);
  reverseArray(nums, numsSize-k, numsSize-1);
  reverseArray(nums, 0, numsSize-1);
}

/*102. Binary Tree Level Order Traversal */
void levelOrderTraverse(Node *root, int level, int *arr, int *size)
{
  if(root==NULL || level==0)
    return;
  if(level==1){
    arr[(*size)++]=root->val;
     printf("%d ,", arr[*(size-1)]);
  }
  levelOrderTraverse(root->left, level-1, arr, size);
  levelOrderTraverse(root->right, level-1, arr, size);
}
int** levelOrder(Node* root, int** columnSizes, int* returnSize) {
  int h = height(root);
  int i=1,j=0, size=0, count=0;
  int **arr = (int**)malloc(sizeof(int*)*(h+1));
  *columnSizes = (int*)malloc(sizeof(int)*(h+1));
  *returnSize=0;
  for(i=1;i<=h;i++)
  {
    int *arr1= (int*)malloc(sizeof(int)*pow(2,h));
    levelOrderTraverse(root, i, arr1, &size);
  //  for(j=0;j<size;j++)
  //  {
    //  printf("%d ,", arr1[j]);
   // }
    printf("\n");
    *columnSizes[count++]=size;
    arr[*returnSize++]=arr1;
    size=0;
  }
  (*returnSize)--;
  return arr;
}
int main()
{
  int *arr = (int *)malloc(sizeof(int)*100);
  Node *root = createBT();
  //  printPathBT(root,arr, 0);
//  mirrorBT(root);
 // printTree(root);
 int *column, returnSize=0;
 int **arr1 = levelOrder(root, &column, &returnSize);
 // printf("\nisBST=%d", (int)isBSTUtil(root, INT_MIN, INT_MAX));
  return 0;
}
