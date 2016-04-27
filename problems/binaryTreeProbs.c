/**
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>
int max(int a,int b){
    return (a>=b)?a:b;
}
int height(struct TreeNode *node)
{
    if(node==NULL)
        return 0;
    return 1+max(height(node->left), height(node->right));
}
bool isBalanced(struct TreeNode* root) {
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
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetricHelper(struct TreeNode *root1, struct TreeNode *root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1 && root2 && root1->val==root2->val)
        return isSymmetricHelper(root1->left, root2->right) && isSymmetricHelper(root1->right, root2->left);
    return false;
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
        return true;
    return isSymmetricHelper(root, root);
}



/**
112. Path Sum 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSumHelper(struct TreeNode *root, int sum)
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
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root==NULL)
        return false;
   int curr=0;
    return hasPathSumHelper(root, sum);
}
