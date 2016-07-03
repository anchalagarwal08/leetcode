#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
  struct Node *left;
  struct Node *right;
  int val;
  int leftsize;
}Node;

/*10.10 sorting &searching: Rank from stream. Idea is to use BST and store the left subtree size in each node because elemnts on left will be smaller than any given node.*/

Node *createNode(int x)
{
  Node *n = (Node*)malloc(sizeof(Node));
  n->left=NULL;
  n->right=NULL;
  n->val=x;
  n->leftsize=0;
  return n;
}
Node* insertBST(Node *root, int x)
{
  if(!root)
    return createNode(x);
  if(x<root->val){
    root->left=insertBST(root->left,x);
    root->leftsize= root->leftsize+1;
    }
  else
      root->right = insertBST(root->right, x);
  return root;
}

int getRank(Node *root, int x)
{
  if(!root)
    return -1;
  if(root->val==x)
    return root->leftsize;
  if(x<root->val)
    return getRank(root->left,x);
  else
    return root->right==NULL?-1:root->leftsize+1+getRank(root->right,x);

}
void inorder(Node *root)
{
  if(!root)
    return;
  inorder(root->left);
  printf("\n node->va=%d node->leftsize=%d",root->val, root->leftsize);
  inorder(root->right);
}
int main()
{
  Node *root = NULL;
  root = insertBST(root, 50);
  insertBST(root, 30);
  insertBST(root, 20);
  insertBST(root, 40);
  insertBST(root, 70);
  insertBST(root, 60);
  insertBST(root, 80);
  inorder(root);
  printf("\n rank of %d=",getRank(root,70));
  return 0;
}
