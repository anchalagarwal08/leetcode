#ifndef _NODE_H
#define _NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
  struct node *left;
  struct node *right;
  struct node *next; /*for populate inorder successor BT ques*/
  int height; /*for AVL trees ques*/
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
  n->height=0;//1;
  n->next=NULL;
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
  Node *root = newNode(5);
  root->left = newNode(4);
  root->right = newNode(8);
  root->left->left = newNode(11);
  root->left->left->left = newNode(7);
  root->left->left->right = newNode(2);
  root->right->left = newNode(13);
  root->right->right = newNode(4);
  root->right->right->left = newNode(5);
  return root;
}


Node *createBT2()
{
//this data for max diff from ancestor node
  Node *root = newNode(8);
  root->left = newNode(3);

  root->left->left = newNode(1);
  root->left->right = newNode(6);
  root->left->right->left = newNode(4);
  root->left->right->right = newNode(7);

  root->right = newNode(10);
  root->right->right = newNode(14);
  root->right->right->left = newNode(13);
  /*Node *root = newNode(3);
  root->left = newNode(9);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(7);
  root->right->right = newNode(6);
  root->right->right->left = newNode(8);
  */
 /* Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->left->right->left = newNode(12);
  root->right->right->left = newNode(10);
  root->right->right->left->right = newNode(11);
  root->left->left->right->left = newNode(13);
  root->left->left->right->right = newNode(14);
  root->left->left->right->right->left = newNode(15);
  */return root;
}

Node *createBT3()
{
  Node *root = newNode(1);
  root->left = newNode(3);
  root->right = newNode(2);
  root->left->right = newNode(6);
  root->right->left = newNode(25);
  root->right->right = newNode(4);
  return root;
}
Node *createBST()
{
  Node *root = newNode(10);
  root->left = newNode(8);
  root->left->left = newNode(7);
  root->left->left->left = newNode(6);
  root->left->left->left->left = newNode(5);
 // insertBST(root,9);
/*  insertBST(root,4);
  insertBST(root,7);
  insertBST(root,2);
  insertBST(root,14);
  insertBST(root,10);
  insertBST(root,9);
  insertBST(root,11);
  insertBST(root,16);
 */ return root;
}

void printTree(Node *root)
{
  if(root==NULL)
    return;
  printf("%d ,", root->val);
  printTree(root->left);
  printTree(root->right);
}

#endif
