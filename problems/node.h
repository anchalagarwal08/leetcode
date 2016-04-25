typedef struct Node{
  Node *left;
  Node *right;
  int val;
}Node;
Node *newNode(int val);
Node *createBST();
Node *createBT();
Node *newNode(int val)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->left=NULL;
  n->right=NULL;
  n->val =val;
  return n;
}
