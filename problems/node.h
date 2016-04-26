
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
  struct node *left;
  struct node *right;
  int val;
}Node;
Node *newNode(int val);
Node *createBST();
Node *createBT();
void printTree(Node *root);
Node *newNode(int val)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->left=NULL;
  n->right=NULL;
  n->val =val;
  return n;
}

Node *insertBST(Node *n, int data)
{
  if(n==NULL)
    return newNode(data);
  if(data < n->val)
    n->left = insertBST(n->left, data);
  else
    n->right = insertBST(n->right,data);
  return n;
}

Node *createBT()
{
  Node *root = newNode(7);
  root->left = newNode(6);
  root->right = newNode(4);
  root->left->left = newNode(3);
  root->left->right = newNode(2);
  root->right->left = newNode(1);
  root->right->right = newNode(5);
  return root;
}

Node *createBST()
{
  Node *root = insertBST(root, 8);
  insertBST(root,5);
  insertBST(root,4);
  insertBST(root,7);
  insertBST(root,2);
  insertBST(root,14);
  insertBST(root,10);
  insertBST(root,9);
  insertBST(root,11);
  insertBST(root,16);
  return root;
}

void printTree(Node *root)
{
  if(root==NULL)
    return;
  printf("%d ,", root->val);
  printTree(root->left);
  printTree(root->right);
}

