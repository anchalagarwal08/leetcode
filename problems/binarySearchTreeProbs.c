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
