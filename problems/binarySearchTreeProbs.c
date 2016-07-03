#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"
#include "list.h"
#include "stack.h"

int cmpfunc(const void *a, const void *b)
{
  int x = *(int*)a;
  int y = *(int*)b;
  return x-y;
}
#if 0
/**
230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void kthSmallest_helper(struct TreeNode *root, int k, int *count, int *val)
{
    if(root==NULL || *count>=k)
        return;
    kthSmallest_helper(root->left,k, count, val);
    (*count)++;
    if(k==*count){
        *val =root->val;
        return;
    }
    kthSmallest_helper(root->right, k, count, val);
}
int kthSmallest(struct TreeNode* root, int k) {
    int count =0, val=0;
    kthSmallest_helper(root, k, &count, &val);
    return val;
}

#endif

/*Create BST from Sorted LinkedList*/
Node *BSTFromSortLLHelper(List **head, int n)
{
  if(n<=0)
    return NULL;
  Node *left = BSTFromSortLLHelper(head,n/2);
  Node *root = (Node *)malloc(sizeof(Node));
  root->val=(*head)->val;
  root->left=left;
  *head=(*head)->next;
  root->right = BSTFromSortLLHelper(head,n-n/2-1);
  return root;
}

void preorder(Node* root)
{
  if(root==NULL)
    return;
  printf("%d ", root->val);
  preorder(root->left);
  preorder(root->right);
}
void BSTFromSortLL(List **head)
{
  if(!head)
    return;
  int n = countNodes(*head);
  printf("\n count=%d\n",n);
  Node *root = BSTFromSortLLHelper(head,n);
  preorder(root);
}

Node *createNode(int val)
{
  Node *root = (Node*)malloc(sizeof(Node));
  root->val=val;
  root->right=NULL;
  root->left=NULL;
  return root;
}
/*Construct BST from preorder traversal. Using extra stack space in O(n) time.*/
Node *constructBSTPreOrder(int *arr, int size)
{
    if(size==0)
      return NULL;
    if(size==1)
      return createNode(arr[0]);
    int i=0;
    stack *s = createStack(size);
    Node *root = createNode(arr[0]);
    push(s,root);
    Node *tmp=NULL;
    for(i=1;i<size;i++)
    {
      tmp=NULL;
      while(!isEmpty(s) && arr[i]>peek(s)->val)
      {
          tmp = pop(s);
      }
      if(tmp!=NULL)
      {
        Node *node= createNode(arr[i]);
        tmp->right=node;
        push(s,node);
      }
      else
      {
          tmp = peek(s);
          tmp->left=createNode(arr[i]);
          push(s, tmp->left);
      }
    }
    if(s)
      free(s);
    return root;
}

void inorder(Node *root, int *arr, int *size)
{
  if(root==NULL)
    return;
  inorder(root->left, arr, size);
  arr[*size]=root->val;
  (*size)++;
  inorder(root->right, arr, size);
}
/*Bimary Tree to Binary Search tree conversion. The structure should remain same. I.e left subtree of BST should look like like left subtree   of BT and same for right. Idea is:
 *  * 1. do inorder of BT. store in tmp
 *   * 2. sort tmp.
 *    * 3. do inorder again of BT and copy elements from tmp to root visited*/

void convertBSTHelper(Node *root, int *tmp, int *i)
{
  if(root==NULL)
    return;
  convertBSTHelper(root->left,tmp,i);
  root->val=tmp[*i];
  *i=*i+1;
  convertBSTHelper(root->right, tmp, i);
}

void convertBSTBT(Node *root)
{
  int *tmp = (int *)malloc(sizeof(int)*100);
  int size=0,i=0;
  inorder(root,tmp,&size);
  qsort(tmp, size, sizeof(int),cmpfunc);
  printf("size=%d\n",size);
  for(i=0;i<size;i++)
    printf("%d ", tmp[i]);
  i=0;
  convertBSTHelper(root, tmp, &i);
}

/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     struct TreeNode *left;
 *      *     struct TreeNode *right;
 *       * };
 *        */
Node *leftMost(Node *root)
{
  Node *curr=root;
  while(curr->left!=NULL)
    curr=curr->left;
  return curr;
}
Node* inorderSuccessor(Node* root, Node* p)
{
  if(!root || !p)
    return NULL;
  if(p->right!=NULL)
    return leftMost(p->right);
  Node *succ=NULL;//, *root=curr;
  while(root!=NULL)
  {
    if(p->val<root->val)
    {
      succ=root;
      root=root->left;
    }
    else if(p->val >root->val)
      root=root->right;
    else
      break;
  }
  return succ;
}

/*Convert a normal BST to Balanced BST. Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.
 * It can be done in O(n) time and O(n) space. Perform inorder traversal and store it in an array and then construct the BST*/
void constructBalancedBSTInord(Node *root, Node **arr, int *i)
{
  if(root==NULL)
    return;
 constructBalancedBSTInord(root->left,arr, i);
 arr[*i]=root;
 *i=*i+1;
 constructBalancedBSTInord(root->right, arr, i);
}

Node *constructBalancedBST(Node **arr, int start, int end)
{
  if(start >end)
    return NULL;
  int mid = (start+end)/2;
  Node *root= arr[mid];
  root->left = constructBalancedBST(arr, start, mid-1);
  root->right = constructBalancedBST(arr, mid+1, end);
  return root;
}
int main()
{
   Node *root = createBST();
#if 0
  List *head = createList();
  BSTFromSortLL(&head);
  if(head)
    free(head);
  int arr[] = {10, 5, 1, 7, 40, 50};
  Node * root = constructBSTPreOrder(arr,6);
  Node *root = createBT2();
  convertBSTBT(root);
  printf("\n printing tree\n");
  preorder(root);
  int flag=0;
  Node *prev=(Node*)malloc(sizeof(Node));
  Node *tmp=inorderSuccessor(root, root);
  printf("\n succ=%d",tmp->val);
//printf("\n succ=%d\n,",inorderSuccessor(root, root->left)->val);
#endif
  Node **arr = (Node**)malloc(sizeof(Node*)*100);
  int i=0;
  constructBalancedBSTInord(root, arr, &i);
  Node *root1 = constructBalancedBST(arr, 0, i-1);
  preorder(root1);
  return 0;
}
