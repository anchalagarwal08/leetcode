#include <stdio.h>
#include <sdlib.h>
#include <node.h>
Node *insertBST(Node *n, int data)
{
  if(n==NULL)
    return newNode(data);
  if(data < n->val)
    n->left = insert(n->left, data);
  else
    n->right = insert(n->right,data);
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
  Node *root

}
