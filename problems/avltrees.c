#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "node.h"
#define max(a,b) a>b?a:b
int height (Node *root)
{
  if(!root)
    return -1;
  return root->height;
}
int getBalance(Node *root)
{
  if(root==NULL)
    return 0;
  return (height(root->left) - height(root->right));
}


Node *rotateLeft(Node *root)
{
  if(root==NULL)
    return NULL;
  Node *x = root->right;
  Node *T2 = x->left;
  x->left=root;
  root->right =T2;
  root->height = max(height(root->left), height(root->right))+1;
  x->height = max(height(x->left), height(x->right))+1;
  return x; /*new root*/
}

Node *rotateRight(Node *root)
{
  if(root==NULL)
    return NULL;
  Node *x = root->left;
  Node *T2 = x->right;
  x->right = root;
  root->left=T2;
  root->height = max(height(root->left), height(root->right))+1;
  x->height = max(height(x->left), height(x->right))+1;
  return x; /*new root*/
}

Node *insertNode(Node *root, int val)
{
  if(root==NULL)
    return newNode(val);
  if(val<root->val)
    root->left = insertNode(root->left, val);/*insert in left subtree*/
  else
    root->right = insertNode(root->right, val);/*insert in roght subtree*/

  root->height = max(height(root->left), height(root->right))+1;
  int diff = getBalance(root);/*get height difference after node is inserted*/

  /*Left Left case. key was inserted in left subtree and Left subtree height > right subtree*/
  if(diff>1 && val<root->left->val)
  {
    return rotateRight(root);
  }
/*Right Right case. key was inserted in right subtree and Left subtree height < right subtree*/
  if(diff<-1 && val>root->right->val)
  {
    return rotateLeft(root);
  }
  /*Left Right Case. Inserted key in right subtree of left subtree*/
  if(diff>1 && val>root->left->val)
  {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
  }
/*Right Left Case. Inserted key in left subtree of right subtree*/
  if(diff<-1 && val<root->right->val)
  {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
  }
  return root;
}

void preOrder(struct node *root)
{
  if(root != NULL)
  {
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
  }
}

/* Drier program to test above function*/
int main()
{
  Node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insertNode(root, 10);
  root = insertNode(root, 20);
  root = insertNode(root, 30);
  root = insertNode(root, 40);
  root = insertNode(root, 50);
  root = insertNode(root, 25);

  /* The constructed AVL Tree would be
   *             30
   *            /  \
   *          20   40
   *        /  \     \
   *       10  25    50
   *                                                  */

  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
  printf("\n");
  return 0;
}
