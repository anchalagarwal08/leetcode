/**
104. Maximum Depth of Binary Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
   if(root ==NULL)
     return 0;
   else
   {
       int left=maxDepth(root->left);
       int right=maxDepth(root->right);
       if(left>right)
          return left+1;
       else 
          return right+1;
   }
}


/**
226. Invert Binary Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL)
        return NULL;
    struct TreeNode *tmp;
    invertTree(root->left);
    invertTree(root->right);
    tmp =root->left;		/*we dont need to check left and right sub child, just swap*/
    root->left = root->right;
    root->right =tmp;
    return root;
}
